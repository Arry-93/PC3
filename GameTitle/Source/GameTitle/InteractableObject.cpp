// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableObject.h"

// Sets default values
AInteractableObject::AInteractableObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->bHiddenInGame = false;

	bUseControllerRotationYaw = false;
}

// Called to bind functionality to input
void AInteractableObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//mouse horizontal movement control y axis
	PlayerInputComponent->BindAxis("Vertical", this, &AInteractableObject::HorizontalRotation);
	//mouse vertical movement control x axis
	PlayerInputComponent->BindAxis("Horizontal", this, &AInteractableObject::VerticalRotation);
}

void AInteractableObject::HorizontalRotation(float value)
{
	if(value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void AInteractableObject::VerticalRotation(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(value, 0, 0));
	}
}

