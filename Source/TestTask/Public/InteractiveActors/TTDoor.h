// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveActors/TTPlayerInputInteractiveActor.h"
#include "TTDoor.generated.h"


UCLASS()
class TESTTASK_API ATTDoor : public ATTPlayerInputInteractiveActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "InteractiveObject | Interaction")
	bool IsOpen = false;

	virtual void StartInteraction_Implementation(AActor* InstigatedBy) override;
};
