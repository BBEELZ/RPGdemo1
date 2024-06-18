// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RpgGameModeBase.generated.h"

class AController;
class ARpgPlayerController;

UCLASS()
class RPGDEMO_API ARpgGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARpgGameModeBase();

	virtual void BeginPlay() override;
	
};
