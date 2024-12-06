// NLDevs All Rights Reserved


#include "Items/Pickups/GodOfWarStoneBase.h"
#include "GodOfWarGameplayTags.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "Characters/GodOfWarHeroCharacter.h"


void AGodOfWarStoneBase::Consume(UGodOfWarAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel)
{
	check(StoneGameplayEffectClass);

	UGameplayEffect* EffectCDO = StoneGameplayEffectClass->GetDefaultObject<UGameplayEffect>();
	
	AbilitySystemComponent->ApplyGameplayEffectToSelf(
		EffectCDO,
		ApplyLevel,
		AbilitySystemComponent->MakeEffectContext()
	);

	BP_OnStoneConsumed();
}

void AGodOfWarStoneBase::OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AGodOfWarHeroCharacter* OverlappedHeroCharacter = Cast<AGodOfWarHeroCharacter>(OtherActor))
	{
		OverlappedHeroCharacter->GetGodOfWarAbilitySystemComponent()->TryActivateAbilityByTag(GodOfWarGameplayTags::Player_Ability_PickUp_Stones);
	}
}


 