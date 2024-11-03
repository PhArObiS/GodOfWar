// // NLDevs All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GodOfWarGameplayTags.h"
#include "GodOfWarFunctionLibrary.h"

#include "GodOfWarDebugHelper.h"


void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		// Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is hitting ") + HitActor->GetActorNameOrLabel());
		return;
	}
	
	OverlappedActors.AddUnique(HitActor);
	
	bool bIsValidBlock = false;

	const bool bIsPlayerBlocking = UGodOfWarFunctionLibrary::NativeDoesActorHaveTag(HitActor, GodOfWarGameplayTags::Player_Status_Blocking);
	const bool bIsMyAttackUnblockable = UGodOfWarFunctionLibrary::NativeDoesActorHaveTag(GetOwningPawn(), GodOfWarGameplayTags::Enemy_Status_Unblockable);

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		bIsValidBlock = UGodOfWarFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	
	if (bIsValidBlock)
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			HitActor,
			GodOfWarGameplayTags::Player_Event_SuccessfulBlock,
			EventData
			);
			
		
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			GodOfWarGameplayTags::Shared_Event_MeleeHit,
			EventData
			);
	}
}
