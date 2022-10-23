// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TTBaseHUD.generated.h"


UENUM(BlueprintType)
enum class EHUDState : uint8
{
	None = 0,
	MainMenu,
	Settings,
	Credits,
	PlayerHUD
};

class UTTBaseWidget;

UCLASS()
class TESTTASK_API ATTBaseHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool ChangeCurrentWidgetTo(EHUDState WidgetKey);

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool GoBack();
	
protected:

	UPROPERTY()
	TMap<EHUDState, UTTBaseWidget*> Widgets;
	
	EHUDState CurrentWidgetName = EHUDState::None;
};
