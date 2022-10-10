// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTBaseInteractiveActor.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogTTInteractiveObjects, All, All);
	
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnStartInteractionSignature, AActor*, InstigatedBy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnStopInteractionSignature);


UCLASS()
class TESTTASK_API ATTBaseInteractiveActor : public AActor
{
	GENERATED_BODY()

public:
	
	ATTBaseInteractiveActor();

	UPROPERTY(BlueprintAssignable, Category = "InteractiveObject | Interaction")
	FOnStartInteractionSignature OnStartInteraction;

	UPROPERTY(BlueprintAssignable, Category = "InteractiveObject | Interaction")
	FOnStopInteractionSignature OnStopInteraction;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Interaction")
	void StartInteraction(AActor* InstigatedBy);
	virtual void StartInteraction_Implementation(AActor* InstigatedBy);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Interaction")
	void StopInteraction();
	virtual void StopInteraction_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Interaction")
	bool IsReadyToStartInteraction();
	virtual bool IsReadyToStartInteraction_Implementation() {return false;}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Interaction")
	bool IsReadyToStopInteraction();
	virtual bool IsReadyToStopInteraction_Implementation() {return false;}

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObject | Interacrion Options")
	bool bStoreOverlappingActors = false;

	UPROPERTY(BlueprintReadOnly)
	int32 CountOfOverlappingActors = 0;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> OverlappingActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObject | Collision")
	FName CollisionComponentName = "CollisionComponent";

	UPROPERTY()
	UPrimitiveComponent* BP_CollisionComponent;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Collision")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Collision")
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;

private:
	
	FComponentReference CollisionComponentReference;
};
