// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTBaseInteractiveActor.generated.h"

UCLASS()
class TESTTASK_API ATTBaseInteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ATTBaseInteractiveActor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
