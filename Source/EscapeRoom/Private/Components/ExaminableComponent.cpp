// Fill out your copyright notice in the Description page of Project Settings.

#include "ExaminableComponent.h"

// Sets default values for this component's properties
UExaminableComponent::UExaminableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	
}

// Called when the game starts
void UExaminableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	_hud = Cast<AEscapeRoomHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}


// Called every frame
void UExaminableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UExaminableComponent::Examine()
{
	_hud->ExamineWidget->DialogText = ExamineText;
	_hud->ExamineWidget->SetVisibility(ESlateVisibility::Visible);
	_hud->TargetWidget->SetVisibility(ESlateVisibility::Hidden);
	OnMouseOut();
}

void UExaminableComponent::StopExamining()
{
	_hud->ExamineWidget->SetVisibility(ESlateVisibility::Hidden);
	_hud->TargetWidget->SetVisibility(ESlateVisibility::Visible);
	OnMouseIn();	
}

void UExaminableComponent::OnMouseIn()
{
	UPrimitiveComponent* primitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetComponentByClass(UPrimitiveComponent::StaticClass()));
	primitiveComponent->SetRenderCustomDepth(true);
	_hud->TargetWidget->ExamineVisibility = ESlateVisibility::Visible;
}

void UExaminableComponent::OnMouseOut()
{
	UPrimitiveComponent* primitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetComponentByClass(UPrimitiveComponent::StaticClass()));
	primitiveComponent->SetRenderCustomDepth(false);
	_hud->TargetWidget->ExamineVisibility = ESlateVisibility::Hidden;
}
