// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Utilities_BPFunction.generated.h"

/**
 * A library of helpful functions and data structures.
 */

USTRUCT(BlueprintType)
struct FItemInformation : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Information System")
	FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Information System")
	FText ItemDescription;

};

UCLASS()
class AGENTSLICKUE4_API UUtilities_BPFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};
