#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// NormalGameManager
struct NormalGameManager_t1176754080;

#include "AssemblyU2DCSharp_Photon_PunBehaviour692890556.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SingletonPhotonMonoBehaviour`1<NormalGameManager>
struct  SingletonPhotonMonoBehaviour_1_t2073043229  : public PunBehaviour_t692890556
{
public:

public:
};

struct SingletonPhotonMonoBehaviour_1_t2073043229_StaticFields
{
public:
	// T SingletonPhotonMonoBehaviour`1::instance
	NormalGameManager_t1176754080 * ___instance_3;

public:
	inline static int32_t get_offset_of_instance_3() { return static_cast<int32_t>(offsetof(SingletonPhotonMonoBehaviour_1_t2073043229_StaticFields, ___instance_3)); }
	inline NormalGameManager_t1176754080 * get_instance_3() const { return ___instance_3; }
	inline NormalGameManager_t1176754080 ** get_address_of_instance_3() { return &___instance_3; }
	inline void set_instance_3(NormalGameManager_t1176754080 * value)
	{
		___instance_3 = value;
		Il2CppCodeGenWriteBarrier(&___instance_3, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
