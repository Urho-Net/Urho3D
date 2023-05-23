//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "../Core/Context.h"
#include "../Physics/PhysicsWorld.h"
#include "../Physics/PhysicsEvents.h"
#include "../Physics/CollisionShape.h"
#include "../Physics/PhysicsUtils.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneEvents.h"
#include "../IO/Log.h"

#include <Bullet/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btConvexShape.h>
#include <Bullet/BulletDynamics/Character/btKinematicCharacterController.h>
#include <cassert>

#include "KinematicCharacterController.h"

namespace Urho3D
{
//=============================================================================
// NOTE! declare these function before #include <Urho3D/DebugNew>
// otherwise you'll get a compile error for _DEBUG build
//=============================================================================
btPairCachingGhostObject* newPairCachingGhostObj() { return new btPairCachingGhostObject(); }

btKinematicCharacterController* newKinematicCharCtrl(btPairCachingGhostObject* ghostCGO, btConvexShape* shape,
                                                     float stepHeight, const btVector3& upVec)
{
    return new btKinematicCharacterController(ghostCGO, shape, stepHeight, upVec);
}

//=============================================================================
//=============================================================================
const float STEP_HEIGHT = 0.4f;
const float JUMP_HEIGHT = 2.0f;
const float FALL_SPEED = 55.0f;
const float JUMP_SPEED = 9.0f;
const float MAX_SLOPE = 45.0f;
const float DEFAULT_DAMPING = 0.2f;
const Vector3 KINEMATIC_GRAVITY(0.0f, -14.0f, 0.0f);

extern const char* PHYSICS_CATEGORY;
//=============================================================================
//=============================================================================
KinematicCharacterController::KinematicCharacterController(Context* context)
    : Component(context)
    , colLayer_(1)
    , colMask_(0xffff)
    , gravity_(KINEMATIC_GRAVITY)
    , stepHeight_(STEP_HEIGHT)
    , maxJumpHeight_(JUMP_HEIGHT)
    , fallSpeed_(FALL_SPEED)
    , jumpSpeed_(JUMP_SPEED)
    , maxSlope_(MAX_SLOPE)
    , linearDamping_(DEFAULT_DAMPING)
    , angularDamping_(DEFAULT_DAMPING)
    , colShapeOffset_(Vector3::ZERO)
    , reapplyAttributes_(false)
{
    kinematicController_.Reset(nullptr);
    physicsWorld_.Reset(nullptr);
    pairCachingGhostObject_.Reset(newPairCachingGhostObj());
    pairCachingGhostObject_->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);
}

KinematicCharacterController::~KinematicCharacterController() { ReleaseKinematic(); }

void KinematicCharacterController::RegisterObject(Context* context)
{
    context->RegisterFactory<KinematicCharacterController>(PHYSICS_CATEGORY);

    URHO3D_ATTRIBUTE("Gravity", Vector3, gravity_, KINEMATIC_GRAVITY, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Collision Layer", int, colLayer_, 1, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Collision Mask", int, colMask_, 0xffff, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Linear Damping", float, linearDamping_, DEFAULT_DAMPING, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Angular Damping", float, angularDamping_, DEFAULT_DAMPING, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Step Height", float, stepHeight_, STEP_HEIGHT, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Max Jump Height", float, maxJumpHeight_, JUMP_HEIGHT, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Fall Speed", float, fallSpeed_, FALL_SPEED, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Jump Speed", float, jumpSpeed_, JUMP_SPEED, AM_DEFAULT);
    URHO3D_ATTRIBUTE("Max Slope", float, maxSlope_, MAX_SLOPE, AM_DEFAULT);
}

void KinematicCharacterController::OnSetAttribute(const AttributeInfo& attr, const Variant& src)
{
    Serializable::OnSetAttribute(attr, src);

    reapplyAttributes_ = true;
}

void KinematicCharacterController::ApplyAttributes()
{
    if (reapplyAttributes_)
    {
        ApplySettings(true);
        reapplyAttributes_ = false;
    }
}

void KinematicCharacterController::ReleaseKinematic()
{
    if (kinematicController_.NotNull())
    {
        RemoveKinematicFromWorld();
    }

    kinematicController_.Reset();
    pairCachingGhostObject_.Reset();
}

void KinematicCharacterController::OnNodeSet(Node* node)
{
    if (node)
        node->AddListener(this);
}

void KinematicCharacterController::OnSceneSet(Scene* scene)
{
    if (scene)
    {
        if (scene == node_)
            URHO3D_LOGWARNING(GetTypeName() + " should not be created to the root scene node");

        physicsWorld_ = scene->GetComponent<PhysicsWorld>();

        if (physicsWorld_)
        {
            AddKinematicToWorld();
            SubscribeToEvent(physicsWorld_, E_PHYSICSPOSTSTEP,
                             URHO3D_HANDLER(KinematicCharacterController, HandlePhysicsPostStep));
        }
    }
    else
    {
        RemoveKinematicFromWorld();
        if (physicsWorld_)
        {
            UnsubscribeFromEvent(physicsWorld_, E_PHYSICSPOSTSTEP);
        }
    }
}

void KinematicCharacterController::HandlePhysicsPostStep(StringHash eventType, VariantMap& eventData)
{
    if (node_ != nullptr)
        node_->SetWorldPosition(GetPosition());
}

void KinematicCharacterController::AddKinematicToWorld()
{
    if (physicsWorld_.Get() != nullptr)
    {
        if (kinematicController_.Null())
        {
            CollisionShape* colShape = GetComponent<CollisionShape>();
            if (colShape)
            {
                // assert(colShape && "missing Collision Shape");

                pairCachingGhostObject_->setCollisionShape(colShape->GetCollisionShape());
                colShapeOffset_ = colShape->GetPosition();
                Vector3 colShapeSize = colShape->GetSize();

                kinematicController_.Reset(newKinematicCharCtrl(
                    pairCachingGhostObject_.Get(), dynamic_cast<btConvexShape*>(colShape->GetCollisionShape()),
                    stepHeight_, ToBtVector3(Vector3::UP)));
                // // apply default settings
                ApplySettings();

                btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
                phyicsWorld->addCollisionObject(pairCachingGhostObject_.Get(), colLayer_, colMask_);
                phyicsWorld->addAction(kinematicController_.Get());
            }
        }
    }
}

void KinematicCharacterController::ApplySettings(bool reapply)
{
    if (kinematicController_.NotNull() && physicsWorld_.Get() != nullptr)
    {
        kinematicController_->setGravity(ToBtVector3(gravity_));
        kinematicController_->setLinearDamping(linearDamping_);
        kinematicController_->setAngularDamping(angularDamping_);
        kinematicController_->setStepHeight(stepHeight_);
        kinematicController_->setMaxJumpHeight(maxJumpHeight_);
        kinematicController_->setMaxSlope(M_DEGTORAD * maxSlope_);
        kinematicController_->setJumpSpeed(jumpSpeed_);
        kinematicController_->setFallSpeed(fallSpeed_);

        if (reapply && pairCachingGhostObject_)
        {
            btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
            phyicsWorld->removeCollisionObject(pairCachingGhostObject_.Get());
            phyicsWorld->addCollisionObject(pairCachingGhostObject_.Get(), colLayer_, colMask_);
        }

        SetTransform(node_->GetWorldPosition(), node_->GetWorldRotation());
    }
}

void KinematicCharacterController::RemoveKinematicFromWorld()
{
    if (kinematicController_ && physicsWorld_.Get() != nullptr)
    {
        btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
        phyicsWorld->removeCollisionObject(pairCachingGhostObject_.Get());
        phyicsWorld->removeAction(kinematicController_.Get());
    }
}

void KinematicCharacterController::SetCollisionLayer(unsigned int layer)
{
    if (physicsWorld_.Get() != nullptr)
    {
        if (layer != colLayer_)
        {
            colLayer_ = layer;
            btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
            phyicsWorld->removeCollisionObject(pairCachingGhostObject_.Get());
            phyicsWorld->addCollisionObject(pairCachingGhostObject_.Get(), colLayer_, colMask_);
        }
    }
}

void KinematicCharacterController::SetCollisionMask(unsigned int mask)
{
    if (physicsWorld_.Get() != nullptr)
    {
        if (mask != colMask_)
        {
            colMask_ = mask;
            btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
            phyicsWorld->removeCollisionObject(pairCachingGhostObject_.Get());
            phyicsWorld->addCollisionObject(pairCachingGhostObject_.Get(), colLayer_, colMask_);
        }
    }
}

void KinematicCharacterController::SetCollisionLayerAndMask(unsigned int layer, unsigned int mask)
{
    if (physicsWorld_.Get() != nullptr)
    {
        if (layer != colLayer_ || mask != colMask_)
        {
            colLayer_ = layer;
            colMask_ = mask;
            btDiscreteDynamicsWorld* phyicsWorld = physicsWorld_->GetWorld();
            phyicsWorld->removeCollisionObject(pairCachingGhostObject_.Get());
            phyicsWorld->addCollisionObject(pairCachingGhostObject_.Get(), colLayer_, colMask_);
        }
    }
}

Vector3 KinematicCharacterController::GetPosition() const
{
    if (pairCachingGhostObject_.NotNull())
    {
        btTransform t = pairCachingGhostObject_->getWorldTransform();
        if (node_ != nullptr)
        {
              return ((ToVector3(t.getOrigin()) - colShapeOffset_*node_->GetScale()));
        }
        else
        {
            return ToVector3(t.getOrigin()) - colShapeOffset_;
        }
       
    }
    else
        return Vector3::ZERO;
}

Quaternion KinematicCharacterController::GetRotation() const
{
    if (pairCachingGhostObject_.NotNull())
    {
        btTransform t = pairCachingGhostObject_->getWorldTransform();
        return ToQuaternion(t.getRotation());
    }
    else
        return Quaternion::IDENTITY;
}

void KinematicCharacterController::SetTransform(const Vector3& position, const Quaternion& rotation)
{
    if (pairCachingGhostObject_.NotNull())
    {
        btTransform worldTrans;
        worldTrans.setIdentity();
        worldTrans.setRotation(ToBtQuaternion(rotation));
        worldTrans.setOrigin(ToBtVector3(position));
        pairCachingGhostObject_->setWorldTransform(worldTrans);
    }
}

void KinematicCharacterController::GetTransform(Vector3& position, Quaternion& rotation) const
{
    if (pairCachingGhostObject_.NotNull())
    {
        btTransform worldTrans = pairCachingGhostObject_->getWorldTransform();
        rotation = ToQuaternion(worldTrans.getRotation());
        position = ToVector3(worldTrans.getOrigin());
    }
    else
    {
        rotation = Quaternion::IDENTITY;
        position = Vector3::ZERO;
    }
}

void KinematicCharacterController::SetLinearDamping(float linearDamping)
{
    if (linearDamping != linearDamping_ && kinematicController_.NotNull())
    {
        linearDamping_ = linearDamping;
        kinematicController_->setLinearDamping(linearDamping_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetAngularDamping(float angularDamping)
{
    if (angularDamping != angularDamping_ && kinematicController_.NotNull())
    {
        angularDamping_ = angularDamping;
        kinematicController_->setAngularDamping(angularDamping_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetGravity(const Vector3& gravity)
{
    if (gravity != gravity_ && kinematicController_.NotNull())
    {
        gravity_ = gravity;
        kinematicController_->setGravity(ToBtVector3(gravity_));
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetStepHeight(float stepHeight)
{
    if (stepHeight != stepHeight_ && kinematicController_.NotNull())
    {
        stepHeight_ = stepHeight;
        kinematicController_->setStepHeight(stepHeight_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetMaxJumpHeight(float maxJumpHeight)
{
    if (maxJumpHeight != maxJumpHeight_ && kinematicController_.NotNull())
    {
        maxJumpHeight_ = maxJumpHeight;
        kinematicController_->setMaxJumpHeight(maxJumpHeight_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetFallSpeed(float fallSpeed)
{
    if (fallSpeed != fallSpeed_ && kinematicController_.NotNull())
    {
        fallSpeed_ = fallSpeed;
        kinematicController_->setFallSpeed(fallSpeed_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetJumpSpeed(float jumpSpeed)
{
    if (jumpSpeed != jumpSpeed_ && kinematicController_.NotNull())
    {
        jumpSpeed_ = jumpSpeed;
        kinematicController_->setJumpSpeed(jumpSpeed_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetMaxSlope(float maxSlope)
{
    if (maxSlope != maxSlope_ && kinematicController_.NotNull())
    {
        maxSlope_ = maxSlope;
        kinematicController_->setMaxSlope(M_DEGTORAD * maxSlope_);
        MarkNetworkUpdate();
    }
}

void KinematicCharacterController::SetWalkDirection(const Vector3& walkDir)
{
    if (kinematicController_.NotNull())
        kinematicController_->setWalkDirection(ToBtVector3(walkDir));
}

bool KinematicCharacterController::OnGround() const
{
    if (kinematicController_.NotNull())
        return kinematicController_->onGround();
    else
        return false;
}

void KinematicCharacterController::Jump(const Vector3& jump)
{
    if (kinematicController_.NotNull())
        kinematicController_->jump(ToBtVector3(jump));
}

bool KinematicCharacterController::CanJump() const
{
    if (kinematicController_.NotNull())
        return kinematicController_->canJump();
    else
        return false;
}

void KinematicCharacterController::ApplyImpulse(const Vector3& impulse)
{
    if (kinematicController_.NotNull())
        kinematicController_->applyImpulse(ToBtVector3(impulse));
}

void KinematicCharacterController::SetAngularVelocity(const Vector3& velocity)
{
    if (kinematicController_.NotNull())
        kinematicController_->setAngularVelocity(ToBtVector3(velocity));
}

const Vector3 KinematicCharacterController::GetAngularVelocity() const
{
    if (kinematicController_.NotNull())
        return ToVector3(kinematicController_->getAngularVelocity());
    else
        return Vector3::ZERO;
}

void KinematicCharacterController::SetLinearVelocity(const Vector3& velocity)
{
    if (kinematicController_.NotNull())
        kinematicController_->setLinearVelocity(ToBtVector3(velocity));
}

const Vector3 KinematicCharacterController::GetLinearVelocity() const
{
    if (kinematicController_.NotNull())
        return ToVector3(kinematicController_->getLinearVelocity());
    else
        return Vector3::ZERO;
}

void KinematicCharacterController::Warp(const Vector3& position)
{
    if (kinematicController_.NotNull())
        kinematicController_->warp(ToBtVector3(position));
}

void KinematicCharacterController::DrawDebugGeometry()
{
    if (kinematicController_.NotNull())
        kinematicController_->debugDraw(physicsWorld_);
}

} // namespace Urho3D
