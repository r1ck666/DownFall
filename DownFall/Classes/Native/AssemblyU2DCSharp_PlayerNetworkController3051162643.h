#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// PlayerController
struct PlayerController_t4148409433;
// UnityEngine.Animator
struct Animator_t69676727;

#include "AssemblyU2DCSharp_Photon_MonoBehaviour3914164484.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"
#include "UnityEngine_UnityEngine_Quaternion4030073918.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// PlayerNetworkController
struct  PlayerNetworkController_t3051162643  : public MonoBehaviour_t3914164484
{
public:
	// UnityEngine.Vector3 PlayerNetworkController::correctPlayerPos
	Vector3_t2243707580  ___correctPlayerPos_3;
	// UnityEngine.Quaternion PlayerNetworkController::correctPlayerRot
	Quaternion_t4030073918  ___correctPlayerRot_4;
	// PlayerController PlayerNetworkController::playerController
	PlayerController_t4148409433 * ___playerController_5;
	// UnityEngine.Animator PlayerNetworkController::animator
	Animator_t69676727 * ___animator_6;
	// System.Boolean PlayerNetworkController::isMine
	bool ___isMine_7;

public:
	inline static int32_t get_offset_of_correctPlayerPos_3() { return static_cast<int32_t>(offsetof(PlayerNetworkController_t3051162643, ___correctPlayerPos_3)); }
	inline Vector3_t2243707580  get_correctPlayerPos_3() const { return ___correctPlayerPos_3; }
	inline Vector3_t2243707580 * get_address_of_correctPlayerPos_3() { return &___correctPlayerPos_3; }
	inline void set_correctPlayerPos_3(Vector3_t2243707580  value)
	{
		___correctPlayerPos_3 = value;
	}

	inline static int32_t get_offset_of_correctPlayerRot_4() { return static_cast<int32_t>(offsetof(PlayerNetworkController_t3051162643, ___correctPlayerRot_4)); }
	inline Quaternion_t4030073918  get_correctPlayerRot_4() const { return ___correctPlayerRot_4; }
	inline Quaternion_t4030073918 * get_address_of_correctPlayerRot_4() { return &___correctPlayerRot_4; }
	inline void set_correctPlayerRot_4(Quaternion_t4030073918  value)
	{
		___correctPlayerRot_4 = value;
	}

	inline static int32_t get_offset_of_playerController_5() { return static_cast<int32_t>(offsetof(PlayerNetworkController_t3051162643, ___playerController_5)); }
	inline PlayerController_t4148409433 * get_playerController_5() const { return ___playerController_5; }
	inline PlayerController_t4148409433 ** get_address_of_playerController_5() { return &___playerController_5; }
	inline void set_playerController_5(PlayerController_t4148409433 * value)
	{
		___playerController_5 = value;
		Il2CppCodeGenWriteBarrier(&___playerController_5, value);
	}

	inline static int32_t get_offset_of_animator_6() { return static_cast<int32_t>(offsetof(PlayerNetworkController_t3051162643, ___animator_6)); }
	inline Animator_t69676727 * get_animator_6() const { return ___animator_6; }
	inline Animator_t69676727 ** get_address_of_animator_6() { return &___animator_6; }
	inline void set_animator_6(Animator_t69676727 * value)
	{
		___animator_6 = value;
		Il2CppCodeGenWriteBarrier(&___animator_6, value);
	}

	inline static int32_t get_offset_of_isMine_7() { return static_cast<int32_t>(offsetof(PlayerNetworkController_t3051162643, ___isMine_7)); }
	inline bool get_isMine_7() const { return ___isMine_7; }
	inline bool* get_address_of_isMine_7() { return &___isMine_7; }
	inline void set_isMine_7(bool value)
	{
		___isMine_7 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
