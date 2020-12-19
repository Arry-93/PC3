// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Components/SpotLightComponent.h"
#include "CharacterMovement.generated.h"

UCLASS()
class GAMETITLE_API ACharacterMovement : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterMovement();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpotLightComponent* FlashLight;



public:
	UPROPERTY(EditAnywhere, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(EditAnywhere, Category = Camera)
		float BaseLookUpRate;

public:
	//keyboard movement
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	//mouse rotation
	void TurnRate(float Rate);
	void LookUpRate(float Rate);
	//flashlight turn on/off
	void ToggleFlashLight();
	bool lightState = false;
	//camera control
	void ZoomIn();
	void ZoomOut();
	float cameraSpeed;
	bool isZoomIn;
	bool isZoomOut;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
