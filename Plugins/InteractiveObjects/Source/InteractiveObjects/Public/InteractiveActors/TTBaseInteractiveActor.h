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

	UPROPERTY(BlueprintAssignable, Category = "InteractiveActor | Interaction")
	FOnStartInteractionSignature OnStartInteraction;

	UPROPERTY(BlueprintAssignable, Category = "InteractiveActor | Interaction")
	FOnStopInteractionSignature OnStopInteraction;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveActor | Interaction")
	void StartInteraction(AActor* InstigatedBy);
	virtual void StartInteraction_Implementation(AActor* InstigatedBy);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveActor | Interaction")
	void StopInteraction();
	virtual void StopInteraction_Implementation();

	UFUNCTION(BlueprintCallable, Category = "InteractiveActor | Interaction")
	virtual bool IsReadyToStartInteraction() {return false;}

	UFUNCTION(BlueprintCallable, Category = "InteractiveActor | Interaction")
	virtual bool IsReadyToStopInteraction() {return false;}

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveActor | Interacrion Options")
	bool bStoreOverlappingActors = false;

	UPROPERTY(BlueprintReadOnly)
	int32 CountOfOverlappingActors = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveActor | Collision")
	TArray<FName> CollisionComponentNames;

	UPROPERTY()
	TArray<UPrimitiveComponent*> CollisionComponents;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveActor | Collision")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveActor | Collision")
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void PostInitializeComponents() override;

	bool GetOverlappingActors(TArray<AActor*>& Actors) const;

private:

	UPROPERTY()
	TArray<AActor*> OverlappingActors;
	
	FComponentReference CollisionComponentReference;
};
