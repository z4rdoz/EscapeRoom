// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "ExaminableWidget.h"
#include "TargetWidget.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "EscapeRoomHUD.h"
#include "ExaminableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UExaminableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExaminableComponent();	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Examinable, meta = (MultiLine = true))
		FString ExamineText = "Don't leave this text naked";

	void Examine();

	void StopExamining();

	void OnMouseIn();

	void OnMouseOut();

private:
	AEscapeRoomHUD * _hud;
};
