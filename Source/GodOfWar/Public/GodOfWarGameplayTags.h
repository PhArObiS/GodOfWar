// // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace GodOfWarGameplayTags
{
	/** Input Tags **/
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player Tags **/
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
	
}
