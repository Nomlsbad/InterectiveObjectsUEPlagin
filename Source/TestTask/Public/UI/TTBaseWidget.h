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

	EWidgetName GetPreviousWidgetName() const { return PreviousWidgetName; }
	void SetPreviousWidgetName(EWidgetName WidgetName) { PreviousWidgetName = WidgetName; }

protected:

	EWidgetName PreviousWidgetName = EWidgetName::None;

	bool ChangeCurrentWidgetTo(EWidgetName WidgetName);

	bool GoBack();

private:

	ATTBaseHUD* GetBaseHUD();
};
