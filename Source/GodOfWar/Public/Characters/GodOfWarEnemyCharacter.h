// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/GodOfWarBaseCharacter.h"
#include "GodOfWarEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class GODOFWAR_API AGodOfWarEnemyCharacter : public AGodOfWarBaseCharacter
{
	GENERATED_BODY()

public:
	AGodOfWarEnemyCharacter();

protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartUpData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; };
};
