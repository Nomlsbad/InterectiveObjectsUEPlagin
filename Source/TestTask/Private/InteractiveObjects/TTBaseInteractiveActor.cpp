// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTBaseInteractiveActor.h"

FName ATTBaseInteractiveActor::CollisionComponentName(TEXT("CollisionComponent"));

ATTBaseInteractiveActor::ATTBaseInteractiveActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UPrimitiveComponent>(CollisionComponentName);
}