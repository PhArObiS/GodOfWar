// NLDevs All Rights Reserved

#include "AI/BTService_OrientToTargetActor.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Constructor: Initializes default values for the service.
UBTService_OrientToTargetActor::UBTService_OrientToTargetActor()
{
	// Set the name for the node, which will be displayed in the behavior tree editor.
	NodeName = TEXT("Native Orient Rotation To Target Actor");

	// Initialize notify flags (default behavior tree service flags).
	INIT_SERVICE_NODE_NOTIFY_FLAGS();

	// Set default interpolation speed for rotation and update intervals.
	RotationInterpSpeed = 5.f; 
	Interval = 0.f;            // Update every frame
	RandomDeviation = 0.f;      // No random deviation in updates

	// Ensure that the blackboard key is filtered to only allow actor objects.
	InTargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, InTargetActorKey), AActor::StaticClass());
}

// Initialize the service from the behavior tree asset.
void UBTService_OrientToTargetActor::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	// Ensure that the target actor key is correctly resolved within the blackboard data.
	if (UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		InTargetActorKey.ResolveSelectedKey(*BBAsset);
	}
}

// Provides a description for the node, used for debugging.
FString UBTService_OrientToTargetActor::GetStaticDescription() const
{
	const FString KeyDescription = InTargetActorKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("Orient rotation to %s key %s"), *KeyDescription, *GetStaticServiceDescription());
}

// Main logic: Rotates the owning pawn to face the target actor each tick.
void UBTService_OrientToTargetActor::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Get the target actor from the blackboard.
	UObject* ActorObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(InTargetActorKey.SelectedKeyName);
	AActor* TargetActor = Cast<AActor>(ActorObject);

	// Get the AI-controlled pawn (the pawn that owns this service).
	APawn* OwningPawn = OwnerComp.GetAIOwner()->GetPawn();

	// If both the owning pawn and the target actor are valid, update the rotation.
	if (OwningPawn && TargetActor)
	{
		// Calculate the rotation needed to face the target actor.
		const FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(OwningPawn->GetActorLocation(), TargetActor->GetActorLocation());
		
		// Interpolate between the current rotation and the desired rotation (towards the target).
		const FRotator TargetRot = FMath::RInterpTo(OwningPawn->GetActorRotation(), LookAtRot, DeltaSeconds, RotationInterpSpeed);

		// Apply the interpolated rotation to the owning pawn.
		OwningPawn->SetActorRotation(TargetRot);
	}
}
