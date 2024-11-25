// // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GodOfWarTypes/GodOfWarEnumTypes.h"
#include "GodOfWarGameplayAbility.generated.h"

class UGodOfWarAbilitySystemComponent;
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class EGodOfWarAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class GODOFWAR_API UGodOfWarGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplay Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplay Interface

	UPROPERTY(EditDefaultsOnly, Category = "GodOfWar")
	EGodOfWarAbilityActivationPolicy GodOfWarAbilityActivationPolicy = EGodOfWarAbilityActivationPolicy::OnTriggered;
	
	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	UGodOfWarAbilitySystemComponent* GetGodOfWarAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle) const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle To Target Actor", ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EGodOfWarSuccessType& OutSuccessType);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|Ability")
	void ApplyGameplayEffectSpecHandleToHitResults(const FGameplayEffectSpecHandle& InSpecHandle, const TArray<FHitResult>& InHitResults);
};
