// // Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/GodOfWarHeroWeapon.h"

void AGodOfWarHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AGodOfWarHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}