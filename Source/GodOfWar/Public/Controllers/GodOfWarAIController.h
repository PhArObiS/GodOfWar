// NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GodOfWarAIController.generated.h"

struct FAIStimulus;
class UAISenseConfig_Sight;
/**
 * 
 */
UCLASS()
class GODOFWAR_API AGodOfWarAIController : public AAIController
{
	GENERATED_BODY()

public:
	AGodOfWarAIController(const FObjectInitializer& ObjectInitializer);

	//~ Begin IGenericTeamAgentInterface Interface
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	//~ End IGenericTeamAgentInterface
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAIPerceptionComponent* EnemyPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Sight* AISenseConfig_Sight;

	UFUNCTION()
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
