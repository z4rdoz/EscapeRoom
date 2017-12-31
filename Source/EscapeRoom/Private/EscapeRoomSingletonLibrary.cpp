// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSingletonLibrary.h"
#include "EscapeRoom.h"

UEscapeRoomSingleton* UEscapeRoomSingletonLibrary::GetSingleton()
{
	UEscapeRoomSingleton* dataInstance = Cast<UEscapeRoomSingleton>(GEngine->GameSingleton);

	if (!dataInstance) return NULL;
	if (!dataInstance->IsValidLowLevel()) return NULL;

	return dataInstance;
}


