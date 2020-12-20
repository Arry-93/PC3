// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "InteractableObject.generated.h"

UCLASS()
class GAMETITLE_API AInteractableObject : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInteractableObject();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
		UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

public:	
	bool isCurrentlyPossessed;

	void HorizontalRotation(float);
	void VerticalRotation(float);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
