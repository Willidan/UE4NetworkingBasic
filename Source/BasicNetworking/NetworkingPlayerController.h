// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetworkingPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BASICNETWORKING_API ANetworkingPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:
	virtual void SetupInputComponent() override;

	UFUNCTION(Server, Reliable, WithValidation)
    void Server_Interact();
};
