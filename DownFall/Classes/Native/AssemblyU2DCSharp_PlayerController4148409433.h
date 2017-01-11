#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.GameObject
struct GameObject_t1756533147;
// UnityEngine.Animator
struct Animator_t69676727;
// UnityEngine.Rigidbody
struct Rigidbody_t4233889191;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "AssemblyU2DCSharp_DirectionState3793521946.h"
#include "AssemblyU2DCSharp_AnimState1507796290.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// PlayerController
struct  PlayerController_t4148409433  : public MonoBehaviour_t1158329972
{
public:
	// DirectionState PlayerController::directionState
	int32_t ___directionState_2;
	// AnimState PlayerController::animState
	int32_t ___animState_3;
	// System.Single PlayerController::needTapDistance
	float ___needTapDistance_4;
	// System.Single PlayerController::moveSpeed
	float ___moveSpeed_5;
	// UnityEngine.GameObject PlayerController::maker
	GameObject_t1756533147 * ___maker_6;
	// UnityEngine.Vector3 PlayerController::touchBeginePos
	Vector3_t2243707580  ___touchBeginePos_7;
	// UnityEngine.Vector3 PlayerController::touchDistancePos
	Vector3_t2243707580  ___touchDistancePos_8;
	// UnityEngine.Animator PlayerController::anim
	Animator_t69676727 * ___anim_9;
	// UnityEngine.Rigidbody PlayerController::rigidbody
	Rigidbody_t4233889191 * ___rigidbody_10;
	// System.Boolean PlayerController::isDirectionMode
	bool ___isDirectionMode_11;
	// System.Boolean PlayerController::isAttack
	bool ___isAttack_12;
	// System.Boolean PlayerController::isPushAttackButton
	bool ___isPushAttackButton_13;
	// System.Boolean PlayerController::isMine
	bool ___isMine_14;

public:
	inline static int32_t get_offset_of_directionState_2() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___directionState_2)); }
	inline int32_t get_directionState_2() const { return ___directionState_2; }
	inline int32_t* get_address_of_directionState_2() { return &___directionState_2; }
	inline void set_directionState_2(int32_t value)
	{
		___directionState_2 = value;
	}

	inline static int32_t get_offset_of_animState_3() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___animState_3)); }
	inline int32_t get_animState_3() const { return ___animState_3; }
	inline int32_t* get_address_of_animState_3() { return &___animState_3; }
	inline void set_animState_3(int32_t value)
	{
		___animState_3 = value;
	}

	inline static int32_t get_offset_of_needTapDistance_4() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___needTapDistance_4)); }
	inline float get_needTapDistance_4() const { return ___needTapDistance_4; }
	inline float* get_address_of_needTapDistance_4() { return &___needTapDistance_4; }
	inline void set_needTapDistance_4(float value)
	{
		___needTapDistance_4 = value;
	}

	inline static int32_t get_offset_of_moveSpeed_5() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___moveSpeed_5)); }
	inline float get_moveSpeed_5() const { return ___moveSpeed_5; }
	inline float* get_address_of_moveSpeed_5() { return &___moveSpeed_5; }
	inline void set_moveSpeed_5(float value)
	{
		___moveSpeed_5 = value;
	}

	inline static int32_t get_offset_of_maker_6() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___maker_6)); }
	inline GameObject_t1756533147 * get_maker_6() const { return ___maker_6; }
	inline GameObject_t1756533147 ** get_address_of_maker_6() { return &___maker_6; }
	inline void set_maker_6(GameObject_t1756533147 * value)
	{
		___maker_6 = value;
		Il2CppCodeGenWriteBarrier(&___maker_6, value);
	}

	inline static int32_t get_offset_of_touchBeginePos_7() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___touchBeginePos_7)); }
	inline Vector3_t2243707580  get_touchBeginePos_7() const { return ___touchBeginePos_7; }
	inline Vector3_t2243707580 * get_address_of_touchBeginePos_7() { return &___touchBeginePos_7; }
	inline void set_touchBeginePos_7(Vector3_t2243707580  value)
	{
		___touchBeginePos_7 = value;
	}

	inline static int32_t get_offset_of_touchDistancePos_8() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___touchDistancePos_8)); }
	inline Vector3_t2243707580  get_touchDistancePos_8() const { return ___touchDistancePos_8; }
	inline Vector3_t2243707580 * get_address_of_touchDistancePos_8() { return &___touchDistancePos_8; }
	inline void set_touchDistancePos_8(Vector3_t2243707580  value)
	{
		___touchDistancePos_8 = value;
	}

	inline static int32_t get_offset_of_anim_9() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___anim_9)); }
	inline Animator_t69676727 * get_anim_9() const { return ___anim_9; }
	inline Animator_t69676727 ** get_address_of_anim_9() { return &___anim_9; }
	inline void set_anim_9(Animator_t69676727 * value)
	{
		___anim_9 = value;
		Il2CppCodeGenWriteBarrier(&___anim_9, value);
	}

	inline static int32_t get_offset_of_rigidbody_10() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___rigidbody_10)); }
	inline Rigidbody_t4233889191 * get_rigidbody_10() const { return ___rigidbody_10; }
	inline Rigidbody_t4233889191 ** get_address_of_rigidbody_10() { return &___rigidbody_10; }
	inline void set_rigidbody_10(Rigidbody_t4233889191 * value)
	{
		___rigidbody_10 = value;
		Il2CppCodeGenWriteBarrier(&___rigidbody_10, value);
	}

	inline static int32_t get_offset_of_isDirectionMode_11() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___isDirectionMode_11)); }
	inline bool get_isDirectionMode_11() const { return ___isDirectionMode_11; }
	inline bool* get_address_of_isDirectionMode_11() { return &___isDirectionMode_11; }
	inline void set_isDirectionMode_11(bool value)
	{
		___isDirectionMode_11 = value;
	}

	inline static int32_t get_offset_of_isAttack_12() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___isAttack_12)); }
	inline bool get_isAttack_12() const { return ___isAttack_12; }
	inline bool* get_address_of_isAttack_12() { return &___isAttack_12; }
	inline void set_isAttack_12(bool value)
	{
		___isAttack_12 = value;
	}

	inline static int32_t get_offset_of_isPushAttackButton_13() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___isPushAttackButton_13)); }
	inline bool get_isPushAttackButton_13() const { return ___isPushAttackButton_13; }
	inline bool* get_address_of_isPushAttackButton_13() { return &___isPushAttackButton_13; }
	inline void set_isPushAttackButton_13(bool value)
	{
		___isPushAttackButton_13 = value;
	}

	inline static int32_t get_offset_of_isMine_14() { return static_cast<int32_t>(offsetof(PlayerController_t4148409433, ___isMine_14)); }
	inline bool get_isMine_14() const { return ___isMine_14; }
	inline bool* get_address_of_isMine_14() { return &___isMine_14; }
	inline void set_isMine_14(bool value)
	{
		___isMine_14 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
