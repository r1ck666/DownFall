#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Transform
struct Transform_t3275118058;
// UnityEngine.Animator
struct Animator_t69676727;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// IKHands
struct  IKHands_t681788122  : public MonoBehaviour_t1158329972
{
public:
	// UnityEngine.Transform IKHands::leftHandObj
	Transform_t3275118058 * ___leftHandObj_2;
	// UnityEngine.Transform IKHands::rightHandObj
	Transform_t3275118058 * ___rightHandObj_3;
	// UnityEngine.Transform IKHands::attachLeft
	Transform_t3275118058 * ___attachLeft_4;
	// UnityEngine.Transform IKHands::attachRight
	Transform_t3275118058 * ___attachRight_5;
	// System.Single IKHands::leftHandPositionWeight
	float ___leftHandPositionWeight_6;
	// System.Single IKHands::leftHandRotationWeight
	float ___leftHandRotationWeight_7;
	// System.Single IKHands::rightHandPositionWeight
	float ___rightHandPositionWeight_8;
	// System.Single IKHands::rightHandRotationWeight
	float ___rightHandRotationWeight_9;
	// UnityEngine.Animator IKHands::animator
	Animator_t69676727 * ___animator_10;

public:
	inline static int32_t get_offset_of_leftHandObj_2() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___leftHandObj_2)); }
	inline Transform_t3275118058 * get_leftHandObj_2() const { return ___leftHandObj_2; }
	inline Transform_t3275118058 ** get_address_of_leftHandObj_2() { return &___leftHandObj_2; }
	inline void set_leftHandObj_2(Transform_t3275118058 * value)
	{
		___leftHandObj_2 = value;
		Il2CppCodeGenWriteBarrier(&___leftHandObj_2, value);
	}

	inline static int32_t get_offset_of_rightHandObj_3() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___rightHandObj_3)); }
	inline Transform_t3275118058 * get_rightHandObj_3() const { return ___rightHandObj_3; }
	inline Transform_t3275118058 ** get_address_of_rightHandObj_3() { return &___rightHandObj_3; }
	inline void set_rightHandObj_3(Transform_t3275118058 * value)
	{
		___rightHandObj_3 = value;
		Il2CppCodeGenWriteBarrier(&___rightHandObj_3, value);
	}

	inline static int32_t get_offset_of_attachLeft_4() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___attachLeft_4)); }
	inline Transform_t3275118058 * get_attachLeft_4() const { return ___attachLeft_4; }
	inline Transform_t3275118058 ** get_address_of_attachLeft_4() { return &___attachLeft_4; }
	inline void set_attachLeft_4(Transform_t3275118058 * value)
	{
		___attachLeft_4 = value;
		Il2CppCodeGenWriteBarrier(&___attachLeft_4, value);
	}

	inline static int32_t get_offset_of_attachRight_5() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___attachRight_5)); }
	inline Transform_t3275118058 * get_attachRight_5() const { return ___attachRight_5; }
	inline Transform_t3275118058 ** get_address_of_attachRight_5() { return &___attachRight_5; }
	inline void set_attachRight_5(Transform_t3275118058 * value)
	{
		___attachRight_5 = value;
		Il2CppCodeGenWriteBarrier(&___attachRight_5, value);
	}

	inline static int32_t get_offset_of_leftHandPositionWeight_6() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___leftHandPositionWeight_6)); }
	inline float get_leftHandPositionWeight_6() const { return ___leftHandPositionWeight_6; }
	inline float* get_address_of_leftHandPositionWeight_6() { return &___leftHandPositionWeight_6; }
	inline void set_leftHandPositionWeight_6(float value)
	{
		___leftHandPositionWeight_6 = value;
	}

	inline static int32_t get_offset_of_leftHandRotationWeight_7() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___leftHandRotationWeight_7)); }
	inline float get_leftHandRotationWeight_7() const { return ___leftHandRotationWeight_7; }
	inline float* get_address_of_leftHandRotationWeight_7() { return &___leftHandRotationWeight_7; }
	inline void set_leftHandRotationWeight_7(float value)
	{
		___leftHandRotationWeight_7 = value;
	}

	inline static int32_t get_offset_of_rightHandPositionWeight_8() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___rightHandPositionWeight_8)); }
	inline float get_rightHandPositionWeight_8() const { return ___rightHandPositionWeight_8; }
	inline float* get_address_of_rightHandPositionWeight_8() { return &___rightHandPositionWeight_8; }
	inline void set_rightHandPositionWeight_8(float value)
	{
		___rightHandPositionWeight_8 = value;
	}

	inline static int32_t get_offset_of_rightHandRotationWeight_9() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___rightHandRotationWeight_9)); }
	inline float get_rightHandRotationWeight_9() const { return ___rightHandRotationWeight_9; }
	inline float* get_address_of_rightHandRotationWeight_9() { return &___rightHandRotationWeight_9; }
	inline void set_rightHandRotationWeight_9(float value)
	{
		___rightHandRotationWeight_9 = value;
	}

	inline static int32_t get_offset_of_animator_10() { return static_cast<int32_t>(offsetof(IKHands_t681788122, ___animator_10)); }
	inline Animator_t69676727 * get_animator_10() const { return ___animator_10; }
	inline Animator_t69676727 ** get_address_of_animator_10() { return &___animator_10; }
	inline void set_animator_10(Animator_t69676727 * value)
	{
		___animator_10 = value;
		Il2CppCodeGenWriteBarrier(&___animator_10, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
