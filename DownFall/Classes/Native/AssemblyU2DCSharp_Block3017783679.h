#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>


#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "AssemblyU2DCSharp_BlockState3403791646.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Block
struct  Block_t3017783679  : public MonoBehaviour_t1158329972
{
public:
	// System.Int32 Block::durability
	int32_t ___durability_2;
	// BlockState Block::state
	int32_t ___state_3;

public:
	inline static int32_t get_offset_of_durability_2() { return static_cast<int32_t>(offsetof(Block_t3017783679, ___durability_2)); }
	inline int32_t get_durability_2() const { return ___durability_2; }
	inline int32_t* get_address_of_durability_2() { return &___durability_2; }
	inline void set_durability_2(int32_t value)
	{
		___durability_2 = value;
	}

	inline static int32_t get_offset_of_state_3() { return static_cast<int32_t>(offsetof(Block_t3017783679, ___state_3)); }
	inline int32_t get_state_3() const { return ___state_3; }
	inline int32_t* get_address_of_state_3() { return &___state_3; }
	inline void set_state_3(int32_t value)
	{
		___state_3 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
