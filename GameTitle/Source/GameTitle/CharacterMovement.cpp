// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterMovement.h"

// Sets default values
ACharacterMovement::ACharacterMovement()
{
#pragma region PlayerControls
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//rotation x control from player 
	bUseControllerRotationPitch = false;

	//rotation y control from player 
	bUseControllerRotationYaw = false;

	//rotation z control from player 
	bUseControllerRotationRoll = false;

	//allow rotation to movement
	GetCharacterMovement()->bOrientRotationToMovement = false;
	//rotation rate
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	//velocity when jump
	GetCharacterMovement()->JumpZVelocity = 600.f;
	//how much we can control when in the air
	GetCharacterMovement()->AirControl = 0.2f;
#pragma endregion

#pragma region CameraControls
	//set camera parent
	//create empty for camera component location
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	//camera distance from arm lenght component
	CameraBoom->TargetArmLength = 0.f;
	//allow rotation to cameraboom
	CameraBoom->bUsePawnControlRotation = true;

	//set camera children in parent
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//deny rotation to followcamera, cameraboom control it
	FollowCamera->bUsePawnControlRotation = false;
#pragma endregion

#pragma region FlashLightControls
	FlashLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("FlashLight"));
	FlashLight->SetupAttachment(RootComponent);
	FlashLight->SetLightBrightness(100000);
#pragma endregion
}

// Called to bind functionality to input
void ACharacterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//set inputs mouse
	//mouse horizontal movement control y axis
	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ACharacterMovement::TurnRate);
	//mouse vertical movement control x axis
	PlayerInputComponent->BindAxis("MouseVertical", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACharacterMovement::LookUpRate);

	//set inputs keyboard
	//jump when press, stop jump when release
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//bind MoveForward
	PlayerInputComponent->BindAxis("Horizontal", this, &ACharacterMovement::MoveForward);
	//bind MoveRight
	PlayerInputComponent->BindAxis("Vertical", this, &ACharacterMovement::MoveRight);

	//flashlight input
	//turn on/off
	PlayerInputComponent->BindAction("Torch", IE_Pressed, this, &ACharacterMovement::ToggleFlashLight);
}

void ACharacterMovement::MoveForward(float Axis)
{
	//get rotation
	FRotator Rotation = Controller->GetControlRotation();
	//get y axis
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	//calculate direction to axis x
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Axis);
}

void ACharacterMovement::MoveRight(float Axis)
{
	//get rotation
	FRotator Rotation = Controller->GetControlRotation();
	//get y axis
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	//calculate direction to axis y
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Axis);
}

void ACharacterMovement::TurnRate(float Rate)
{
	//set y speed rotation
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACharacterMovement::LookUpRate(float Rate)
{
	//set x speed rotation
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACharacterMovement::ToggleFlashLight()
{
	if (lightState)
	{
		lightState = false;
		FlashLight->SetVisibility(false, false);
	}
	else
	{
		lightState = true;
		FlashLight->SetVisibility(true, false);
	}
}

