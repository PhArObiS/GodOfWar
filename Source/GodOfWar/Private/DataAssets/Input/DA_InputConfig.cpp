// // Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DA_InputConfig.h"

UInputAction* UDA_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FGodOfWarInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
