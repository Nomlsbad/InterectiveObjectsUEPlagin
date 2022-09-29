// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/TestTaskCharacter.h"
#include "TTPlayerCharacter.generated.h"

class UTTInteractionComponent;

UCLASS()
class TESTTASK_API ATTPlayerCharacter : public ATestTaskCharacter
{
	GENERATED_BODY()

public:

	ATTPlayerCharacter();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTTInteractionComponent* InteractiveComponent;

	virtual void PossessedBy(AController* NewController) override;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void OnInteraction();
	
};
