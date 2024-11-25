// NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GodOfWarPickupBase.generated.h"

class USphereComponent;

UCLASS()
class GODOFWAR_API AGodOfWarPickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGodOfWarPickupBase();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pick Up Interation")
	USphereComponent* PickUpCollisionSphere;

	UFUNCTION()
	virtual void OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
