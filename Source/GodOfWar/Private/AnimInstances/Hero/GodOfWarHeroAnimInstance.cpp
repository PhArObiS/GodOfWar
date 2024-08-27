// // Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/GodOfWarHeroAnimInstance.h"

#include "Characters/GodOfWarHeroCharacter.h"

void UGodOfWarHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AGodOfWarHeroCharacter>(OwningCharacter);
	}
}

void UGodOfWarHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
