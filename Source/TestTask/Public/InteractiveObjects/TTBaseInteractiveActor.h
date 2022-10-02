// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTBaseInteractiveActor.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogTTInteractiveObjects, All, All);

UCLASS()
class TESTTASK_API ATTBaseInteractiveActor : public AActor
{
	GENERATED_BODY()

public:
	ATTBaseInteractiveActor();

	UFUNCTION(BlueprintNativeEvent)
	void StartInteraction();
	virtual void StartInteraction_Implementation() {}

	UFUNCTION(BlueprintNativeEvent)
	void StopInteraction();
	virtual void StopInteraction_Implementation() {}

	UFUNCTION(BlueprintNativeEvent)
	bool IsReadyToStartInteraction();
	virtual bool IsReadyToStartInteraction_Implementation() { return false; }

	UFUNCTION(BlueprintNativeEvent)
	bool IsReadyToStopInteraction();
	virtual bool IsReadyToStopInteraction_Implementation() { return false; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UPrimitiveComponent* BP_CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	FName CollisionComponentName = "CollisionComponent";

	UFUNCTION(BlueprintNativeEvent)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {}

	UFUNCTION(BlueprintNativeEvent)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {}

	virtual void PostInitializeComponents() override;

private:
	FComponentReference CollisionComponentReference;
};
