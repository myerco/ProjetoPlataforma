// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

APlataforma::APlataforma()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

}

void APlataforma::Tick(float DeltaTime)
{
	{
		Super::Tick(DeltaTime);

		if (ActiveTriggers > 0)
		{
			FVector Location = GetActorLocation();

			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += DeltaTime * SpeedPlataform * Direction;
			SetActorLocation(Location);
		}
	}
}

void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void APlataforma::AddActiveTrigger()
{
	ActiveTriggers++;
}

void APlataforma::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
