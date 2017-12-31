// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSingleton.h"
#include "EscapeRoom.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.h"

UEscapeRoomSingleton::UEscapeRoomSingleton()
{
	
}

void UEscapeRoomSingleton::Init(UWorld* world)
{	
	EscapeRoomState = EEscapeRoomState::Default;

	//Target widget
	if (TargetWidgetRef)
	{				
		TargetWidget = CreateWidget<UBaseWidget>(world, TargetWidgetRef);
		if (TargetWidget)
		{			
			TargetWidget->AddToViewport();
		}
	}

	//Examine Widget
	if (ExamineWidgetRef)
	{
		ExamineWidget = CreateWidget<UBaseWidget>(world, ExamineWidgetRef);
		if (ExamineWidget)
		{
			ExamineWidget->AddToViewport();
			ExamineWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}