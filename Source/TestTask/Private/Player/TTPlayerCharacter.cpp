// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TTPlayerCharacter.h"
#include "InteractiveObjects/TTInteractionComponent.h"

ATTPlayerCharacter::ATTPlayerCharacter()
{
	InteractiveComponent = CreateDefaultSubobject<UTTInteractionComponent>("InteractionComponent");
}

void ATTPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsValid(InteractiveComponent))
	{
		InteractiveComponent->InitializeUpdaterTargetTimer();
	}
}

void ATTPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATTPlayerCharacter::OnInteraction);
}

void ATTPlayerCharacter::OnInteraction()
{
	InteractiveComponent->TryToInteract();
}
