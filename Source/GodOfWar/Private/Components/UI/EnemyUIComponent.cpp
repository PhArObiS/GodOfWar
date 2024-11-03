// NLDevs All Rights Reserved


#include "Components/UI/EnemyUIComponent.h"
#include "Widgets/GodOfWarWidgetBase.h"

void UEnemyUIComponent::RegisterEnemyDrawnWidget(UGodOfWarWidgetBase* InWidgetToRegister)
{
	EnemyDrawnWidgets.Add(InWidgetToRegister);
}

void UEnemyUIComponent::RemoveEnemyDrawnWidgetsIfAny()
{
	if (EnemyDrawnWidgets.IsEmpty())
	{
		return;
	}

	for (UGodOfWarWidgetBase* DrawnWidget : EnemyDrawnWidgets)
	{
		if (DrawnWidget)
		{
			DrawnWidget->RemoveFromParent();
		}
	}
}
