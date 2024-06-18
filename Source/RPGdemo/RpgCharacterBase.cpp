// Fill out your copyright notice in the Description page of Project Settings.


#include "RpgCharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RpgPlayerController.h"

// Sets default values
ARpgCharacterBase::ARpgCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARpgCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARpgCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARpgCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARpgCharacterBase::RequestSprintStart()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ARpgCharacterBase::RequestSprintEnd()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}
