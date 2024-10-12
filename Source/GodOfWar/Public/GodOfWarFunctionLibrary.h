// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GodOfWarTypes/GodOfWarEnumTypes.h"
#include "GodOfWarFunctionLibrary.generated.h"

struct FGameplayEffectSpecHandle;
class UPawnCombatComponent;
struct FGameplayTag;
class UGodOfWarAbilitySystemComponent;


/**
 * 
 */
UCLASS()
class GODOFWAR_API UGodOfWarFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UGodOfWarAbilitySystemComponent* NativeGetGodOfWarASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);
	
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EGodOfWarConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, EGodOfWarValidType& OutValidType);

	UFUNCTION(BlueprintPure, Category = "GodOfWar|FunctionLibrary")
	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);

	UFUNCTION(BlueprintCallable, Category = "GodOfWar|FunctionLibrary")
	static bool ApplyGameplayEffectSpecHandleToTargetActor(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle);
};
