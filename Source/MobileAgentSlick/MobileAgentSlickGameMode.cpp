// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "MobileAgentSlick.h"
#include "MobileAgentSlickGameMode.h"
#include "MobileAgentSlickPawn.h"

AMobileAgentSlickGameMode::AMobileAgentSlickGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AMobileAgentSlickPawn::StaticClass();
}

