#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// Stage
struct Stage_t1821503306;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t1125654279;
// Block[0...,0...,0...]
struct BlockU5BU2CU2CU5D_t2110524840;
// System.Func`2<System.String,System.UInt32>
struct Func_2_t313488745;
// System.Func`2<System.String,System.Boolean>
struct Func_2_t1989381442;

#include "AssemblyU2DCSharp_SingletonMonoBehaviour_1_gen5964208.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// StageManager
struct  StageManager_t1309287873  : public SingletonMonoBehaviour_1_t5964208
{
public:
	// Stage StageManager::stage
	Stage_t1821503306 * ___stage_3;
	// UnityEngine.GameObject StageManager::stageObject
	GameObject_t1756533147 * ___stageObject_4;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> StageManager::blockList
	List_1_t1125654279 * ___blockList_5;
	// Block[0...,0...,0...] StageManager::blocksObject
	BlockU5BU2CU2CU5D_t2110524840* ___blocksObject_6;

public:
	inline static int32_t get_offset_of_stage_3() { return static_cast<int32_t>(offsetof(StageManager_t1309287873, ___stage_3)); }
	inline Stage_t1821503306 * get_stage_3() const { return ___stage_3; }
	inline Stage_t1821503306 ** get_address_of_stage_3() { return &___stage_3; }
	inline void set_stage_3(Stage_t1821503306 * value)
	{
		___stage_3 = value;
		Il2CppCodeGenWriteBarrier(&___stage_3, value);
	}

	inline static int32_t get_offset_of_stageObject_4() { return static_cast<int32_t>(offsetof(StageManager_t1309287873, ___stageObject_4)); }
	inline GameObject_t1756533147 * get_stageObject_4() const { return ___stageObject_4; }
	inline GameObject_t1756533147 ** get_address_of_stageObject_4() { return &___stageObject_4; }
	inline void set_stageObject_4(GameObject_t1756533147 * value)
	{
		___stageObject_4 = value;
		Il2CppCodeGenWriteBarrier(&___stageObject_4, value);
	}

	inline static int32_t get_offset_of_blockList_5() { return static_cast<int32_t>(offsetof(StageManager_t1309287873, ___blockList_5)); }
	inline List_1_t1125654279 * get_blockList_5() const { return ___blockList_5; }
	inline List_1_t1125654279 ** get_address_of_blockList_5() { return &___blockList_5; }
	inline void set_blockList_5(List_1_t1125654279 * value)
	{
		___blockList_5 = value;
		Il2CppCodeGenWriteBarrier(&___blockList_5, value);
	}

	inline static int32_t get_offset_of_blocksObject_6() { return static_cast<int32_t>(offsetof(StageManager_t1309287873, ___blocksObject_6)); }
	inline BlockU5BU2CU2CU5D_t2110524840* get_blocksObject_6() const { return ___blocksObject_6; }
	inline BlockU5BU2CU2CU5D_t2110524840** get_address_of_blocksObject_6() { return &___blocksObject_6; }
	inline void set_blocksObject_6(BlockU5BU2CU2CU5D_t2110524840* value)
	{
		___blocksObject_6 = value;
		Il2CppCodeGenWriteBarrier(&___blocksObject_6, value);
	}
};

struct StageManager_t1309287873_StaticFields
{
public:
	// System.Func`2<System.String,System.UInt32> StageManager::<>f__mg$cache0
	Func_2_t313488745 * ___U3CU3Ef__mgU24cache0_7;
	// System.Func`2<System.String,System.UInt32> StageManager::<>f__mg$cache1
	Func_2_t313488745 * ___U3CU3Ef__mgU24cache1_8;
	// System.Func`2<System.String,System.Boolean> StageManager::<>f__am$cache0
	Func_2_t1989381442 * ___U3CU3Ef__amU24cache0_9;

public:
	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache0_7() { return static_cast<int32_t>(offsetof(StageManager_t1309287873_StaticFields, ___U3CU3Ef__mgU24cache0_7)); }
	inline Func_2_t313488745 * get_U3CU3Ef__mgU24cache0_7() const { return ___U3CU3Ef__mgU24cache0_7; }
	inline Func_2_t313488745 ** get_address_of_U3CU3Ef__mgU24cache0_7() { return &___U3CU3Ef__mgU24cache0_7; }
	inline void set_U3CU3Ef__mgU24cache0_7(Func_2_t313488745 * value)
	{
		___U3CU3Ef__mgU24cache0_7 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache0_7, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache1_8() { return static_cast<int32_t>(offsetof(StageManager_t1309287873_StaticFields, ___U3CU3Ef__mgU24cache1_8)); }
	inline Func_2_t313488745 * get_U3CU3Ef__mgU24cache1_8() const { return ___U3CU3Ef__mgU24cache1_8; }
	inline Func_2_t313488745 ** get_address_of_U3CU3Ef__mgU24cache1_8() { return &___U3CU3Ef__mgU24cache1_8; }
	inline void set_U3CU3Ef__mgU24cache1_8(Func_2_t313488745 * value)
	{
		___U3CU3Ef__mgU24cache1_8 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache1_8, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__amU24cache0_9() { return static_cast<int32_t>(offsetof(StageManager_t1309287873_StaticFields, ___U3CU3Ef__amU24cache0_9)); }
	inline Func_2_t1989381442 * get_U3CU3Ef__amU24cache0_9() const { return ___U3CU3Ef__amU24cache0_9; }
	inline Func_2_t1989381442 ** get_address_of_U3CU3Ef__amU24cache0_9() { return &___U3CU3Ef__amU24cache0_9; }
	inline void set_U3CU3Ef__amU24cache0_9(Func_2_t1989381442 * value)
	{
		___U3CU3Ef__amU24cache0_9 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__amU24cache0_9, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
