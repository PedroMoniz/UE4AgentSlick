// Fill out your copyright notice in the Description page of Project Settings.

#include "AgentSlickUE410.h"
#include "Bodyguard.h"


// Sets default values
ABodyguard::ABodyguard()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    
    FollowPath = true;
    Speed = 10.0f;
    MinDistanceToPoint = 50.0f;
    
    FieldOfViewDistance = 200.0f;
}

// Called when the game starts or when spawned
void ABodyguard::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABodyguard::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    
    DetectTarget();
    
    if (FollowPath) {
        MoveToPath();
    }
}

FVector ABodyguard::GetNextPosition()
{
    if (Path.Num() > 0) {
        if (Path[CurrentPositionIndex] != nullptr
            && FVector::DistSquared(Path[CurrentPositionIndex]->GetActorLocation(), GetActorLocation()) < MinDistanceToPoint * MinDistanceToPoint)
        {
            CurrentPositionIndex = (CurrentPositionIndex + 1) % Path.Num();
        }
        
        if (Path[CurrentPositionIndex] != nullptr)
        {
            return Path[CurrentPositionIndex]->GetActorLocation();
        }
    }
    return GetActorLocation();
}

void ABodyguard::MoveToPath()
{
    MoveTo(GetNextPosition());
}

void ABodyguard::MoveTo(FVector location)
{
    FVector direction = (location - GetActorLocation()).GetSafeNormal();
    direction *= Speed;
    
    SetActorLocationAndRotation(GetActorLocation() + direction, direction.Rotation());
}

void ABodyguard::DetectTarget()
{
    if (Target != nullptr
        && FVector::DistSquared(Target->GetActorLocation(), GetActorLocation()) < FieldOfViewDistance * FieldOfViewDistance ) {
        OnTargetDetected();
    }
}

void ABodyguard::OnTargetDetected_Implementation()
{
    
}