// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTBaseInteractiveActor.h"

ATTBaseInteractiveActor::ATTBaseInteractiveActor()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ATTBaseInteractiveActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollisionComponentReference.ComponentProperty = CollisionComponentName;
	BP_CollisionComponent = Cast<UPrimitiveComponent>(CollisionComponentReference.GetComponent(this));
}
