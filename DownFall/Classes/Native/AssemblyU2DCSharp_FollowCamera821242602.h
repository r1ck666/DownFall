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

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// FollowCamera
struct  FollowCamera_t821242602  : public MonoBehaviour_t1158329972
{
public:
	// System.Single FollowCamera::distance
	float ___distance_2;
	// System.Single FollowCamera::horizontalAngle
	float ___horizontalAngle_3;
	// System.Single FollowCamera::verticalAngle
	float ___verticalAngle_4;
	// UnityEngine.Transform FollowCamera::lookTarget
	Transform_t3275118058 * ___lookTarget_5;
	// UnityEngine.Vector3 FollowCamera::offset
	Vector3_t2243707580  ___offset_6;

public:
	inline static int32_t get_offset_of_distance_2() { return static_cast<int32_t>(offsetof(FollowCamera_t821242602, ___distance_2)); }
	inline float get_distance_2() const { return ___distance_2; }
	inline float* get_address_of_distance_2() { return &___distance_2; }
	inline void set_distance_2(float value)
	{
		___distance_2 = value;
	}

	inline static int32_t get_offset_of_horizontalAngle_3() { return static_cast<int32_t>(offsetof(FollowCamera_t821242602, ___horizontalAngle_3)); }
	inline float get_horizontalAngle_3() const { return ___horizontalAngle_3; }
	inline float* get_address_of_horizontalAngle_3() { return &___horizontalAngle_3; }
	inline void set_horizontalAngle_3(float value)
	{
		___horizontalAngle_3 = value;
	}

	inline static int32_t get_offset_of_verticalAngle_4() { return static_cast<int32_t>(offsetof(FollowCamera_t821242602, ___verticalAngle_4)); }
	inline float get_verticalAngle_4() const { return ___verticalAngle_4; }
	inline float* get_address_of_verticalAngle_4() { return &___verticalAngle_4; }
	inline void set_verticalAngle_4(float value)
	{
		___verticalAngle_4 = value;
	}

	inline static int32_t get_offset_of_lookTarget_5() { return static_cast<int32_t>(offsetof(FollowCamera_t821242602, ___lookTarget_5)); }
	inline Transform_t3275118058 * get_lookTarget_5() const { return ___lookTarget_5; }
	inline Transform_t3275118058 ** get_address_of_lookTarget_5() { return &___lookTarget_5; }
	inline void set_lookTarget_5(Transform_t3275118058 * value)
	{
		___lookTarget_5 = value;
		Il2CppCodeGenWriteBarrier(&___lookTarget_5, value);
	}

	inline static int32_t get_offset_of_offset_6() { return static_cast<int32_t>(offsetof(FollowCamera_t821242602, ___offset_6)); }
	inline Vector3_t2243707580  get_offset_6() const { return ___offset_6; }
	inline Vector3_t2243707580 * get_address_of_offset_6() { return &___offset_6; }
	inline void set_offset_6(Vector3_t2243707580  value)
	{
		___offset_6 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
