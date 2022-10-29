// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTInteractionComponent.h"
#include "DrawDebugHelpers.h"
#include "TTInteractiveObjectsSettings.h"
#include "Camera/CameraComponent.h"
#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"
#include "Player/TTPlayerCharacter.h"


UTTInteractionComponent::UTTInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTTInteractionComponent::InitializeUpdaterTargetTimer()
{
	FTimerDelegate UpdateTargetTimerDelegate;
	UpdateTargetRate = GetDefault<UTTInteractiveObjectsSettings>()->UpdateTargetRate;
	
	UpdateTargetTimerDelegate.BindUObject(this, &UTTInteractionComponent::UpdatePotentialForInteract);
	GetWorld()->GetTimerManager().SetTimer(UpdaterTargetTimerHandle, UpdateTargetTimerDelegate, UpdateTargetRate, true);
}

void UTTInteractionComponent::TryToInteract()
{
	if (!IsValid(PotentialForInteract)
		|| !PotentialForInteract->IsReadyToStartInteraction()
		|| !IsValid(this->GetOwner())) return;

	PotentialForInteract->StartInteraction(GetOwner());
}

bool UTTInteractionComponent::GetInteractionText(FString& Text) const
{
	if (!PotentialForInteract) return false;
	Text = PotentialForInteract->GetInteractionText();
	return true;
}

void UTTInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
	const auto InteractiveShapeClassName = GetDefault<UTTInteractiveObjectsSettings>()->InteractiveShape;
	const auto InteractiveShapeClass = (InteractiveShapeClassName.IsValid() ?
		LoadObject<UClass>(GetOwner(), *InteractiveShapeClassName.ToString()) : nullptr);
	
	if (InteractiveShapeClass)
	{
		InteractiveShape = GetWorld()->SpawnActor<ATTBaseInteractiveActor>(InteractiveShapeClass);
		InteractiveShape->SetOwner(GetOwner());
	}
}

void UTTInteractionComponent::UpdatePotentialForInteract()
{
	FHitResult HitResult;
	FVector EndTrace;
	
	PotentialForInteract = nullptr;
	
	if (GetHitResultOnDistance(EndTrace, HitResult, ECC_Visibility))
	{
		const auto InputInteractiveActor = Cast<ATTPlayerInputInteractiveActor>(HitResult.GetComponent()->GetOwner());
		if (InputInteractiveActor)
		{
			PotentialForInteract = InputInteractiveActor;
		}
	}

	GenerateOverlapEvent(EndTrace);
}

bool UTTInteractionComponent::GetBoundaryPoints(FVector& Start, FVector& End) const
{
	const auto Pawn = Cast<APawn>(GetOwner());
	if (!Pawn) return false;

	const auto Controller = Pawn->GetController<APlayerController>();
	if (!Controller) return false;
	
	const auto CameraManager = Controller->PlayerCameraManager;
	if (!CameraManager) return false;
	
	const FRotator CameraRotation = CameraManager->GetCameraRotation();
	const FVector PlayerLocation = Pawn->GetActorLocation();
	
	Start = PlayerLocation;
	End = Start + CameraRotation.Vector() * MaxDistanceToTarget;

	return true;
}

void UTTInteractionComponent::GenerateOverlapEvent(const FVector& Location) const
{
	if (!IsValid(InteractiveShape)) return;
	InteractiveShape->SetActorLocation(Location);
}

bool UTTInteractionComponent::GetHitResultOnDistance(FVector& EndTrace, FHitResult& HitResult, ECollisionChannel TraceChannel,
                                                     const FCollisionQueryParams& Params, const FCollisionResponseParams& ResponseParam) const
{
	FVector Start;
	FVector End;
	if (!GetBoundaryPoints(Start, End)) return false;

	const bool bWasHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel);
	bWasHit ? EndTrace = HitResult.ImpactPoint : EndTrace = End;
	DrawDebugLine(GetWorld(), Start, bWasHit ? HitResult.ImpactPoint : End, FColor::Orange, false, UpdateTargetRate, 0, 3);

	return bWasHit;
}


