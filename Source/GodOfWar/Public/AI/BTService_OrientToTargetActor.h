// NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_OrientToTargetActor.generated.h"

/**
 * Service that orients the owning pawn to face a target actor specified in the blackboard.
 * This service is used in AI behavior trees.
 */
UCLASS()
class GODOFWAR_API UBTService_OrientToTargetActor : public UBTService
{
	GENERATED_BODY()

public:
	// Constructor
	UBTService_OrientToTargetActor();

protected:
	//~ Begin UBTNode Interface 
	/** Initializes the service from the Behavior Tree asset. */
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

	/** Returns a description of the service for debugging and visualization purposes. */
	virtual FString GetStaticDescription() const override;
	//~ End UBTNode Interface

	/** Called every tick to update the rotation of the owning pawn towards the target actor. */
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	/** Blackboard key to retrieve the target actor to orient towards. */
	UPROPERTY(EditAnywhere, Category = "Target")
	FBlackboardKeySelector InTargetActorKey;

	/** Speed at which the owning pawn's rotation will interpolate towards the target. */
	UPROPERTY(EditAnywhere, Category = "Target")
	float RotationInterpSpeed;
};
