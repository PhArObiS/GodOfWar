// // Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/GodOfWarCharacterAnimInstance.h"
#include "KismetAnimationLibrary.h"
#include "Characters/GodOfWarBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGodOfWarCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AGodOfWarBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UGodOfWarCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	 if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation()); 
}
