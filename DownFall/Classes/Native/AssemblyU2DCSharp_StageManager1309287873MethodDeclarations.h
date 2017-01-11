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

// StageManager
struct StageManager_t1309287873;
// Stage
struct Stage_t1821503306;
// Block[0...,0...,0...]
struct BlockU5BU2CU2CU5D_t2110524840;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String2029220233.h"
#include "AssemblyU2DCSharp_Stage1821503306.h"

// System.Void StageManager::.ctor()
extern "C"  void StageManager__ctor_m1110380480 (StageManager_t1309287873 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StageManager::Awake()
extern "C"  void StageManager_Awake_m1739710317 (StageManager_t1309287873 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Stage StageManager::GetStage()
extern "C"  Stage_t1821503306 * StageManager_GetStage_m357287661 (StageManager_t1309287873 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Block[0...,0...,0...] StageManager::GetBlocksObject()
extern "C"  BlockU5BU2CU2CU5D_t2110524840* StageManager_GetBlocksObject_m538738675 (StageManager_t1309287873 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.String StageManager::ResourcesLoad(System.String)
extern "C"  String_t* StageManager_ResourcesLoad_m4157764288 (StageManager_t1309287873 * __this, String_t* ___mapName0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StageManager::BlockLoad()
extern "C"  void StageManager_BlockLoad_m2412252027 (StageManager_t1309287873 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// Stage StageManager::MapLoad(System.String)
extern "C"  Stage_t1821503306 * StageManager_MapLoad_m3425370387 (StageManager_t1309287873 * __this, String_t* ___stageData0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void StageManager::MapCreate(Stage)
extern "C"  void StageManager_MapCreate_m1728795014 (StageManager_t1309287873 * __this, Stage_t1821503306 * ___stage0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean StageManager::<MapLoad>m__0(System.String)
extern "C"  bool StageManager_U3CMapLoadU3Em__0_m1195963943 (Il2CppObject * __this /* static, unused */, String_t* ___line0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
