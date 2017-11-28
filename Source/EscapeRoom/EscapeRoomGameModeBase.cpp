// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomGameModeBase.h"
#include "public/EscapeRoomCharacter.h"

AEscapeRoomGameModeBase::AEscapeRoomGameModeBase() 
	: Super::AGameModeBase()
{

	//DefaultPawnClass = AEscapeRoomCharacter::StaticClass();
}

void AEscapeRoomGameModeBase::StartPlay() 
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("HELLO WORLD"));
	}

	//UE_LOG(LogTemp, Warning, TEXT("Testing 123"));
}

