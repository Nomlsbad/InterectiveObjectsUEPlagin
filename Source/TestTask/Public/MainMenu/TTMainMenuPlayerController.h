// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TTMainMenuPlayerController.generated.h"


UCLASS()
class TESTTASK_API ATTMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
};
