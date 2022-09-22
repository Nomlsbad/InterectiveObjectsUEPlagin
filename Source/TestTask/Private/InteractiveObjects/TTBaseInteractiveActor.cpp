// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTBaseInteractiveActor.h"


ATTBaseInteractiveActor::ATTBaseInteractiveActor()
{
 	PrimaryActorTick.bCanEverTick = true;
}


void ATTBaseInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATTBaseInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

