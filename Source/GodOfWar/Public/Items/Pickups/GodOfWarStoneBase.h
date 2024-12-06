// NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "Items/Pickups/GodOfWarPickupBase.h"
#include "GodOfWarStoneBase.generated.h"

class UGodOfWarAbilitySystemComponent;
class UGameplayEffect;
/**
 * 
 */

UCLASS()
class GODOFWAR_API AGodOfWarStoneBase : public AGodOfWarPickupBase
{
	GENERATED_BODY()

public:
	void Consume(UGodOfWarAbilitySystemComponent* AbilitySystemComponent, int32 ApplyLevel);
	
protected:
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Stone Consumed"))
	void BP_OnStoneConsumed();
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> StoneGameplayEffectClass;
	
};
