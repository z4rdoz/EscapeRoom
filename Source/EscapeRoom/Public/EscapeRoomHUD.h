// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widget.h"
#include "EscapeRoomGameModeBase.h"
#include "EscapeRoomHUD.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API AEscapeRoomHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void AEscapeRoomHUD::BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "GameState")
		void SetGameState(EEscapeRoomState gameState);

	UFUNCTION(BlueprintCallable, Category = "GameState")
		EEscapeRoomState GetGameState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomHUD)
		TSubclassOf<class UBaseWidget> TargetWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomHUD)
		TSubclassOf<class UBaseWidget> ExamineWidgetRef;


	class UBaseWidget* TargetWidget;
	class UBaseWidget* ExamineWidget;

private:
	EEscapeRoomState _gameState = EEscapeRoomState::Default;
};
