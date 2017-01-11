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

// PlayerController
struct PlayerController_t4148409433;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_AnimState1507796290.h"
#include "AssemblyU2DCSharp_DirectionState3793521946.h"

// System.Void PlayerController::.ctor()
extern "C"  void PlayerController__ctor_m3280132936 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean PlayerController::get_IsAttack()
extern "C"  bool PlayerController_get_IsAttack_m4095371711 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::set_IsAttack(System.Boolean)
extern "C"  void PlayerController_set_IsAttack_m3285189950 (PlayerController_t4148409433 * __this, bool ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean PlayerController::get_IsPushAttackButton()
extern "C"  bool PlayerController_get_IsPushAttackButton_m2297073887 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::set_IsPushAttackButton(System.Boolean)
extern "C"  void PlayerController_set_IsPushAttackButton_m2122470762 (PlayerController_t4148409433 * __this, bool ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean PlayerController::get_IsMine()
extern "C"  bool PlayerController_get_IsMine_m1951407538 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::set_IsMine(System.Boolean)
extern "C"  void PlayerController_set_IsMine_m4219802863 (PlayerController_t4148409433 * __this, bool ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::Start()
extern "C"  void PlayerController_Start_m3606284888 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::Update()
extern "C"  void PlayerController_Update_m4228472513 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::FixedUpdate()
extern "C"  void PlayerController_FixedUpdate_m1756102567 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::Maker()
extern "C"  void PlayerController_Maker_m1879415036 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::Move()
extern "C"  void PlayerController_Move_m1170937917 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::SetDirection()
extern "C"  void PlayerController_SetDirection_m191159059 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::SendFroundBlock()
extern "C"  void PlayerController_SendFroundBlock_m574933345 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::ActionAnimation(AnimState)
extern "C"  void PlayerController_ActionAnimation_m3705855972 (PlayerController_t4148409433 * __this, int32_t ___aState0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// DirectionState PlayerController::GetDirection(System.Single)
extern "C"  int32_t PlayerController_GetDirection_m2474591011 (PlayerController_t4148409433 * __this, float ___angleY0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::OnDirectionButton(System.Boolean)
extern "C"  void PlayerController_OnDirectionButton_m3052722861 (PlayerController_t4148409433 * __this, bool ___isPush0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::OnActionMotionEnter()
extern "C"  void PlayerController_OnActionMotionEnter_m1110905081 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::OnActionMotion()
extern "C"  void PlayerController_OnActionMotion_m4250028141 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::OnActionMotionExit()
extern "C"  void PlayerController_OnActionMotionExit_m3276832061 (PlayerController_t4148409433 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerController::OnActionButton(System.Boolean)
extern "C"  void PlayerController_OnActionButton_m3039050928 (PlayerController_t4148409433 * __this, bool ___isPush0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
