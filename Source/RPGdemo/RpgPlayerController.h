// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RpgPlayerController.generated.h"

class ARpgCharacterBase;

UCLASS()
class RPGDEMO_API ARpgPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

protected:
	void SetupInputComponent() override;

	void RequestMoveForward(float AxisValue);
	void RequestMoveRight(float AxisValue);
	void RequestLookUp(float AxisValue);
	void RequestLookRight(float AxisValue);
	
	void RequestJump();
	void RequestStopJump();

	void RequestCrouchStart();
	void RequestCrouchEnd();

	void RequestSprintStart();
	void RequestSprintEnd();

	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseLookUpRate = 90.0f;

	/** Base lookright rate, in deg/sec. Other scaling may affect final lookup rate. */
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseLookRightRate = 90.0f;
};
