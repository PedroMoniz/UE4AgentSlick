// Fill out your copyright notice in the Description page of Project Settings.

#include "MobileAgentSlick.h"
#include "AgentSlickGameMode.h"
#include "AgentSlickPlayerController.h"
#include "SpriteCharacter.h"

AAgentSlickGameMode::AAgentSlickGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAgentSlickPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/AgentSlickCPP/Blueprints/AgentSlickCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}


