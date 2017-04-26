// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProcessPickup.generated.h"

UCLASS()
class E4FI_API AProcessPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcessPickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Material Accessor
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return ProcessPickupMesh; };

	UFUNCTION(BlueprintPure, Category="ProcessPickup")
		bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "ProcessPickup")
		void SetActive(bool newPickupState);

protected:

	bool bIsActive;

	
private:
	//Static Mesh 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ProcessPickup", meta = (AllowPrivateAccess="true"))
	class UStaticMeshComponent* ProcessPickupMesh;
	
};
