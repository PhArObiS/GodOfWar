// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

struct FGameplayTag;
class AGodOfWarWeaponBase;
/**
 * 
 */
UCLASS()
class GODOFWAR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AGodOfWarWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Combat")
	AGodOfWarWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)  const;

	UPROPERTY(BlueprintReadWrite, Category = "GodOfWar|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Combat")
	AGodOfWarWeaponBase* GetCharacterCurrentEquippedWeapon() const;

private:
	TMap<FGameplayTag, AGodOfWarWeaponBase*> CharacterCarriedWeaponMap;
};