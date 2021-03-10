// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkingPlayerController.h"

#include "BasicNetworkingCharacter.h"

void ANetworkingPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Interact with actors
	InputComponent->BindAction("Interact", IE_Released, this, &ANetworkingPlayerController::Server_Interact);
}

void ANetworkingPlayerController::Server_Interact_Implementation()
{
	ABasicNetworkingCharacter* PlayerCharacter = Cast<ABasicNetworkingCharacter>(GetCharacter());

	if(PlayerCharacter)
	{
		PlayerCharacter->Interact();
	}
}

bool ANetworkingPlayerController::Server_Interact_Validate()
{
	return true;
}
