#pragma once

UENUM()
enum class EGodOfWarConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EGodOfWarValidType : uint8
{
	Valid,
	Invalid
};

UENUM()
enum class EGodOfWarSuccessType : uint8
{
	Successful,
	Failed
};

UENUM()
enum class EGodOfWarCountDownActionInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class EGodOfWarCountDownActionOutput : uint8
{
	Updated,
	Completed,
	Cancelled
};