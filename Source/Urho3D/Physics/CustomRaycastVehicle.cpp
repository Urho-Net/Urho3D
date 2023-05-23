//
// Copyright (c) 2008-2016 the Urho3D project.
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
#include "../Physics/PhysicsUtils.h"
#include "../Physics/RigidBody.h"
#include "../Physics/PhysicsWorld.h"
#include <Bullet/BulletDynamics/Vehicle/btRaycastVehicle.h>
#include <Bullet/BulletDynamics/Dynamics/btDynamicsWorld.h>
#include <Bullet/BulletCollision/CollisionShapes/btCompoundShape.h>
#include <Bullet/BulletCollision/CollisionShapes/btSphereShape.h>
#include <SDL/SDL_log.h>

#include "CustomRaycastVehicle.h"

namespace Urho3D
{
    //=============================================================================
    //=============================================================================
    CustomRaycastVehicle::CustomRaycastVehicle(Context* context)
        : RigidBody(context)
        , vehicleRaycaster_(NULL)
        , raycastVehicle_(NULL)
        , sphShape_(NULL)
        , vehicleCenterOfMass_(Vector3::ZERO)
        , indexAddedShape_(-1)
    {
    }

    CustomRaycastVehicle::~CustomRaycastVehicle()
    {
        if (sphShape_)
        {
            delete sphShape_;
            sphShape_ = NULL;
        }
        if (vehicleRaycaster_)
        {
            delete vehicleRaycaster_;
            vehicleRaycaster_ = NULL;
        }
        if (raycastVehicle_)
        {
            if (GetPhysicsWorld())
            {
                btDynamicsWorld* pbtDynWorld = (btDynamicsWorld*)GetPhysicsWorld()->GetWorld();
                pbtDynWorld->removeVehicle(raycastVehicle_);

            }
            delete raycastVehicle_;
            raycastVehicle_ = NULL;
        }
    }

    void CustomRaycastVehicle::RegisterObject(Context* context)
    {
        context->RegisterFactory<CustomRaycastVehicle>("Physics");
    }

    void CustomRaycastVehicle::AddBodyToWorld()
    {
        RigidBody::AddBodyToWorld();

        if (GetBody() && vehicleRaycaster_ == NULL)
        {
            const int rightIndex = 0;
            const int upIndex = 1;
            const int forwardIndex = 2;

            btDynamicsWorld* pbtDynWorld = (btDynamicsWorld*)GetPhysicsWorld()->GetWorld();
            vehicleRaycaster_ = new btDefaultVehicleRaycaster(pbtDynWorld);
            raycastVehicle_ = new btRaycastVehicle(vehicleTuning_, GetBody(), vehicleRaycaster_);

            pbtDynWorld->addVehicle(raycastVehicle_);
            raycastVehicle_->setCoordinateSystem(rightIndex, upIndex, forwardIndex);
        }
    }

    void CustomRaycastVehicle::SetVehicleCenterOfMass(const Vector3& centerOfMass)
    {
        if (sphShape_ == NULL)
        {
            // compound shape
            btTransform transf;
            transf.setIdentity();
            sphShape_ = new btSphereShape(0.2f);
            indexAddedShape_ = GetCompoundShape()->getNumChildShapes();

            // rigid body's center of mass = avg(sum of all compound positions) // size and mass are irrelevant
            vehicleCenterOfMass_ = centerOfMass;
            btVector3 pos = ToBtVector3(vehicleCenterOfMass_ * 2.0f);
            transf.setOrigin(pos);
            GetCompoundShape()->addChildShape(transf, sphShape_);
        }
        else
        {
            btTransform transf;
            transf.setIdentity();
            vehicleCenterOfMass_ = centerOfMass;
            btVector3 pos = ToBtVector3(vehicleCenterOfMass_ * 2.0f);
            transf.setOrigin(pos);

            GetCompoundShape()->updateChildTransform(indexAddedShape_, transf);
        }

        // updatemass to have the compound shape added to the rigid body and recalculate CoM
        UpdateMass();
    }

    const Vector3 CustomRaycastVehicle::GetVehicleCenterOfMass() const
    {
        return vehicleCenterOfMass_;
    }

    void CustomRaycastVehicle::ResetSuspension()
    {
        raycastVehicle_->resetSuspension();
    }

    float CustomRaycastVehicle::GetSteeringValue(int wheel) const
    {
        return raycastVehicle_->getSteeringValue(wheel);
    }

    void CustomRaycastVehicle::SetSteeringValue(float steering, int wheel)
    {
        raycastVehicle_->setSteeringValue(steering, wheel);
    }

    void CustomRaycastVehicle::ApplyEngineForce(float force, int wheel)
    {
        raycastVehicle_->applyEngineForce(force, wheel);
    }

    void  CustomRaycastVehicle::SetBrake(float brake, int wheel)
    {
        raycastVehicle_->setBrake(brake, wheel);
    }

    Vector3 CustomRaycastVehicle::GetWheelPositionWS(int wheel) const
    {
        const btTransform& transform = raycastVehicle_->getWheelTransformWS(wheel);
        return ToVector3(transform.getOrigin());
    }

    Vector3 CustomRaycastVehicle::GetWheelPositionLS(int wheel) const
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        return ToVector3(whInfo.m_chassisConnectionPointCS);
    }

    Quaternion CustomRaycastVehicle::GetWheelRotation(int wheel) const
    {
        const btTransform& transform = raycastVehicle_->getWheelTransformWS(wheel);
        return ToQuaternion(transform.getRotation());
    }

    const btTransform& CustomRaycastVehicle::GetWheelTransformWS(int wheel) const
    {
        return raycastVehicle_->getWheelTransformWS(wheel);
    }

    void CustomRaycastVehicle::UpdateWheelTransform(int wheel, bool interpolatedTransform)
    {
        raycastVehicle_->updateWheelTransform(wheel, interpolatedTransform);
    }

   void CustomRaycastVehicle::AddWheel(const Vector3& connectionPointCS0, const Vector3& wheelDirectionCS0, const Vector3& wheelAxleCS,
        float suspensionRestLength, float wheelRadius, bool isFrontWheel)
    {
         raycastVehicle_->addWheel(ToBtVector3(connectionPointCS0), ToBtVector3(wheelDirectionCS0), ToBtVector3(wheelAxleCS),
            suspensionRestLength, wheelRadius, vehicleTuning_, isFrontWheel);
    }

    int CustomRaycastVehicle::GetNumWheels() const
    {
        return raycastVehicle_->getNumWheels();
    }

    Vector3 CustomRaycastVehicle::GetForwardVector() const
    {
        return ToVector3(raycastVehicle_->getForwardVector());
    }

    Vector3 CustomRaycastVehicle::GetCompoundLocalExtents() const
    {
        const btVector3& minAabb = GetCompoundShape()->getLocalAabbMin();
        const btVector3& maxAabb = GetCompoundShape()->getLocalAabbMax();

        return ToVector3(btScalar(0.5) * (maxAabb - minAabb));
    }

    Vector3 CustomRaycastVehicle::GetCompooundLocalExtentsCenter() const
    {
        const btVector3& minAabb = GetCompoundShape()->getLocalAabbMin();
        const btVector3& maxAabb = GetCompoundShape()->getLocalAabbMax();

        return ToVector3(btScalar(0.5) * (maxAabb + minAabb));
    }

    Vector3 CustomRaycastVehicle::GetCompoundLocalAabbMin() const
    {
        const btVector3& minAabb = GetCompoundShape()->getLocalAabbMin();
        return ToVector3(minAabb);
    }

    Vector3 CustomRaycastVehicle::GetCompoundLocalAabbMax() const
    {
        const btVector3& maxAabb = GetCompoundShape()->getLocalAabbMax();
        return ToVector3(maxAabb);
    }

    void CustomRaycastVehicle::CompoundScaleLocalAabbMin(const Vector3& scale)
    {
        btVector3& minAabb = GetCompoundShape()->getLocalAabbMin();
        Vector3 aabb = ToVector3(minAabb);
        aabb.x_ *= scale.x_;
        aabb.y_ *= scale.y_;
        aabb.z_ *= scale.z_;
        minAabb = ToBtVector3(aabb);
    }

    void CustomRaycastVehicle::CompoundScaleLocalAabbMax(const Vector3& scale)
    {
        btVector3& maxAabb = GetCompoundShape()->getLocalAabbMax();
        Vector3 aabb = ToVector3(maxAabb);
        aabb.x_ *= scale.x_;
        aabb.y_ *= scale.y_;
        aabb.z_ *= scale.z_;
        maxAabb = ToBtVector3(aabb);
    }

    /*****************/
    /****ELI*NEW*********/
    /*****************/
    void CustomRaycastVehicle::SetWheelSuspensionStiffness(int wheel, float stiffness)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_suspensionStiffness = stiffness;
    }

    float CustomRaycastVehicle::GetWheelSuspensionStiffness(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_suspensionStiffness;
    }

    void CustomRaycastVehicle::SetWheelDampingRelaxation(int wheel, float damping)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_wheelsDampingRelaxation = damping;
    }

    float CustomRaycastVehicle::GetWheelDampingRelaxation(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_wheelsDampingRelaxation;
    }

    void CustomRaycastVehicle::SetWheelDampingCompression(int wheel, float compression)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_wheelsDampingCompression = compression;
    }

    float CustomRaycastVehicle::GetWheelDampingCompression(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_wheelsDampingCompression;
    }

    void CustomRaycastVehicle::SetWheelFrictionSlip(int wheel, float slip)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_frictionSlip = slip;
    }

    float CustomRaycastVehicle::GetWheelFrictionSlip(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_frictionSlip;
    }


    void CustomRaycastVehicle::SetWheelRollInfluence(int wheel, float rollInfluence)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_rollInfluence = rollInfluence;
    }

    float CustomRaycastVehicle::GetWheelRollInfluence(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_rollInfluence;
    }

    void CustomRaycastVehicle::SetSideFrictionStiffness(int wheel, float Stiffness)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_sideFrictionStiffness = Stiffness;
    }

    float CustomRaycastVehicle::GetSideFrictionStiffness(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_sideFrictionStiffness;
    }

    Vector3 CustomRaycastVehicle::GetChassisConnectionPointCS(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return ToVector3(whInfo.m_chassisConnectionPointCS);
    }

    bool  CustomRaycastVehicle::IsWheelInContact(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_raycastInfo.m_isInContact;
    }

    Vector3 CustomRaycastVehicle::GetContactPointWS(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return ToVector3(whInfo.m_raycastInfo.m_contactPointWS);
    }
    
    Vector3 CustomRaycastVehicle::GetContactNormalWS(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return ToVector3(whInfo.m_raycastInfo.m_contactNormalWS);
    }


    void CustomRaycastVehicle::SetSkidInfoCumulative(int wheel, float skid)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_skidInfoCumulative = skid;
    }

    float CustomRaycastVehicle::GetSkidInfoCumulative(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_skidInfoCumulative;
    }


    float CustomRaycastVehicle::GetWheelsRadius(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_wheelsRadius;
    }

   
    void CustomRaycastVehicle::SetDeltaRotation(int wheel, float deltaRotation)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_deltaRotation = deltaRotation;
    }

    float CustomRaycastVehicle::GetDeltaRotation(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_deltaRotation;
    }

    //m_rotation
    void CustomRaycastVehicle::SetRotation(int wheel, float rotation)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_rotation = rotation;
    }

    float CustomRaycastVehicle::GetRotation(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_rotation;
    }

    void CustomRaycastVehicle::SetSkidInfo(int wheel, float skid)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_skidInfo = skid;
    }

    float CustomRaycastVehicle::GetSkidInfo(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_skidInfo;
    }

    Vector3 CustomRaycastVehicle::GetWheelAxleWS(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return ToVector3(whInfo.m_raycastInfo.m_wheelAxleWS);
    }

    void CustomRaycastVehicle::SetRollInfluence(int wheel, float rollInfluence)
    {
        btWheelInfo& whInfo = raycastVehicle_->getWheelInfo(wheel);
        whInfo.m_rollInfluence = rollInfluence;
    }

    float CustomRaycastVehicle::GetRollInfluence(int wheel) const
    {
        btWheelInfo whInfo = raycastVehicle_->getWheelInfo(wheel);
        return whInfo.m_rollInfluence;
    }

}


