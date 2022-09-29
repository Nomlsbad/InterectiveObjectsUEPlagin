// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTInteractionComponent.h"
#include "DrawDebugHelpers.h"
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
	UpdateTargetTimerDelegate.BindUObject(this, &UTTInteractionComponent::UpdatePotentialForInteract);
	GetWorld()->GetTimerManager().SetTimer(UpdaterTargetTimerHandle, UpdateTargetTimerDelegate, UpdateTargetRate, true);
}

void UTTInteractionComponent::TryToInteract()
{
	if (!PotentialForInteract || !PotentialForInteract->GetReadyToInteract()) return;

	PotentialForInteract->StartInteraction();
}

void UTTInteractionComponent::UpdatePotentialForInteract()
{
	FHitResult HitResult;

	PotentialForInteract = nullptr;
	
	GetHitResultInInteractiveChannel(HitResult);
	if (!HitResult.GetComponent()) return;
	
	const auto InputInteractiveActor = Cast<ATTPlayerInputInteractiveActor>(HitResult.GetActor()->GetOwner());
	if (!InputInteractiveActor) return;

	PotentialForInteract = InputInteractiveActor;
}

bool UTTInteractionComponent::GetHitResultInInteractiveChannel(FHitResult& HitResult,
	const FCollisionQueryParams& Params, const FCollisionResponseParams& ResponseParam) const
{	
	const auto Character = Cast<ATTPlayerCharacter>(GetOwner());
	if (!Character) return false;
	
	const auto Controller = Character->GetController<APlayerController>();
	if (!Controller) return false;

	const FRotator CameraRotation = Character->GetFollowCamera()->GetComponentRotation();
	const FVector PlayerLocation = Character->GetActorLocation();
	
	const FVector Start = PlayerLocation;
	const FVector End = Start + CameraRotation.Vector() * MaxDistanceToTarget;
	
	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, UpdateTargetRate, 0, 3);

	return GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel1);
}


