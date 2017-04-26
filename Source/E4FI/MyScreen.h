// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine.h"
#include "MyScreen.generated.h"

UCLASS()
class E4FI_API AMyScreen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyScreen(const class FObjectInitializer &PCIP);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void Log();

	UFUNCTION(BlueprintPure, Category = "MyScreen")
		bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void SetActive(bool NewMyScreenState);

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void MoveHorizontally();

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void ResizeUp();

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void ResizeDown();

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void ScaleY(float value);

	UFUNCTION(BlueprintCallable, Category = "MyScreen")
		void SetLocationOnCylinder();
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = AugmentedReality)
		UStaticMeshComponent* VideoSurfaceMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AugmentedReality)
		FVector test;


protected:

	bool isActive;

	UFUNCTION(BlueprintCallable, Category = AugmentedReality)
		void UpdateVideoFrame();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AugmentedReality)
		UTexture2D* VideoTexture;

	UPROPERTY()
		TArray<FColor> VideoFrameData;

	FUpdateTextureRegion2D *VideoTextureRegion;

	UMaterialInstanceDynamic *VideoMaterial;

	int i;// used for debug 

	int m_width, m_height;

	FORCEINLINE int getWidth() const { return m_width; }
	FORCEINLINE int getHeight() const { return m_height; }

	void GetFrameImage(uint8* DestinationImageBuffer);

	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);

	void InitVideoMaterialTexture();

	void InitWidthHeight(int w, int h);

	void EndPlay(const EEndPlayReason::Type EndPlayReason);


};


//TODO
//Try to have a fixed ratio between the image input and the scale of the plane
