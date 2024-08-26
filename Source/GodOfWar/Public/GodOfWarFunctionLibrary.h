// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GodOfWarFunctionLibrary.generated.h"

// struct FGameplayTag;
class UGodOfWarAbilitySystemComponent;

UENUM()
enum class EGodOfWarConfirmType : uint8
{
	Yes,
	No
};

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
};
