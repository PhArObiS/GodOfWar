// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

struct FGameplayTag;
class AGodOfWarWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

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

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

protected:
	TArray<AActor*> OverlappedActors;
private:
	TMap<FGameplayTag, AGodOfWarWeaponBase*> CharacterCarriedWeaponMap;
};