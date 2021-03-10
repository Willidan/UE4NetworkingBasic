// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InteractableComponent.h"
#include "GameFramework/Actor.h"
#include "JumpingNetActor.generated.h"

UCLASS()
class BASICNETWORKING_API AJumpingNetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpingNetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ActorMesh;

	UPROPERTY()
	UInteractableComponent* Interactable;

	UFUNCTION()
	void OnInteract();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Jump();
};
