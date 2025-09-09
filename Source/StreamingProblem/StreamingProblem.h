// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldPartition/DataLayer/DataLayerManager.h"
#include "StreamingProblem.generated.h"

UCLASS(Abstract, Blueprintable)
class ASPFlushingActor : public AActor
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UDataLayerAsset> DataLayerToLoad;
};