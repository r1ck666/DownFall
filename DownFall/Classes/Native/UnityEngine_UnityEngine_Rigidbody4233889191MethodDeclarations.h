﻿#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// UnityEngine.Rigidbody
struct Rigidbody_t4233889191;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"
#include "UnityEngine_UnityEngine_Rigidbody4233889191.h"
#include "UnityEngine_UnityEngine_ForceMode1856518252.h"
#include "UnityEngine_UnityEngine_Quaternion4030073918.h"

// UnityEngine.Vector3 UnityEngine.Rigidbody::get_velocity()
extern "C"  Vector3_t2243707580  Rigidbody_get_velocity_m2022666970 (Rigidbody_t4233889191 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::set_velocity(UnityEngine.Vector3)
extern "C"  void Rigidbody_set_velocity_m2514070071 (Rigidbody_t4233889191 * __this, Vector3_t2243707580  ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_get_velocity(UnityEngine.Vector3&)
extern "C"  void Rigidbody_INTERNAL_get_velocity_m1938461825 (Rigidbody_t4233889191 * __this, Vector3_t2243707580 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_set_velocity(UnityEngine.Vector3&)
extern "C"  void Rigidbody_INTERNAL_set_velocity_m3384354677 (Rigidbody_t4233889191 * __this, Vector3_t2243707580 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector3 UnityEngine.Rigidbody::get_angularVelocity()
extern "C"  Vector3_t2243707580  Rigidbody_get_angularVelocity_m3820121000 (Rigidbody_t4233889191 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::set_angularVelocity(UnityEngine.Vector3)
extern "C"  void Rigidbody_set_angularVelocity_m824394045 (Rigidbody_t4233889191 * __this, Vector3_t2243707580  ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_get_angularVelocity(UnityEngine.Vector3&)
extern "C"  void Rigidbody_INTERNAL_get_angularVelocity_m2914925467 (Rigidbody_t4233889191 * __this, Vector3_t2243707580 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_set_angularVelocity(UnityEngine.Vector3&)
extern "C"  void Rigidbody_INTERNAL_set_angularVelocity_m3276405927 (Rigidbody_t4233889191 * __this, Vector3_t2243707580 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::AddForce(UnityEngine.Vector3)
extern "C"  void Rigidbody_AddForce_m2836187433 (Rigidbody_t4233889191 * __this, Vector3_t2243707580  ___force0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_CALL_AddForce(UnityEngine.Rigidbody,UnityEngine.Vector3&,UnityEngine.ForceMode)
extern "C"  void Rigidbody_INTERNAL_CALL_AddForce_m3164777073 (Il2CppObject * __this /* static, unused */, Rigidbody_t4233889191 * ___self0, Vector3_t2243707580 * ___force1, int32_t ___mode2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::MovePosition(UnityEngine.Vector3)
extern "C"  void Rigidbody_MovePosition_m1810529681 (Rigidbody_t4233889191 * __this, Vector3_t2243707580  ___position0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_CALL_MovePosition(UnityEngine.Rigidbody,UnityEngine.Vector3&)
extern "C"  void Rigidbody_INTERNAL_CALL_MovePosition_m2709492198 (Il2CppObject * __this /* static, unused */, Rigidbody_t4233889191 * ___self0, Vector3_t2243707580 * ___position1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::MoveRotation(UnityEngine.Quaternion)
extern "C"  void Rigidbody_MoveRotation_m3412525692 (Rigidbody_t4233889191 * __this, Quaternion_t4030073918  ___rot0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Rigidbody::INTERNAL_CALL_MoveRotation(UnityEngine.Rigidbody,UnityEngine.Quaternion&)
extern "C"  void Rigidbody_INTERNAL_CALL_MoveRotation_m2205051919 (Il2CppObject * __this /* static, unused */, Rigidbody_t4233889191 * ___self0, Quaternion_t4030073918 * ___rot1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
