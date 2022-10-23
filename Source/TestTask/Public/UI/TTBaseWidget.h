// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTBaseHUD.h"
#include "Blueprint/UserWidget.h"
#include "TTBaseWidget.generated.h"


UCLASS()
class TESTTASK_API UTTBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	EHUDState GetPreviousWidgetName() const { return PreviousWidgetName; }
	void SetPreviousWidgetName(EHUDState WidgetName) { PreviousWidgetName = WidgetName; }

protected:

	EHUDState PreviousWidgetName = EHUDState::None;

	bool ChangeCurrentWidgetTo(EHUDState WidgetName);

	bool GoBack();

private:

	ATTBaseHUD* GetBaseHUD();
};
