// Fill out your copyright notice in the Description page of Project Settings.


#include "RpgGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RpgPlayerController.h"

ARpgGameModeBase::ARpgGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ARpgGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}
