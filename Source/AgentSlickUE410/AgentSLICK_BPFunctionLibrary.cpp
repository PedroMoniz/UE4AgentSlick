// Fill out your copyright notice in the Description page of Project Settings.

#include "AgentSlickUE410.h"
#include "AgentSLICK_BPFunctionLibrary.h"

FString UAgentSLICK_BPFunctionLibrary::GetCurrentMapReference(AActor * sourceActor)
{
    if (sourceActor == NULL)
    {
        return FString(TEXT("Must have a sourceActor (was NULL)"));
    }
    
    FString fullPath = sourceActor->GetWorld()->GetMapName();
    FString directoryPath = sourceActor->GetWorld()->StreamingLevelsPrefix;
    
    fullPath.ReplaceInline(*directoryPath, TEXT(""));
    return fullPath;
}