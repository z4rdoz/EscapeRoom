// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomHUD.h"
#include "Blueprint/UserWidget.h"
#include "ExaminableWidget.h"
#include "TargetWidget.h"

void AEscapeRoomHUD::BeginPlay()
{		
	//Target widget
	if (TargetWidgetRef)
	{				
		TargetWidget = CreateWidget<UTargetWidget>(GetWorld(), TargetWidgetRef);
		if (TargetWidget)
		{			
			TargetWidget->AddToViewport();
		}
	}

	//Examine Widget
	if (ExamineWidgetRef)
	{
		ExamineWidget = CreateWidget<UExaminableWidget>(GetWorld(), ExamineWidgetRef);
		if (ExamineWidget)
		{
			ExamineWidget->AddToViewport();
			ExamineWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	SetGameState(EEscapeRoomState::Default);
}

void AEscapeRoomHUD::SetGameState(EEscapeRoomState gamestate)
{
	/*if (!(
		ExamineWidget && 
		TargetWidget
		))
	{
		UE_LOG(LogTemp, Warning, TEXT("A widget reference is not set."));
		return;
	}*/

	_gameState = gamestate;

	//ExamineWidget->SetVisibility(ESlateVisibility::Hidden);
	//TargetWidget->SetVisibility(ESlateVisibility::Hidden);
	//switch (_gameState)
	//{
	//case EEscapeRoomState::Default:
	//	TargetWidget->SetVisibility(ESlateVisibility::Visible);
	//	break;
	//case EEscapeRoomState::Examining:
	//	ExamineWidget->SetVisibility(ESlateVisibility::Visible);
	//	break;
	//default:
	//	break;
	//}
}

EEscapeRoomState AEscapeRoomHUD::GetGameState()
{
	return _gameState;
}
