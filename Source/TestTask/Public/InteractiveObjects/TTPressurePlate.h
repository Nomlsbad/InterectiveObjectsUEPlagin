// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "TTPressurePlate.generated.h"


UCLASS()
class TESTTASK_API ATTPressurePlate : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

public:

	ATTPressurePlate(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void StartInteraction() override;
	virtual void FinishInteraction() override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* Plate;

	int32 CountOfOverlappingObjects;

	virtual void BeginPlay() override;
};
