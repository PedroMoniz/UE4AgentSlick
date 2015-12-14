// Fill out your copyright notice in the Description page of Project Settings.

#include "AgentSlickUE410.h"
#include "AgentSlickPawn.h"
#include "TimerManager.h"

const FName AAgentSlickPawn::MoveForwardBinding("MoveForward");
const FName AAgentSlickPawn::MoveRightBinding("MoveRight");
const FName AAgentSlickPawn::WalkSlowBinding("WalkSlow-KeyPressed");



AAgentSlickPawn::AAgentSlickPawn()
{
	// Create the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	RootComponent = MeshComponent;
	MeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->RelativeRotation = FRotator(-80.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

										  // Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

														// Movement
	MoveSpeed = 1000.0f;
	
}

void AAgentSlickPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	// set up gameplay key bindings
	InputComponent->BindAxis(MoveForwardBinding);
	InputComponent->BindAxis(MoveRightBinding);
	InputComponent->BindAction(WalkSlowBinding, IE_Pressed, this, &AAgentSlickPawn::WalkSlowlyPressed);
	InputComponent->BindAction(WalkSlowBinding, IE_Released, this, &AAgentSlickPawn::WalkSlowlyReleased);
}

void AAgentSlickPawn::WalkSlowlyPressed() {
	MoveSpeed = 500.0f;

}


void AAgentSlickPawn::WalkSlowlyReleased() {
	MoveSpeed = 1000.0f;
}

void AAgentSlickPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);
	//find if walking slowly

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

}
