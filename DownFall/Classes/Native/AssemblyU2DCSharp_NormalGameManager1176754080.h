#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// Stage
struct Stage_t1821503306;
// System.UInt32[0...,0...,0...]
struct UInt32U5BU2CU2CU5D_t59386218;
// Block[0...,0...,0...]
struct BlockU5BU2CU2CU5D_t2110524840;
// UnityEngine.Material
struct Material_t193706927;
// System.Int32[]
struct Int32U5BU5D_t3030399641;

#include "AssemblyU2DCSharp_SingletonPhotonMonoBehaviour_1_g2073043229.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// NormalGameManager
struct  NormalGameManager_t1176754080  : public SingletonPhotonMonoBehaviour_1_t2073043229
{
public:
	// System.String NormalGameManager::_gameVersion
	String_t* ____gameVersion_4;
	// UnityEngine.GameObject NormalGameManager::playerPrefab
	GameObject_t1756533147 * ___playerPrefab_5;
	// UnityEngine.GameObject NormalGameManager::mainCamera
	GameObject_t1756533147 * ___mainCamera_6;
	// UnityEngine.GameObject NormalGameManager::player
	GameObject_t1756533147 * ___player_7;
	// System.Single NormalGameManager::timeLimit
	float ___timeLimit_8;
	// System.Int32 NormalGameManager::ROCK_MAX
	int32_t ___ROCK_MAX_9;
	// System.Int32 NormalGameManager::power
	int32_t ___power_10;
	// Stage NormalGameManager::stage
	Stage_t1821503306 * ___stage_11;
	// System.UInt32[0...,0...,0...] NormalGameManager::blocks
	UInt32U5BU2CU2CU5D_t59386218* ___blocks_12;
	// Block[0...,0...,0...] NormalGameManager::blocksObject
	BlockU5BU2CU2CU5D_t2110524840* ___blocksObject_13;
	// System.Int32 NormalGameManager::DURABILITY_NONE
	int32_t ___DURABILITY_NONE_14;
	// System.Int32 NormalGameManager::DURABILITY_NORMAL
	int32_t ___DURABILITY_NORMAL_15;
	// System.Int32 NormalGameManager::DURABILITY_UNBREAK
	int32_t ___DURABILITY_UNBREAK_16;
	// System.Int32 NormalGameManager::DURABILITY_BROKEN
	int32_t ___DURABILITY_BROKEN_17;
	// UnityEngine.Material NormalGameManager::MATERIAL_NORMAL
	Material_t193706927 * ___MATERIAL_NORMAL_18;
	// UnityEngine.Material NormalGameManager::MATERIAL_UNBREAK
	Material_t193706927 * ___MATERIAL_UNBREAK_19;
	// UnityEngine.Material NormalGameManager::MATERIAL_BROKEN
	Material_t193706927 * ___MATERIAL_BROKEN_20;
	// System.Int32[] NormalGameManager::dicX
	Int32U5BU5D_t3030399641* ___dicX_21;
	// System.Int32[] NormalGameManager::dicZ
	Int32U5BU5D_t3030399641* ___dicZ_22;

public:
	inline static int32_t get_offset_of__gameVersion_4() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ____gameVersion_4)); }
	inline String_t* get__gameVersion_4() const { return ____gameVersion_4; }
	inline String_t** get_address_of__gameVersion_4() { return &____gameVersion_4; }
	inline void set__gameVersion_4(String_t* value)
	{
		____gameVersion_4 = value;
		Il2CppCodeGenWriteBarrier(&____gameVersion_4, value);
	}

	inline static int32_t get_offset_of_playerPrefab_5() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___playerPrefab_5)); }
	inline GameObject_t1756533147 * get_playerPrefab_5() const { return ___playerPrefab_5; }
	inline GameObject_t1756533147 ** get_address_of_playerPrefab_5() { return &___playerPrefab_5; }
	inline void set_playerPrefab_5(GameObject_t1756533147 * value)
	{
		___playerPrefab_5 = value;
		Il2CppCodeGenWriteBarrier(&___playerPrefab_5, value);
	}

	inline static int32_t get_offset_of_mainCamera_6() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___mainCamera_6)); }
	inline GameObject_t1756533147 * get_mainCamera_6() const { return ___mainCamera_6; }
	inline GameObject_t1756533147 ** get_address_of_mainCamera_6() { return &___mainCamera_6; }
	inline void set_mainCamera_6(GameObject_t1756533147 * value)
	{
		___mainCamera_6 = value;
		Il2CppCodeGenWriteBarrier(&___mainCamera_6, value);
	}

	inline static int32_t get_offset_of_player_7() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___player_7)); }
	inline GameObject_t1756533147 * get_player_7() const { return ___player_7; }
	inline GameObject_t1756533147 ** get_address_of_player_7() { return &___player_7; }
	inline void set_player_7(GameObject_t1756533147 * value)
	{
		___player_7 = value;
		Il2CppCodeGenWriteBarrier(&___player_7, value);
	}

	inline static int32_t get_offset_of_timeLimit_8() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___timeLimit_8)); }
	inline float get_timeLimit_8() const { return ___timeLimit_8; }
	inline float* get_address_of_timeLimit_8() { return &___timeLimit_8; }
	inline void set_timeLimit_8(float value)
	{
		___timeLimit_8 = value;
	}

	inline static int32_t get_offset_of_ROCK_MAX_9() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___ROCK_MAX_9)); }
	inline int32_t get_ROCK_MAX_9() const { return ___ROCK_MAX_9; }
	inline int32_t* get_address_of_ROCK_MAX_9() { return &___ROCK_MAX_9; }
	inline void set_ROCK_MAX_9(int32_t value)
	{
		___ROCK_MAX_9 = value;
	}

	inline static int32_t get_offset_of_power_10() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___power_10)); }
	inline int32_t get_power_10() const { return ___power_10; }
	inline int32_t* get_address_of_power_10() { return &___power_10; }
	inline void set_power_10(int32_t value)
	{
		___power_10 = value;
	}

	inline static int32_t get_offset_of_stage_11() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___stage_11)); }
	inline Stage_t1821503306 * get_stage_11() const { return ___stage_11; }
	inline Stage_t1821503306 ** get_address_of_stage_11() { return &___stage_11; }
	inline void set_stage_11(Stage_t1821503306 * value)
	{
		___stage_11 = value;
		Il2CppCodeGenWriteBarrier(&___stage_11, value);
	}

	inline static int32_t get_offset_of_blocks_12() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___blocks_12)); }
	inline UInt32U5BU2CU2CU5D_t59386218* get_blocks_12() const { return ___blocks_12; }
	inline UInt32U5BU2CU2CU5D_t59386218** get_address_of_blocks_12() { return &___blocks_12; }
	inline void set_blocks_12(UInt32U5BU2CU2CU5D_t59386218* value)
	{
		___blocks_12 = value;
		Il2CppCodeGenWriteBarrier(&___blocks_12, value);
	}

	inline static int32_t get_offset_of_blocksObject_13() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___blocksObject_13)); }
	inline BlockU5BU2CU2CU5D_t2110524840* get_blocksObject_13() const { return ___blocksObject_13; }
	inline BlockU5BU2CU2CU5D_t2110524840** get_address_of_blocksObject_13() { return &___blocksObject_13; }
	inline void set_blocksObject_13(BlockU5BU2CU2CU5D_t2110524840* value)
	{
		___blocksObject_13 = value;
		Il2CppCodeGenWriteBarrier(&___blocksObject_13, value);
	}

	inline static int32_t get_offset_of_DURABILITY_NONE_14() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___DURABILITY_NONE_14)); }
	inline int32_t get_DURABILITY_NONE_14() const { return ___DURABILITY_NONE_14; }
	inline int32_t* get_address_of_DURABILITY_NONE_14() { return &___DURABILITY_NONE_14; }
	inline void set_DURABILITY_NONE_14(int32_t value)
	{
		___DURABILITY_NONE_14 = value;
	}

	inline static int32_t get_offset_of_DURABILITY_NORMAL_15() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___DURABILITY_NORMAL_15)); }
	inline int32_t get_DURABILITY_NORMAL_15() const { return ___DURABILITY_NORMAL_15; }
	inline int32_t* get_address_of_DURABILITY_NORMAL_15() { return &___DURABILITY_NORMAL_15; }
	inline void set_DURABILITY_NORMAL_15(int32_t value)
	{
		___DURABILITY_NORMAL_15 = value;
	}

	inline static int32_t get_offset_of_DURABILITY_UNBREAK_16() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___DURABILITY_UNBREAK_16)); }
	inline int32_t get_DURABILITY_UNBREAK_16() const { return ___DURABILITY_UNBREAK_16; }
	inline int32_t* get_address_of_DURABILITY_UNBREAK_16() { return &___DURABILITY_UNBREAK_16; }
	inline void set_DURABILITY_UNBREAK_16(int32_t value)
	{
		___DURABILITY_UNBREAK_16 = value;
	}

	inline static int32_t get_offset_of_DURABILITY_BROKEN_17() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___DURABILITY_BROKEN_17)); }
	inline int32_t get_DURABILITY_BROKEN_17() const { return ___DURABILITY_BROKEN_17; }
	inline int32_t* get_address_of_DURABILITY_BROKEN_17() { return &___DURABILITY_BROKEN_17; }
	inline void set_DURABILITY_BROKEN_17(int32_t value)
	{
		___DURABILITY_BROKEN_17 = value;
	}

	inline static int32_t get_offset_of_MATERIAL_NORMAL_18() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___MATERIAL_NORMAL_18)); }
	inline Material_t193706927 * get_MATERIAL_NORMAL_18() const { return ___MATERIAL_NORMAL_18; }
	inline Material_t193706927 ** get_address_of_MATERIAL_NORMAL_18() { return &___MATERIAL_NORMAL_18; }
	inline void set_MATERIAL_NORMAL_18(Material_t193706927 * value)
	{
		___MATERIAL_NORMAL_18 = value;
		Il2CppCodeGenWriteBarrier(&___MATERIAL_NORMAL_18, value);
	}

	inline static int32_t get_offset_of_MATERIAL_UNBREAK_19() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___MATERIAL_UNBREAK_19)); }
	inline Material_t193706927 * get_MATERIAL_UNBREAK_19() const { return ___MATERIAL_UNBREAK_19; }
	inline Material_t193706927 ** get_address_of_MATERIAL_UNBREAK_19() { return &___MATERIAL_UNBREAK_19; }
	inline void set_MATERIAL_UNBREAK_19(Material_t193706927 * value)
	{
		___MATERIAL_UNBREAK_19 = value;
		Il2CppCodeGenWriteBarrier(&___MATERIAL_UNBREAK_19, value);
	}

	inline static int32_t get_offset_of_MATERIAL_BROKEN_20() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___MATERIAL_BROKEN_20)); }
	inline Material_t193706927 * get_MATERIAL_BROKEN_20() const { return ___MATERIAL_BROKEN_20; }
	inline Material_t193706927 ** get_address_of_MATERIAL_BROKEN_20() { return &___MATERIAL_BROKEN_20; }
	inline void set_MATERIAL_BROKEN_20(Material_t193706927 * value)
	{
		___MATERIAL_BROKEN_20 = value;
		Il2CppCodeGenWriteBarrier(&___MATERIAL_BROKEN_20, value);
	}

	inline static int32_t get_offset_of_dicX_21() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___dicX_21)); }
	inline Int32U5BU5D_t3030399641* get_dicX_21() const { return ___dicX_21; }
	inline Int32U5BU5D_t3030399641** get_address_of_dicX_21() { return &___dicX_21; }
	inline void set_dicX_21(Int32U5BU5D_t3030399641* value)
	{
		___dicX_21 = value;
		Il2CppCodeGenWriteBarrier(&___dicX_21, value);
	}

	inline static int32_t get_offset_of_dicZ_22() { return static_cast<int32_t>(offsetof(NormalGameManager_t1176754080, ___dicZ_22)); }
	inline Int32U5BU5D_t3030399641* get_dicZ_22() const { return ___dicZ_22; }
	inline Int32U5BU5D_t3030399641** get_address_of_dicZ_22() { return &___dicZ_22; }
	inline void set_dicZ_22(Int32U5BU5D_t3030399641* value)
	{
		___dicZ_22 = value;
		Il2CppCodeGenWriteBarrier(&___dicZ_22, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
