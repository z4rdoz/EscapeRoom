// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EscapeRoomGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API AEscapeRoomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AEscapeRoomGameModeBase();

	void StartPlay() override;	
};
