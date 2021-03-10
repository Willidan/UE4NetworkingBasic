// Copyright Epic Games, Inc. All Rights Reserved.

#include "BasicNetworkingGameMode.h"
#include "BasicNetworkingCharacter.h"
#include "NetworkingPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ABasicNetworkingGameMode::ABasicNetworkingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = ANetworkingPlayerController::StaticClass();
}
