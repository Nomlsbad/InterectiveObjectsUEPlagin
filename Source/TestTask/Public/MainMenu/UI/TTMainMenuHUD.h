// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/TTBaseHUD.h"
#include "TTMainMenuHUD.generated.h"


UCLASS()
class TESTTASK_API ATTMainMenuHUD : public ATTBaseHUD
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> SettingsWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> CreatorsWidgetClass;

	virtual void BeginPlay() override;
};
