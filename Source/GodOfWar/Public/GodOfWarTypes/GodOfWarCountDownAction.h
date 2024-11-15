// NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GodOfWarEnumTypes.h"

class FGodOfWarCountDownAction : public FPendingLatentAction
{
public:
	FGodOfWarCountDownAction(float InTotalCountDownTime, float InUpdateInterval, float& InOutRemainingTime, EGodOfWarCountDownActionOutput& InCountDownOutput, const FLatentActionInfo& LatentInfo)
	: bNeedToCancel(false) 
	, TotalCountDownTime(InTotalCountDownTime)
	, UpdateInterval(InUpdateInterval)
	, OutRemainingTime(InOutRemainingTime)
	, CountDownOutput(InCountDownOutput)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
	, ElapsedInterval(0.f)
	, ElapsedTimeSinceStart(0.f)
	{
		
	}

private:
	bool bNeedToCancel;
	float TotalCountDownTime;
	float UpdateInterval;
	float& OutRemainingTime;
	EGodOfWarCountDownActionOutput& CountDownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;
};
