// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AgentSLICK_BPFunctionLibrary.generated.h"

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
class AGENTSLICKUE410_API UAgentSLICK_BPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    /** Get the currently loaded map reference name.   You have to have a sourceActor because multiple maps can be loaded/loading.
     * Typical return string is like "UIEPED_0_MyMapName" in the editor or "MyMapName" if in a stand-alone game.
     */
    UFUNCTION(BlueprintPure, Category = TDLHelpers)
    static FString GetCurrentMapReference(AActor * sourceActor);
    
};
