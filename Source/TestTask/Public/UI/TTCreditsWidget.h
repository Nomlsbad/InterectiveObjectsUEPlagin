// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/TTBaseWidget.h"
#include "TTCreditsWidget.generated.h"

class UButton;

UCLASS()
class TESTTASK_API UTTCreditsWidget : public UTTBaseWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	UButton* GoBackButton;

	virtual void NativeOnInitialized() override;
	
private:

	UFUNCTION()
	void OnGoBack();
};
