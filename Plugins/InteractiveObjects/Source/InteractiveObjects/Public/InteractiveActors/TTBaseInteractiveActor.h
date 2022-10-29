// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTBaseInteractiveActor.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogTTInteractiveObjects, All, All);
	
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnStartInteractionSignature, AActor*, InstigatedBy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnStopInteractionSignature);


UCLASS()
class INTERACTIVEOBJECTS_API ATTBaseInteractiveActor : public AActor
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

	UFUNCTION(BlueprintCallable, Category = "InteractiveObject | Interaction")
	virtual bool IsReadyToStartInteraction() {return false;}

	UFUNCTION(BlueprintCallable, Category = "InteractiveObject | Interaction")
	virtual bool IsReadyToStopInteraction() {return false;}

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObject | Interacrion Options")
	bool bStoreOverlappingActors = false;

	UPROPERTY(BlueprintReadOnly)
	int32 CountOfOverlappingActors = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObject | Collision")
	TArray<FName> CollisionComponentNames;

	UPROPERTY()
	TArray<UPrimitiveComponent*> CollisionComponents;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Collision")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Collision")
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;

	bool GetOverlappingActors(TArray<AActor*>& Actors) const;

private:

	UPROPERTY()
	TArray<AActor*> OverlappingActors;
	
	FComponentReference CollisionComponentReference;
};
