// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTBaseHUD.h"
#include "UI/TTBaseWidget.h"


bool ATTBaseHUD::ChangeCurrentWidgetTo(EWidgetName WidgetKey)
{
	if (!Widgets.Contains(WidgetKey) || !Widgets.Contains(CurrentWidgetName)) return false;

	auto CurrentWidget = Widgets[CurrentWidgetName];
	EWidgetName PreviousWidgetName = EWidgetName::None;
	
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
		PreviousWidgetName = CurrentWidgetName;
	}

	CurrentWidgetName = WidgetKey;
	CurrentWidget = Widgets[WidgetKey];
	CurrentWidget->SetPreviousWidgetName(PreviousWidgetName);
	CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	
	return true;
}

bool ATTBaseHUD::GoBack()
{
	if (!Widgets.Contains(CurrentWidgetName)) return false;

	auto CurrentWidget = Widgets[CurrentWidgetName];
	if (!Widgets.Contains(CurrentWidget->GetPreviousWidgetName())) return false;

	const auto PreviousWidgetName = CurrentWidget->GetPreviousWidgetName();
	CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	CurrentWidget = Widgets[CurrentWidget->GetPreviousWidgetName()];
	if (!CurrentWidget) return false;

	CurrentWidgetName = PreviousWidgetName;
	CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	
	return true;
}
