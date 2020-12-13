// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterMovement.h"
#include "Components/BoxComponent.h"
#include "InteractiveObject.generated.h"

UCLASS()
class GAMETITLE_API AInteractiveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveObject();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive")
		USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive")
		UStaticMeshComponent* InteractiveMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive")
		UBoxComponent* InteractiveCollision;

public:
	ACharacterMovement* CurrentCharacter;

	bool CanLookAt = false;
	void Interact();
	void SetEnable(bool);

};
