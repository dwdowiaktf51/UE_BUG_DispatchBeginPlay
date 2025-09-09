// Copyright Epic Games, Inc. All Rights Reserved.

#include "StreamingProblem.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, StreamingProblem, "StreamingProblem" );

void ASPFlushingActor::BeginPlay()
{
	Super::BeginPlay();

	if (UWorld* const World = GetWorld())
	{
		UDataLayerManager* DataLayerManager = World->GetDataLayerManager();
		if (DataLayerManager && DataLayerToLoad)
		{
			DataLayerManager->SetDataLayerRuntimeState(DataLayerToLoad, EDataLayerRuntimeState::Activated);
		}

		World->BlockTillLevelStreamingCompleted();
	}
}