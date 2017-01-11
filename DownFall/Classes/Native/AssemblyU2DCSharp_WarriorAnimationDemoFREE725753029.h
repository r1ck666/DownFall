#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Animator
struct Animator_t69676727;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"
#include "AssemblyU2DCSharp_WarriorAnimationDemoFREE_Warrior1732622984.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// WarriorAnimationDemoFREE
struct  WarriorAnimationDemoFREE_t725753029  : public MonoBehaviour_t1158329972
{
public:
	// UnityEngine.Animator WarriorAnimationDemoFREE::animator
	Animator_t69676727 * ___animator_2;
	// System.Single WarriorAnimationDemoFREE::rotationSpeed
	float ___rotationSpeed_3;
	// UnityEngine.Vector3 WarriorAnimationDemoFREE::inputVec
	Vector3_t2243707580  ___inputVec_4;
	// UnityEngine.Vector3 WarriorAnimationDemoFREE::targetDirection
	Vector3_t2243707580  ___targetDirection_5;
	// WarriorAnimationDemoFREE/Warrior WarriorAnimationDemoFREE::warrior
	int32_t ___warrior_6;

public:
	inline static int32_t get_offset_of_animator_2() { return static_cast<int32_t>(offsetof(WarriorAnimationDemoFREE_t725753029, ___animator_2)); }
	inline Animator_t69676727 * get_animator_2() const { return ___animator_2; }
	inline Animator_t69676727 ** get_address_of_animator_2() { return &___animator_2; }
	inline void set_animator_2(Animator_t69676727 * value)
	{
		___animator_2 = value;
		Il2CppCodeGenWriteBarrier(&___animator_2, value);
	}

	inline static int32_t get_offset_of_rotationSpeed_3() { return static_cast<int32_t>(offsetof(WarriorAnimationDemoFREE_t725753029, ___rotationSpeed_3)); }
	inline float get_rotationSpeed_3() const { return ___rotationSpeed_3; }
	inline float* get_address_of_rotationSpeed_3() { return &___rotationSpeed_3; }
	inline void set_rotationSpeed_3(float value)
	{
		___rotationSpeed_3 = value;
	}

	inline static int32_t get_offset_of_inputVec_4() { return static_cast<int32_t>(offsetof(WarriorAnimationDemoFREE_t725753029, ___inputVec_4)); }
	inline Vector3_t2243707580  get_inputVec_4() const { return ___inputVec_4; }
	inline Vector3_t2243707580 * get_address_of_inputVec_4() { return &___inputVec_4; }
	inline void set_inputVec_4(Vector3_t2243707580  value)
	{
		___inputVec_4 = value;
	}

	inline static int32_t get_offset_of_targetDirection_5() { return static_cast<int32_t>(offsetof(WarriorAnimationDemoFREE_t725753029, ___targetDirection_5)); }
	inline Vector3_t2243707580  get_targetDirection_5() const { return ___targetDirection_5; }
	inline Vector3_t2243707580 * get_address_of_targetDirection_5() { return &___targetDirection_5; }
	inline void set_targetDirection_5(Vector3_t2243707580  value)
	{
		___targetDirection_5 = value;
	}

	inline static int32_t get_offset_of_warrior_6() { return static_cast<int32_t>(offsetof(WarriorAnimationDemoFREE_t725753029, ___warrior_6)); }
	inline int32_t get_warrior_6() const { return ___warrior_6; }
	inline int32_t* get_address_of_warrior_6() { return &___warrior_6; }
	inline void set_warrior_6(int32_t value)
	{
		___warrior_6 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
