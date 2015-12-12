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

USTRUCT(BlueprintType)
struct FGuardChat : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Guard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Greet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Distraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Danswer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		int32 Dtype;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Joke;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Janswer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		int32 Jtype;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Charm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Canswer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		int32 Ctype;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Story;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		FText Sanswer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting System")
		int32 Stype;
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
