// // NLDevs All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GodOfWarGameplayTags.h"
#include "GodOfWarFunctionLibrary.h"

#include "GodOfWarDebugHelper.h"
#include "Characters/GodOfWarEnemyCharacter.h"
#include "Components/BoxComponent.h"


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

void UEnemyCombatComponent::ToggleBodyCollisionBoxCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	AGodOfWarEnemyCharacter* OwningEnemyCharacter = GetOwningPawn<AGodOfWarEnemyCharacter>();
	check(OwningEnemyCharacter);

	UBoxComponent* LeftHandCollisionBox = OwningEnemyCharacter->GetLeftHandCollisionBox();
	UBoxComponent* RightHandCollisionBox = OwningEnemyCharacter->GetRightHandCollisionBox();

	check(LeftHandCollisionBox && RightHandCollisionBox);
	switch (ToggleDamageType)
	{
	case EToggleDamageType::LeftHand:
		LeftHandCollisionBox->SetCollisionEnabled(bShouldEnable? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
		break;
		
	case EToggleDamageType::RightHand:
		RightHandCollisionBox->SetCollisionEnabled(bShouldEnable? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
		break;
		
	default:
		break;
	}

	if (!bShouldEnable)
	{
		OverlappedActors.Empty();
	}
}
