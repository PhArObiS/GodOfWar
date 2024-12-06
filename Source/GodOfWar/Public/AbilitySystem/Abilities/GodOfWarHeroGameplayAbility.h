// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GodOfWarGameplayAbility.h"
#include "GodOfWarHeroGameplayAbility.generated.h"

class UHeroUIComponent;
class UHeroCombatComponent;
class AGodOfWarHeroController;
class AGodOfWarHeroCharacter;
/**
 * 
 */
UCLASS()
class GODOFWAR_API UGodOfWarHeroGameplayAbility : public UGodOfWarGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	AGodOfWarHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	AGodOfWarHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	UHeroUIComponent* GetHeroUIComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Ability")
	bool GetAbilityRemainingCooldownByTag(FGameplayTag InCooldownTag, float& TotalCooldownTime, float& RemainingCooldownTime);

private:
	TWeakObjectPtr<AGodOfWarHeroCharacter> CachedGodOfWarHeroCharacter;
	TWeakObjectPtr<AGodOfWarHeroController> CachedGodOfWarHeroController;
};
