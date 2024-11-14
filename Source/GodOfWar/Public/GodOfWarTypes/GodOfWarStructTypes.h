// NLDevs All Rights Reserved

#pragma once

#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "GodOfWarStructTypes.generated.h"

class UGodOfWarGameplayAbility;
class UGodOfWarHeroLinkedAnimLayer;
class UInputMappingContext;


USTRUCT(BlueprintType)
struct FGodOfWarHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = " InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGodOfWarGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FGodOfWarHeroSpecialAbilitySet : public FGodOfWarHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> AbilityIconMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Player.Cooldown"))
	FGameplayTag AbilityCooldownTag;
	
};

USTRUCT(BlueprintType)
struct FGodOfWarHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGodOfWarHeroLinkedAnimLayer> WeaponAnimLayerToLink;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FGodOfWarHeroAbilitySet> DefaultWeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FGodOfWarHeroSpecialAbilitySet> SpecialWeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat WeaponBaseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> SoftWeaponIconTexture;
};