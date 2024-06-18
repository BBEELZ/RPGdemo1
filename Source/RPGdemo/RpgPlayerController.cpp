// Fill out your copyright notice in the Description page of Project Settings.


#include "RpgPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RpgCharacterBase.h"
#include "RpgGameModeBase.h"

void ARpgPlayerController::BeginPlay()
{

}

void ARpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ARpgPlayerController::RequestJump);
		InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Released, this, &ARpgPlayerController::RequestStopJump);

		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Pressed, this, &ARpgPlayerController::RequestCrouchStart);
		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Released, this, &ARpgPlayerController::RequestCrouchEnd);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &ARpgPlayerController::RequestSprintStart);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &ARpgPlayerController::RequestSprintEnd);

		InputComponent->BindAxis(TEXT("MoveForward"), this, &ARpgPlayerController::RequestMoveForward);
		InputComponent->BindAxis(TEXT("MoveRight"), this, &ARpgPlayerController::RequestMoveRight);
		InputComponent->BindAxis(TEXT("LookUp"), this, &ARpgPlayerController::RequestLookUp);
		InputComponent->BindAxis(TEXT("LookRight"), this, &ARpgPlayerController::RequestLookRight);

	}
}

void ARpgPlayerController::RequestMoveForward(float AxisValue)
{
	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		// transform to world space and add it
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisValue);
	}
}

void ARpgPlayerController::RequestMoveRight(float AxisValue)
{
	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		// transform to world space and add it
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), AxisValue);
	}
}

void ARpgPlayerController::RequestLookUp(float AxisValue)
{
	AddPitchInput(AxisValue * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ARpgPlayerController::RequestLookRight(float AxisValue)
{
	AddYawInput(AxisValue * BaseLookRightRate * GetWorld()->GetDeltaSeconds());
}

void ARpgPlayerController::RequestJump()
{
	if (ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter()))
	{
		RpgCharacterBase->Jump();
	}
}

void ARpgPlayerController::RequestStopJump()
{
	if (ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter()))
	{
		RpgCharacterBase->StopJumping();
	}
}

void ARpgPlayerController::RequestCrouchStart()
{
	ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter());
	if (!RpgCharacterBase || !RpgCharacterBase->GetCharacterMovement()->IsMovingOnGround())
	{
		return;
	}

	RpgCharacterBase->Crouch();
}

void ARpgPlayerController::RequestCrouchEnd()
{
	if (ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter()))
	{
		RpgCharacterBase->UnCrouch();
	}
}

void ARpgPlayerController::RequestSprintStart()
{
	if (ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter()))
	{
		RpgCharacterBase->RequestSprintStart();
	}
}

void ARpgPlayerController::RequestSprintEnd()
{
	if (ARpgCharacterBase* RpgCharacterBase = Cast<ARpgCharacterBase>(GetCharacter()))
	{
		RpgCharacterBase->RequestSprintEnd();
	}
}
