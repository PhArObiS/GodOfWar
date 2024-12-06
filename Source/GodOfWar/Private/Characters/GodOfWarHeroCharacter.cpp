// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GodOfWarHeroCharacter.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GodOfWarGameplayTags.h"
#include "Components/Input/GodOfWarInputComponent.h"
#include "DataAssets/Input/DA_InputConfig.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "Components/UI/HeroUIComponent.h"

#include "GodOfWarDebugHelper.h"

AGodOfWarHeroCharacter::AGodOfWarHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
	HeroUIComponent = CreateDefaultSubobject<UHeroUIComponent>(TEXT("HeroUIComponent"));
}

UPawnCombatComponent* AGodOfWarHeroCharacter::GetPawnCombatComponent() const
{
	return HeroCombatComponent;
}

UPawnUIComponent* AGodOfWarHeroCharacter::GetPawnUIComponent() const
{
	return HeroUIComponent;
}

UHeroUIComponent* AGodOfWarHeroCharacter::GetHeroUIComponent() const
{
	return HeroUIComponent;
}

void AGodOfWarHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadData = CharacterStartUpData.LoadSynchronous())
		{
			LoadData->GiveToAbilitySystemComponent(GodOfWarAbilitySystemComponent);
		}
	}
}

void AGodOfWarHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UGodOfWarInputComponent* GodOfWarInputComponent = CastChecked<UGodOfWarInputComponent>(PlayerInputComponent);

	GodOfWarInputComponent->BindNativeInputAction(InputConfigDataAsset, GodOfWarGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	GodOfWarInputComponent->BindNativeInputAction(InputConfigDataAsset, GodOfWarGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	GodOfWarInputComponent->BindNativeInputAction(InputConfigDataAsset, GodOfWarGameplayTags::InputTag_SwitchedTarget, ETriggerEvent::Triggered, this, &ThisClass::Input_SwitchTargetTriggered);
	GodOfWarInputComponent->BindNativeInputAction(InputConfigDataAsset, GodOfWarGameplayTags::InputTag_SwitchedTarget, ETriggerEvent::Completed, this, &ThisClass::Input_SwitchTargetCompleted);

	GodOfWarInputComponent->BindNativeInputAction(InputConfigDataAsset, GodOfWarGameplayTags::InputTag_PickUp_Stones, ETriggerEvent::Started, this, &ThisClass::Input_PickUpStonesStarted);
	GodOfWarInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void AGodOfWarHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGodOfWarHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGodOfWarHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGodOfWarHeroCharacter::Input_SwitchTargetTriggered(const FInputActionValue& InputActionValue)
{
	SwitchDirection = InputActionValue.Get<FVector2D>();
}

void AGodOfWarHeroCharacter::Input_SwitchTargetCompleted(const FInputActionValue& InputActionValue)
{
	FGameplayEventData Data;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		this,
		SwitchDirection.X > 0.f? GodOfWarGameplayTags::Player_Event_SwitchTarget_Right : GodOfWarGameplayTags::Player_Event_SwitchTarget_Left,
		Data
		);

	// Debug::Print(TEXT("SwitchDirection: ") + SwitchDirection.ToString());
}

void AGodOfWarHeroCharacter::Input_PickUpStonesStarted(const FInputActionValue& InputActionValue)
{
	FGameplayEventData Data;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		this,
		GodOfWarGameplayTags::Player_Event_ConsumeStones,
		Data
		);
}

void AGodOfWarHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	GodOfWarAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AGodOfWarHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	GodOfWarAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
