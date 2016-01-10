// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "AgentSlickPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOBILEAGENTSLICK_API AAgentSlickPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAgentSlickPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bMoveEnabled = true;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);
protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);


	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};
