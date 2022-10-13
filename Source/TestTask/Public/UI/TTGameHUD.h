// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TTGameHUD.generated.h"


UCLASS()
class TESTTASK_API ATTGameHUD : public AHUD
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	UUserWidget* PlayerHUDWidget;
	
};
