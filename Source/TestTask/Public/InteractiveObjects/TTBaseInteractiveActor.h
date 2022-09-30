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
	
	ATTBaseInteractiveActor(const FObjectInitializer& ObjectInitializer);

	static FName CollisionComponentName;
	
	UFUNCTION(BlueprintNativeEvent)
	void StartInteraction();
	virtual void StartInteraction_Implementation() {}

	UFUNCTION(BlueprintNativeEvent)
	void FinishInteraction();
	virtual void FinishInteraction_Implementation() {}

	bool GetReadyToInteract() const { return bReadyToInteract; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	UPrimitiveComponent* CollisionComponent;

	bool bReadyToInteract;

	UFUNCTION(BlueprintNativeEvent)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {}

	UFUNCTION(BlueprintNativeEvent)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {}
};
