// // NLDevs All Rights Reserved


#include "GodOfWarFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UGodOfWarAbilitySystemComponent* UGodOfWarFunctionLibrary::NativeGetGodOfWarASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UGodOfWarAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UGodOfWarFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UGodOfWarAbilitySystemComponent* ASC = 	NativeGetGodOfWarASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UGodOfWarFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UGodOfWarAbilitySystemComponent* ASC = 	NativeGetGodOfWarASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UGodOfWarFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UGodOfWarAbilitySystemComponent* ASC = 	NativeGetGodOfWarASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UGodOfWarFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EGodOfWarConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EGodOfWarConfirmType::Yes : EGodOfWarConfirmType::No;
}

UPawnCombatComponent* UGodOfWarFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}
	return nullptr;
}

UPawnCombatComponent* UGodOfWarFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, EGodOfWarValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	
	OutValidType = CombatComponent ? EGodOfWarValidType::Valid : EGodOfWarValidType::Invalid;
	
	return CombatComponent;
}

