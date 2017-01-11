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

// NormalGameManager
struct NormalGameManager_t1176754080;
// Stage
struct Stage_t1821503306;
// System.UInt32[0...,0...,0...]
struct UInt32U5BU2CU2CU5D_t59386218;
// Block[0...,0...,0...]
struct BlockU5BU2CU2CU5D_t2110524840;
// PhotonPlayer
struct PhotonPlayer_t4120608827;
// System.Boolean[0...,0...]
struct BooleanU5B0___U2C0___U5D_t3568034316;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t1440998580;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_PhotonPlayer4120608827.h"
#include "AssemblyU2DCSharp_BlockState3403791646.h"

// System.Void NormalGameManager::.ctor()
extern "C"  void NormalGameManager__ctor_m1051487345 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Stage NormalGameManager::get_Stage()
extern "C"  Stage_t1821503306 * NormalGameManager_get_Stage_m1698444511 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.UInt32[0...,0...,0...] NormalGameManager::get_Blocks()
extern "C"  UInt32U5BU2CU2CU5D_t59386218* NormalGameManager_get_Blocks_m374068233 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Block[0...,0...,0...] NormalGameManager::get_BlocksObject()
extern "C"  BlockU5BU2CU2CU5D_t2110524840* NormalGameManager_get_BlocksObject_m3309114453 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::Awake()
extern "C"  void NormalGameManager_Awake_m143530576 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::Start()
extern "C"  void NormalGameManager_Start_m545743377 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::OnLeftRoom()
extern "C"  void NormalGameManager_OnLeftRoom_m1473885804 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::LeaveRoom()
extern "C"  void NormalGameManager_LeaveRoom_m3543965605 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::OnPhotonPlayerConnected(PhotonPlayer)
extern "C"  void NormalGameManager_OnPhotonPlayerConnected_m2618783811 (NormalGameManager_t1176754080 * __this, PhotonPlayer_t4120608827 * ___other0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::OnPhotonPlayerDisconnected(PhotonPlayer)
extern "C"  void NormalGameManager_OnPhotonPlayerDisconnected_m672186733 (NormalGameManager_t1176754080 * __this, PhotonPlayer_t4120608827 * ___other0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::InitializePlayer()
extern "C"  void NormalGameManager_InitializePlayer_m668064908 (NormalGameManager_t1176754080 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean NormalGameManager::ActionJudge(System.Int32,System.Int32)
extern "C"  bool NormalGameManager_ActionJudge_m2166272004 (NormalGameManager_t1176754080 * __this, int32_t ___x0, int32_t ___z1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::ChangeBlock(System.Int32,System.Int32,System.Int32,BlockState)
extern "C"  void NormalGameManager_ChangeBlock_m280438549 (NormalGameManager_t1176754080 * __this, int32_t ___x0, int32_t ___y1, int32_t ___z2, int32_t ___state3, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::UpdateStage(System.Int32,System.Int32,System.Int32)
extern "C"  void NormalGameManager_UpdateStage_m2823381077 (NormalGameManager_t1176754080 * __this, int32_t ___x0, int32_t ___y1, int32_t ___z2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void NormalGameManager::DownFall(System.Int32,System.Int32)
extern "C"  void NormalGameManager_DownFall_m2588635318 (NormalGameManager_t1176754080 * __this, int32_t ___x0, int32_t ___z1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean NormalGameManager::RecursiveJudge(System.Int32,System.Int32,System.Boolean[0...,0...]&,System.Collections.Generic.List`1<System.Int32>&,System.Collections.Generic.List`1<System.Int32>&)
extern "C"  bool NormalGameManager_RecursiveJudge_m2106920413 (NormalGameManager_t1176754080 * __this, int32_t ___x0, int32_t ___z1, BooleanU5B0___U2C0___U5D_t3568034316** ___done2, List_1_t1440998580 ** ___fallX3, List_1_t1440998580 ** ___fallZ4, const MethodInfo* method) IL2CPP_METHOD_ATTR;
