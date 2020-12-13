// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObject.h"

// Sets default values
AInteractiveObject::AInteractiveObject()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	//mesh
	InteractiveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	InteractiveMesh->SetupAttachment(RootComponent);

	InteractiveCollision= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InteractiveCollision"));
	InteractiveCollision->SetupAttachment(RootComponent);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInteractiveObject::SetEnable(bool)
{

}

void AInteractiveObject::Interact()
{
	//if press F interact
}
