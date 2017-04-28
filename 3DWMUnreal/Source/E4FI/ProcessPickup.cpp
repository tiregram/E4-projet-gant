// Fill out your copyright notice in the Description page of Project Settings.

#include "E4FI.h"
#include "ProcessPickup.h"


// Sets default values
AProcessPickup::AProcessPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bIsActive = true;

	ProcessPickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProcessPickupMesh"));
	RootComponent = ProcessPickupMesh;

}


bool AProcessPickup::IsActive()
{
	return bIsActive;
}

void AProcessPickup::SetActive(bool newPickupState)
{
	bIsActive = newPickupState;
}

// Called when the game starts or when spawned
void AProcessPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProcessPickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

