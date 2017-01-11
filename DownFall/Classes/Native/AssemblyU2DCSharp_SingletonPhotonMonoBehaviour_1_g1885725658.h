#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// TitleManager
struct TitleManager_t989436509;

#include "AssemblyU2DCSharp_Photon_PunBehaviour692890556.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SingletonPhotonMonoBehaviour`1<TitleManager>
struct  SingletonPhotonMonoBehaviour_1_t1885725658  : public PunBehaviour_t692890556
{
public:

public:
};

struct SingletonPhotonMonoBehaviour_1_t1885725658_StaticFields
{
public:
	// T SingletonPhotonMonoBehaviour`1::instance
	TitleManager_t989436509 * ___instance_3;

public:
	inline static int32_t get_offset_of_instance_3() { return static_cast<int32_t>(offsetof(SingletonPhotonMonoBehaviour_1_t1885725658_StaticFields, ___instance_3)); }
	inline TitleManager_t989436509 * get_instance_3() const { return ___instance_3; }
	inline TitleManager_t989436509 ** get_address_of_instance_3() { return &___instance_3; }
	inline void set_instance_3(TitleManager_t989436509 * value)
	{
		___instance_3 = value;
		Il2CppCodeGenWriteBarrier(&___instance_3, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
