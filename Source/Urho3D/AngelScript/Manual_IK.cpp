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

#ifdef URHO3D_IK

#include "../Precompiled.h"
#include "../AngelScript/APITemplates.h"

#include "../IK/IKSolver.h"

namespace Urho3D
{

// This function is called before ASRegisterGenerated()
void ASRegisterManualFirst_IK(asIScriptEngine* engine)
{
    // enum IKSolver::Algorithm | File: ../IK/IKSolver.h
    engine->RegisterEnum("IKAlgorithm");
    engine->RegisterEnumValue("IKAlgorithm", "SOLVER_ONE_BONE", ALGORITHM_ONE_BONE);
    engine->RegisterEnumValue("IKAlgorithm", "SOLVER_TWO_BONE", ALGORITHM_TWO_BONE);
    engine->RegisterEnumValue("IKAlgorithm", "FABRIK", ALGORITHM_FABRIK);

    // enum IKSolver::Feature | File: ../IK/IKSolver.h
    engine->RegisterEnum("IKFeature");
    engine->RegisterEnumValue("IKFeature", "JOINT_ROTATIONS", FEATURE_JOINT_ROTATIONS);
    engine->RegisterEnumValue("IKFeature", "TARGET_ROTATIONS", FEATURE_TARGET_ROTATIONS);
    engine->RegisterEnumValue("IKFeature", "UPDATE_ORIGINAL_POSE", FEATURE_UPDATE_ORIGINAL_POSE);
    engine->RegisterEnumValue("IKFeature", "UPDATE_ACTIVE_POSE", FEATURE_UPDATE_ACTIVE_POSE);
    engine->RegisterEnumValue("IKFeature", "USE_ORIGINAL_POSE", FEATURE_USE_ORIGINAL_POSE);
    engine->RegisterEnumValue("IKFeature", "CONSTRAINTS", FEATURE_CONSTRAINTS);
    engine->RegisterEnumValue("IKFeature", "AUTO_SOLVE", FEATURE_AUTO_SOLVE);
}

// This function is called after ASRegisterGenerated()
void ASRegisterManualLast_IK(asIScriptEngine* engine)
{
    // Algorithm IKSolver::GetAlgorithm() const | File: ../IK/IKSolver.h
    engine->RegisterObjectMethod("IKSolver", "IKAlgorithm get_algorithm() const", asMETHOD(IKSolver, GetAlgorithm), asCALL_THISCALL);
    // void IKSolver::SetAlgorithm(Algorithm algorithm) | File: ../IK/IKSolver.h
    engine->RegisterObjectMethod("IKSolver", "void set_algorithm(IKAlgorithm)", asMETHOD(IKSolver, SetAlgorithm), asCALL_THISCALL);
}

}

#endif // def URHO3D_IK
