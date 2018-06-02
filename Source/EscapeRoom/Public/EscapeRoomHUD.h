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
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "GameState")
		void SetGameState(EEscapeRoomState gameState);

	UFUNCTION(BlueprintCallable, Category = "GameState")
		EEscapeRoomState GetGameState();	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomHUD)
		TSubclassOf<class UTargetWidget> TargetWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomHUD)
		TSubclassOf<class UExaminableWidget> ExamineWidgetRef;


	class UTargetWidget* TargetWidget;
	class UExaminableWidget* ExamineWidget;

private:
	EEscapeRoomState _gameState = EEscapeRoomState::Default;
};
