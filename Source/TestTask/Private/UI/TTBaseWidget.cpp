// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTBaseWidget.h"

bool UTTBaseWidget::ChangeCurrentWidgetTo(EWidgetName WidgetName)
{
	const auto BaseHUD = GetBaseHUD();
	if (!BaseHUD) return false;

	return BaseHUD->ChangeCurrentWidgetTo(WidgetName);;
}

bool UTTBaseWidget::GoBack()
{
	const auto BaseHUD = GetBaseHUD();
	if (!BaseHUD) return false;

	return BaseHUD->GoBack();
}

ATTBaseHUD* UTTBaseWidget::GetBaseHUD()
{
	if (!GetOwningPlayer()) return nullptr;
	return Cast<ATTBaseHUD>(GetOwningPlayer()->GetHUD());
}
