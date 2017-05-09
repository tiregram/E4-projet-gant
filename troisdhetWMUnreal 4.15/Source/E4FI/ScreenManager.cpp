// Fill out your copyright notice in the Description page of Project Settings.

#include "E4FI.h"
#include "ScreenManager.h"


// Sets default values
AScreenManager::AScreenManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScreenManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScreenManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScreenManager::init(int nbScreen)
{
  
  UE_LOG(LogTemp, Warning, TEXT("Bonjour Bonjour je suis screenManager, nb ecrans : %d"),nbScreen);

}


