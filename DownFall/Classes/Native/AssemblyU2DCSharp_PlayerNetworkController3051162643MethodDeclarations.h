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

// PlayerNetworkController
struct PlayerNetworkController_t3051162643;
// PhotonStream
struct PhotonStream_t2436786422;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_PhotonStream2436786422.h"
#include "AssemblyU2DCSharp_PhotonMessageInfo13590565.h"

// System.Void PlayerNetworkController::.ctor()
extern "C"  void PlayerNetworkController__ctor_m2074472268 (PlayerNetworkController_t3051162643 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerNetworkController::Awake()
extern "C"  void PlayerNetworkController_Awake_m2142625539 (PlayerNetworkController_t3051162643 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerNetworkController::Update()
extern "C"  void PlayerNetworkController_Update_m4284357183 (PlayerNetworkController_t3051162643 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerNetworkController::OnPhotonSerializeView(PhotonStream,PhotonMessageInfo)
extern "C"  void PlayerNetworkController_OnPhotonSerializeView_m2556843759 (PlayerNetworkController_t3051162643 * __this, PhotonStream_t2436786422 * ___stream0, PhotonMessageInfo_t13590565  ___info1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void PlayerNetworkController::SetMine(System.Boolean)
extern "C"  void PlayerNetworkController_SetMine_m1326700034 (PlayerNetworkController_t3051162643 * __this, bool ___isMe0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
