// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "Components/ShapeComponent.h"

FName ATTBaseInteractiveActor::CollisionComponentName(TEXT("CollisionComponent"));

ATTBaseInteractiveActor::ATTBaseInteractiveActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UShapeComponent>(CollisionComponentName);
}


void ATTBaseInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
}
