// // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GodOfWarTypes/GodOfWarStructTypes.h"
#include "Items/Weapons/GodOfWarWeaponBase.h"
#include "GodOfWarHeroWeapon.generated.h"


/**
 * 
 */
UCLASS()
class GODOFWAR_API AGodOfWarHeroWeapon : public AGodOfWarWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FGodOfWarHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;
private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
