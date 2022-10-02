// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTInteractionComponent.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"
#include "InteractiveObjects/TTPlayerInteractiveSphere.h"
#include "Player/TTPlayerCharacter.h"


UTTInteractionComponent::UTTInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTTInteractionComponent::InitializeUpdaterTargetTimer()
{
	FTimerDelegate UpdateTargetTimerDelegate;
	UpdateTargetTimerDelegate.BindUObject(this, &UTTInteractionComponent::UpdatePotentialForInteract);
	GetWorld()->GetTimerManager().SetTimer(UpdaterTargetTimerHandle, UpdateTargetTimerDelegate, UpdateTargetRate, true);
}

void UTTInteractionComponent::TryToInteract()
{
	if (!IsValid(PotentialForInteract) || !PotentialForInteract->IsReadyToStartInteraction()) return;

	PotentialForInteract->StartInteraction();
}

void UTTInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	if (InteractiveSphereClass)
	{
		InteractiveSphere = GetWorld()->SpawnActor<ATTBaseInteractiveActor>(InteractiveSphereClass);
		InteractiveSphere->SetOwner(GetOwner());
	}
}

void UTTInteractionComponent::UpdatePotentialForInteract()
{
	FHitResult HitResult;

	PotentialForInteract = nullptr;
	
	if (!GetHitResultInInteractiveChannel(HitResult)) return;
	
	const auto InputInteractiveActor = Cast<ATTPlayerInputInteractiveActor>(HitResult.GetComponent()->GetOwner());
	if (!InputInteractiveActor) return;

	PotentialForInteract = InputInteractiveActor;
}

bool UTTInteractionComponent::GetHitResultInInteractiveChannel(FHitResult& HitResult,
	const FCollisionQueryParams& Params, const FCollisionResponseParams& ResponseParam) const
{	
	const auto Character = Cast<ATTPlayerCharacter>(GetOwner());
	if (!Character) return false;

	const FRotator CameraRotation = Character->GetFollowCamera()->GetComponentRotation();
	const FVector PlayerLocation = Character->GetActorLocation();
	
	const FVector Start = PlayerLocation;
	const FVector End = Start + CameraRotation.Vector() * MaxDistanceToTarget;

	const bool bWasHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (InteractiveSphere)
	{
		InteractiveSphere->SetActorLocation(bWasHit ? HitResult.ImpactPoint : End);
	}

	DrawDebugLine(GetWorld(), Start, bWasHit ? HitResult.ImpactPoint : End, FColor::Orange, false, UpdateTargetRate, 0, 3);

	return bWasHit;
}


