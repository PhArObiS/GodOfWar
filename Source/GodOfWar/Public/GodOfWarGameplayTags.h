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
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	/** Player Tags **/
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_HitPause);
	
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_HitPause);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Light);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Heavy);
	
	/** Enemy Tags **/
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Ranged);
	
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_Strafing);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_UnderAttack);

	/** Shared Tags **/
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death);
	
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact);
	
	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_BaseDamage);

	GODOFWAR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Dead);
	
}
