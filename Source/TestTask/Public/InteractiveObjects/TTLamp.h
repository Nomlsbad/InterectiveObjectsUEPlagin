// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "TTLamp.generated.h"

class UPointLightComponent;

UCLASS()
class TESTTASK_API ATTLamp : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

public:
	
	ATTLamp(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPointLightComponent* PointLightComponent;

	int32 CountOfPawnInRadius;

	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
	virtual void BeginPlay() override;
};
