// Fill out your copyright notice in the Description page of Project Settings.

#include "AgentSlickUE410.h"
#include "Bodyguard.h"

// Sets default values
ABodyguard::ABodyguard()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
    RootComponent = Mesh;
    
    FollowPath = true;
    Speed = 20.f;
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
    
    if (TargetLocationSet) {
        if (FVector::DistSquared(TargetLocation, GetActorLocation()) < MinDistanceToPoint * MinDistanceToPoint) {
            TargetLocationSet = false;
        }
        MoveTo(TargetLocation, DeltaTime);
    } else
    {
        if (FollowPath) {
            MoveToPath(DeltaTime);
        }
    }
}

void ABodyguard::GoToLocation(FVector location)
{
    TargetLocation = location;
    TargetLocationSet = true;
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

void ABodyguard::MoveToPath(float DeltaTime)
{
    FVector position = GetNextPosition();
    if (position != GetActorLocation()) {
        MoveTo(position, DeltaTime);
    }
}

void ABodyguard::MoveTo(FVector location, float DeltaTime)
{
    const FVector direction = (location - GetActorLocation()).GetSafeNormal2D().GetClampedToMaxSize(1.0f) * Speed * DeltaTime;
    DrawDebugPoint(
                   GetWorld(),
                   GetActorLocation() + direction,
                   10,  					//size
                   FColor(255,0,255)  //pink
                   );
    //    DrawDebugLine(
    //                  GetWorld(),
    //                  GetActorLocation(),
    //                  GetActorLocation() + direction,
    //                  FColor(255,0,0),
    //                  false, -1, 0,
    //                  12.333
    //                  );
    // If non-zero size, move this actor
    if (direction.SizeSquared() > 0.0f)
    {
        SetActorLocationAndRotation(GetActorLocation() + direction, direction.Rotation());
    }
}

float GetAngleBetween(FVector vector1, FVector vector2)
{
    return FMath::RadiansToDegrees(acosf(FVector::DotProduct(vector1, vector2)));
}

void ABodyguard::DetectTarget()
{
    DrawDebugSphere(
                    GetWorld(),
                    GetActorLocation(),
                    FieldOfViewDistance,
                    32,
                    FColor(255,0,0)
                    );
    
    //float deltaAngle = GetAngleBetween(GetActorForwardVector(), Target->GetActorLocation());
    if (Target != nullptr)
    {
        if(FVector::DistSquared(Target->GetActorLocation(), GetActorLocation()) < FieldOfViewDistance * FieldOfViewDistance )
        {
            OnTargetDetected();
        }
    }
}

void ABodyguard::OnTargetDetected_Implementation()
{
    
}