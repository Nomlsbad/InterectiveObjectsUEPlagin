// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTBaseHUD.h"
#include "GameFramework/HUD.h"
#include "TTGameHUD.generated.h"


UCLASS()
class TESTTASK_API ATTGameHUD : public ATTBaseHUD
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	virtual void BeginPlay() override;
};
