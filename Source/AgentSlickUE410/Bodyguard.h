// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bodyguard.generated.h"

UCLASS()
class AGENTSLICKUE410_API ABodyguard : public AActor
{
    GENERATED_BODY()
    
private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "True"))
    class UStaticMeshComponent* Mesh;
    
    FVector GetNextPosition();
    
    void MoveToPath();
    
    int CurrentPositionIndex;
    
    void DetectTarget();
    
public:
    // Sets default values for this actor's properties
    ABodyguard();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    UFUNCTION(BlueprintCallable, Category = Path)
    void MoveTo(FVector position);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Path)
    TArray<class AActor *> Path;
    
    /** True if the bodyguard should follow it's path and false if it should stay still */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Path)
    bool FollowPath;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Path)
    float Speed;
    
    /** Distance to consider the next point has reached */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Path)
    float MinDistanceToPoint;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting)
    class AActor* Target;
    
    /** Distance to which the bodyguard can see it's target */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting)
    float FieldOfViewDistance;
    
    /** Called when the target is spotted by the bodyguard */
    UFUNCTION(BlueprintNativeEvent, Category = Targeting)
    void OnTargetDetected();
};
