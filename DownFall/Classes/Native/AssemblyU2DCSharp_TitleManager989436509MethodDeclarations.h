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

// TitleManager
struct TitleManager_t989436509;
// System.Object[]
struct ObjectU5BU5D_t3614634134;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String2029220233.h"

// System.Void TitleManager::.ctor()
extern "C"  void TitleManager__ctor_m1960605280 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::Awake()
extern "C"  void TitleManager_Awake_m1326758573 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::Start()
extern "C"  void TitleManager_Start_m3478079240 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::Update()
extern "C"  void TitleManager_Update_m3622815785 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::InitializeUI()
extern "C"  void TitleManager_InitializeUI_m2753235114 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::Connect()
extern "C"  void TitleManager_Connect_m90161230 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnConnectedToMaster()
extern "C"  void TitleManager_OnConnectedToMaster_m1644887361 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnJoinedLobby()
extern "C"  void TitleManager_OnJoinedLobby_m3742062400 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnDisconnectedFromPhoton()
extern "C"  void TitleManager_OnDisconnectedFromPhoton_m529900874 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnPhotonCreateRoomFailed(System.Object[])
extern "C"  void TitleManager_OnPhotonCreateRoomFailed_m3463007043 (TitleManager_t989436509 * __this, ObjectU5BU5D_t3614634134* ___codeAndMsg0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnJoinedRoom()
extern "C"  void TitleManager_OnJoinedRoom_m3171142809 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::OnPhotonJoinRoomFailed(System.Object[])
extern "C"  void TitleManager_OnPhotonJoinRoomFailed_m1724804681 (TitleManager_t989436509 * __this, ObjectU5BU5D_t3614634134* ___codAndMsg0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::JoinRoom(System.Int32)
extern "C"  void TitleManager_JoinRoom_m3733222576 (TitleManager_t989436509 * __this, int32_t ___n0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::UpdateRoomInfo()
extern "C"  void TitleManager_UpdateRoomInfo_m3709208808 (TitleManager_t989436509 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void TitleManager::ErrorDialog(System.String)
extern "C"  void TitleManager_ErrorDialog_m1791548748 (TitleManager_t989436509 * __this, String_t* ___mes0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
