// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWidget.h"

void UBaseWidget::SendMessage(const FString& msg)
{
	this->OnMessageReceived(msg);
}