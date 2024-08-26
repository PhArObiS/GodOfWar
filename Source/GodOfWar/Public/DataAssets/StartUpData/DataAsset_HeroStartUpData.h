// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GodOfWarTypes/GodOfWarStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"


/**
 * 
 */
UCLASS()
class GODOFWAR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UGodOfWarAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FGodOfWarHeroAbilitySet> HeroStartUpAbilitySets;
};
