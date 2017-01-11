#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// UnityEngine.Animator
struct Animator_t69676727;
// System.String
struct String_t;
// UnityEngine.RuntimeAnimatorController
struct RuntimeAnimatorController_t670468573;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String2029220233.h"
#include "UnityEngine_UnityEngine_AvatarIKGoal3089653344.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"
#include "UnityEngine_UnityEngine_Animator69676727.h"
#include "UnityEngine_UnityEngine_Quaternion4030073918.h"

// System.Single UnityEngine.Animator::GetFloat(System.String)
extern "C"  float Animator_GetFloat_m3697451862 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetFloat(System.String,System.Single)
extern "C"  void Animator_SetFloat_m956158019 (Animator_t69676727 * __this, String_t* ___name0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Animator::GetBool(System.String)
extern "C"  bool Animator_GetBool_m998609148 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetBool(System.String,System.Boolean)
extern "C"  void Animator_SetBool_m2305662531 (Animator_t69676727 * __this, String_t* ___name0, bool ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Animator::GetInteger(System.String)
extern "C"  int32_t Animator_GetInteger_m1118677844 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetInteger(System.String,System.Int32)
extern "C"  void Animator_SetInteger_m528582597 (Animator_t69676727 * __this, String_t* ___name0, int32_t ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetTrigger(System.String)
extern "C"  void Animator_SetTrigger_m3418492570 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::ResetTrigger(System.String)
extern "C"  void Animator_ResetTrigger_m865269317 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Animator::get_applyRootMotion()
extern "C"  bool Animator_get_applyRootMotion_m915232763 (Animator_t69676727 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::set_applyRootMotion(System.Boolean)
extern "C"  void Animator_set_applyRootMotion_m635228566 (Animator_t69676727 * __this, bool ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKPosition(UnityEngine.AvatarIKGoal,UnityEngine.Vector3)
extern "C"  void Animator_SetIKPosition_m3754744543 (Animator_t69676727 * __this, int32_t ___goal0, Vector3_t2243707580  ___goalPosition1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKPositionInternal(UnityEngine.AvatarIKGoal,UnityEngine.Vector3)
extern "C"  void Animator_SetIKPositionInternal_m627652436 (Animator_t69676727 * __this, int32_t ___goal0, Vector3_t2243707580  ___goalPosition1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::INTERNAL_CALL_SetIKPositionInternal(UnityEngine.Animator,UnityEngine.AvatarIKGoal,UnityEngine.Vector3&)
extern "C"  void Animator_INTERNAL_CALL_SetIKPositionInternal_m2542413499 (Il2CppObject * __this /* static, unused */, Animator_t69676727 * ___self0, int32_t ___goal1, Vector3_t2243707580 * ___goalPosition2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKRotation(UnityEngine.AvatarIKGoal,UnityEngine.Quaternion)
extern "C"  void Animator_SetIKRotation_m4119847878 (Animator_t69676727 * __this, int32_t ___goal0, Quaternion_t4030073918  ___goalRotation1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKRotationInternal(UnityEngine.AvatarIKGoal,UnityEngine.Quaternion)
extern "C"  void Animator_SetIKRotationInternal_m2182387227 (Animator_t69676727 * __this, int32_t ___goal0, Quaternion_t4030073918  ___goalRotation1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::INTERNAL_CALL_SetIKRotationInternal(UnityEngine.Animator,UnityEngine.AvatarIKGoal,UnityEngine.Quaternion&)
extern "C"  void Animator_INTERNAL_CALL_SetIKRotationInternal_m4087004338 (Il2CppObject * __this /* static, unused */, Animator_t69676727 * ___self0, int32_t ___goal1, Quaternion_t4030073918 * ___goalRotation2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKPositionWeight(UnityEngine.AvatarIKGoal,System.Single)
extern "C"  void Animator_SetIKPositionWeight_m2782442723 (Animator_t69676727 * __this, int32_t ___goal0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKPositionWeightInternal(UnityEngine.AvatarIKGoal,System.Single)
extern "C"  void Animator_SetIKPositionWeightInternal_m3301773304 (Animator_t69676727 * __this, int32_t ___goal0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKRotationWeight(UnityEngine.AvatarIKGoal,System.Single)
extern "C"  void Animator_SetIKRotationWeight_m3417634268 (Animator_t69676727 * __this, int32_t ___goal0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIKRotationWeightInternal(UnityEngine.AvatarIKGoal,System.Single)
extern "C"  void Animator_SetIKRotationWeightInternal_m3149308873 (Animator_t69676727 * __this, int32_t ___goal0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.Animator::GetLayerWeight(System.Int32)
extern "C"  float Animator_GetLayerWeight_m2228986294 (Animator_t69676727 * __this, int32_t ___layerIndex0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)
extern "C"  void Animator_SetLayerWeight_m2914961795 (Animator_t69676727 * __this, int32_t ___layerIndex0, float ___weight1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.RuntimeAnimatorController UnityEngine.Animator::get_runtimeAnimatorController()
extern "C"  RuntimeAnimatorController_t670468573 * Animator_get_runtimeAnimatorController_m652575931 (Animator_t69676727 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Animator::StringToHash(System.String)
extern "C"  int32_t Animator_StringToHash_m3313850714 (Il2CppObject * __this /* static, unused */, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::CheckIfInIKPass()
extern "C"  void Animator_CheckIfInIKPass_m4048236447 (Animator_t69676727 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Animator::CheckIfInIKPassInternal()
extern "C"  bool Animator_CheckIfInIKPassInternal_m1624362606 (Animator_t69676727 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetFloatString(System.String,System.Single)
extern "C"  void Animator_SetFloatString_m3960043456 (Animator_t69676727 * __this, String_t* ___name0, float ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Single UnityEngine.Animator::GetFloatString(System.String)
extern "C"  float Animator_GetFloatString_m4224954149 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetBoolString(System.String,System.Boolean)
extern "C"  void Animator_SetBoolString_m1893192746 (Animator_t69676727 * __this, String_t* ___name0, bool ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Animator::GetBoolString(System.String)
extern "C"  bool Animator_GetBoolString_m307776885 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetIntegerString(System.String,System.Int32)
extern "C"  void Animator_SetIntegerString_m3104058366 (Animator_t69676727 * __this, String_t* ___name0, int32_t ___value1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Int32 UnityEngine.Animator::GetIntegerString(System.String)
extern "C"  int32_t Animator_GetIntegerString_m1029923547 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::SetTriggerString(System.String)
extern "C"  void Animator_SetTriggerString_m2002790359 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.Animator::ResetTriggerString(System.String)
extern "C"  void Animator_ResetTriggerString_m1445965342 (Animator_t69676727 * __this, String_t* ___name0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.Animator::get_logWarnings()
extern "C"  bool Animator_get_logWarnings_m485644130 (Animator_t69676727 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
