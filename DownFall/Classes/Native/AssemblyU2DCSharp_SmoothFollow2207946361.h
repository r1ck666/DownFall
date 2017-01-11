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
// UnityEngine.GameObject
struct GameObject_t1756533147;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SmoothFollow
struct  SmoothFollow_t2207946361  : public MonoBehaviour_t1158329972
{
public:
	// System.Boolean SmoothFollow::LockX
	bool ___LockX_3;
	// System.Single SmoothFollow::offSetZ
	float ___offSetZ_4;
	// System.Boolean SmoothFollow::LockY
	bool ___LockY_5;
	// System.Boolean SmoothFollow::LockZ
	bool ___LockZ_6;
	// System.Boolean SmoothFollow::useSmoothing
	bool ___useSmoothing_7;
	// UnityEngine.Transform SmoothFollow::target
	Transform_t3275118058 * ___target_8;
	// UnityEngine.GameObject SmoothFollow::hudElements
	GameObject_t1756533147 * ___hudElements_9;
	// UnityEngine.Transform SmoothFollow::thisTransform
	Transform_t3275118058 * ___thisTransform_10;
	// UnityEngine.Vector3 SmoothFollow::velocity
	Vector3_t2243707580  ___velocity_11;
	// System.Boolean SmoothFollow::hudActive
	bool ___hudActive_12;

public:
	inline static int32_t get_offset_of_LockX_3() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___LockX_3)); }
	inline bool get_LockX_3() const { return ___LockX_3; }
	inline bool* get_address_of_LockX_3() { return &___LockX_3; }
	inline void set_LockX_3(bool value)
	{
		___LockX_3 = value;
	}

	inline static int32_t get_offset_of_offSetZ_4() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___offSetZ_4)); }
	inline float get_offSetZ_4() const { return ___offSetZ_4; }
	inline float* get_address_of_offSetZ_4() { return &___offSetZ_4; }
	inline void set_offSetZ_4(float value)
	{
		___offSetZ_4 = value;
	}

	inline static int32_t get_offset_of_LockY_5() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___LockY_5)); }
	inline bool get_LockY_5() const { return ___LockY_5; }
	inline bool* get_address_of_LockY_5() { return &___LockY_5; }
	inline void set_LockY_5(bool value)
	{
		___LockY_5 = value;
	}

	inline static int32_t get_offset_of_LockZ_6() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___LockZ_6)); }
	inline bool get_LockZ_6() const { return ___LockZ_6; }
	inline bool* get_address_of_LockZ_6() { return &___LockZ_6; }
	inline void set_LockZ_6(bool value)
	{
		___LockZ_6 = value;
	}

	inline static int32_t get_offset_of_useSmoothing_7() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___useSmoothing_7)); }
	inline bool get_useSmoothing_7() const { return ___useSmoothing_7; }
	inline bool* get_address_of_useSmoothing_7() { return &___useSmoothing_7; }
	inline void set_useSmoothing_7(bool value)
	{
		___useSmoothing_7 = value;
	}

	inline static int32_t get_offset_of_target_8() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___target_8)); }
	inline Transform_t3275118058 * get_target_8() const { return ___target_8; }
	inline Transform_t3275118058 ** get_address_of_target_8() { return &___target_8; }
	inline void set_target_8(Transform_t3275118058 * value)
	{
		___target_8 = value;
		Il2CppCodeGenWriteBarrier(&___target_8, value);
	}

	inline static int32_t get_offset_of_hudElements_9() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___hudElements_9)); }
	inline GameObject_t1756533147 * get_hudElements_9() const { return ___hudElements_9; }
	inline GameObject_t1756533147 ** get_address_of_hudElements_9() { return &___hudElements_9; }
	inline void set_hudElements_9(GameObject_t1756533147 * value)
	{
		___hudElements_9 = value;
		Il2CppCodeGenWriteBarrier(&___hudElements_9, value);
	}

	inline static int32_t get_offset_of_thisTransform_10() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___thisTransform_10)); }
	inline Transform_t3275118058 * get_thisTransform_10() const { return ___thisTransform_10; }
	inline Transform_t3275118058 ** get_address_of_thisTransform_10() { return &___thisTransform_10; }
	inline void set_thisTransform_10(Transform_t3275118058 * value)
	{
		___thisTransform_10 = value;
		Il2CppCodeGenWriteBarrier(&___thisTransform_10, value);
	}

	inline static int32_t get_offset_of_velocity_11() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___velocity_11)); }
	inline Vector3_t2243707580  get_velocity_11() const { return ___velocity_11; }
	inline Vector3_t2243707580 * get_address_of_velocity_11() { return &___velocity_11; }
	inline void set_velocity_11(Vector3_t2243707580  value)
	{
		___velocity_11 = value;
	}

	inline static int32_t get_offset_of_hudActive_12() { return static_cast<int32_t>(offsetof(SmoothFollow_t2207946361, ___hudActive_12)); }
	inline bool get_hudActive_12() const { return ___hudActive_12; }
	inline bool* get_address_of_hudActive_12() { return &___hudActive_12; }
	inline void set_hudActive_12(bool value)
	{
		___hudActive_12 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
