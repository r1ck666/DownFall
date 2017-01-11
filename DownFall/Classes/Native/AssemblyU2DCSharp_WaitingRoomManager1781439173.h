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
// UnityEngine.GameObject[]
struct GameObjectU5BU5D_t3057952154;
// UnityEngine.UI.Text[]
struct TextU5BU5D_t4216439300;
// UnityEngine.UI.Text
struct Text_t356221433;
// UnityEngine.UI.InputField
struct InputField_t1631627530;

#include "AssemblyU2DCSharp_SingletonPhotonMonoBehaviour_1_g2677728322.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// WaitingRoomManager
struct  WaitingRoomManager_t1781439173  : public SingletonPhotonMonoBehaviour_1_t2677728322
{
public:
	// UnityEngine.GameObject WaitingRoomManager::playerUI
	GameObject_t1756533147 * ___playerUI_4;
	// UnityEngine.GameObject[] WaitingRoomManager::playerObjects
	GameObjectU5BU5D_t3057952154* ___playerObjects_5;
	// UnityEngine.UI.Text[] WaitingRoomManager::player_Text
	TextU5BU5D_t4216439300* ___player_Text_6;
	// UnityEngine.UI.Text WaitingRoomManager::roomName
	Text_t356221433 * ___roomName_7;
	// UnityEngine.GameObject WaitingRoomManager::gameStartButton
	GameObject_t1756533147 * ___gameStartButton_8;
	// UnityEngine.UI.Text WaitingRoomManager::gameStartButtonText
	Text_t356221433 * ___gameStartButtonText_9;
	// UnityEngine.GameObject WaitingRoomManager::nameField
	GameObject_t1756533147 * ___nameField_10;
	// UnityEngine.UI.InputField WaitingRoomManager::inputNameField
	InputField_t1631627530 * ___inputNameField_11;
	// System.Int32 WaitingRoomManager::playerCount
	int32_t ___playerCount_12;
	// System.Int32 WaitingRoomManager::maxPlayers
	int32_t ___maxPlayers_13;
	// System.Boolean WaitingRoomManager::isOpenUI
	bool ___isOpenUI_14;

public:
	inline static int32_t get_offset_of_playerUI_4() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___playerUI_4)); }
	inline GameObject_t1756533147 * get_playerUI_4() const { return ___playerUI_4; }
	inline GameObject_t1756533147 ** get_address_of_playerUI_4() { return &___playerUI_4; }
	inline void set_playerUI_4(GameObject_t1756533147 * value)
	{
		___playerUI_4 = value;
		Il2CppCodeGenWriteBarrier(&___playerUI_4, value);
	}

	inline static int32_t get_offset_of_playerObjects_5() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___playerObjects_5)); }
	inline GameObjectU5BU5D_t3057952154* get_playerObjects_5() const { return ___playerObjects_5; }
	inline GameObjectU5BU5D_t3057952154** get_address_of_playerObjects_5() { return &___playerObjects_5; }
	inline void set_playerObjects_5(GameObjectU5BU5D_t3057952154* value)
	{
		___playerObjects_5 = value;
		Il2CppCodeGenWriteBarrier(&___playerObjects_5, value);
	}

	inline static int32_t get_offset_of_player_Text_6() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___player_Text_6)); }
	inline TextU5BU5D_t4216439300* get_player_Text_6() const { return ___player_Text_6; }
	inline TextU5BU5D_t4216439300** get_address_of_player_Text_6() { return &___player_Text_6; }
	inline void set_player_Text_6(TextU5BU5D_t4216439300* value)
	{
		___player_Text_6 = value;
		Il2CppCodeGenWriteBarrier(&___player_Text_6, value);
	}

	inline static int32_t get_offset_of_roomName_7() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___roomName_7)); }
	inline Text_t356221433 * get_roomName_7() const { return ___roomName_7; }
	inline Text_t356221433 ** get_address_of_roomName_7() { return &___roomName_7; }
	inline void set_roomName_7(Text_t356221433 * value)
	{
		___roomName_7 = value;
		Il2CppCodeGenWriteBarrier(&___roomName_7, value);
	}

	inline static int32_t get_offset_of_gameStartButton_8() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___gameStartButton_8)); }
	inline GameObject_t1756533147 * get_gameStartButton_8() const { return ___gameStartButton_8; }
	inline GameObject_t1756533147 ** get_address_of_gameStartButton_8() { return &___gameStartButton_8; }
	inline void set_gameStartButton_8(GameObject_t1756533147 * value)
	{
		___gameStartButton_8 = value;
		Il2CppCodeGenWriteBarrier(&___gameStartButton_8, value);
	}

	inline static int32_t get_offset_of_gameStartButtonText_9() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___gameStartButtonText_9)); }
	inline Text_t356221433 * get_gameStartButtonText_9() const { return ___gameStartButtonText_9; }
	inline Text_t356221433 ** get_address_of_gameStartButtonText_9() { return &___gameStartButtonText_9; }
	inline void set_gameStartButtonText_9(Text_t356221433 * value)
	{
		___gameStartButtonText_9 = value;
		Il2CppCodeGenWriteBarrier(&___gameStartButtonText_9, value);
	}

	inline static int32_t get_offset_of_nameField_10() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___nameField_10)); }
	inline GameObject_t1756533147 * get_nameField_10() const { return ___nameField_10; }
	inline GameObject_t1756533147 ** get_address_of_nameField_10() { return &___nameField_10; }
	inline void set_nameField_10(GameObject_t1756533147 * value)
	{
		___nameField_10 = value;
		Il2CppCodeGenWriteBarrier(&___nameField_10, value);
	}

	inline static int32_t get_offset_of_inputNameField_11() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___inputNameField_11)); }
	inline InputField_t1631627530 * get_inputNameField_11() const { return ___inputNameField_11; }
	inline InputField_t1631627530 ** get_address_of_inputNameField_11() { return &___inputNameField_11; }
	inline void set_inputNameField_11(InputField_t1631627530 * value)
	{
		___inputNameField_11 = value;
		Il2CppCodeGenWriteBarrier(&___inputNameField_11, value);
	}

	inline static int32_t get_offset_of_playerCount_12() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___playerCount_12)); }
	inline int32_t get_playerCount_12() const { return ___playerCount_12; }
	inline int32_t* get_address_of_playerCount_12() { return &___playerCount_12; }
	inline void set_playerCount_12(int32_t value)
	{
		___playerCount_12 = value;
	}

	inline static int32_t get_offset_of_maxPlayers_13() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___maxPlayers_13)); }
	inline int32_t get_maxPlayers_13() const { return ___maxPlayers_13; }
	inline int32_t* get_address_of_maxPlayers_13() { return &___maxPlayers_13; }
	inline void set_maxPlayers_13(int32_t value)
	{
		___maxPlayers_13 = value;
	}

	inline static int32_t get_offset_of_isOpenUI_14() { return static_cast<int32_t>(offsetof(WaitingRoomManager_t1781439173, ___isOpenUI_14)); }
	inline bool get_isOpenUI_14() const { return ___isOpenUI_14; }
	inline bool* get_address_of_isOpenUI_14() { return &___isOpenUI_14; }
	inline void set_isOpenUI_14(bool value)
	{
		___isOpenUI_14 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
