// Fill out your copyright notice in the Description page of Project Settings.

#include "E4FI.h"
#include "Engine.h"
#include "MyScreen.h"

#include <cstdlib>
#include <ctime>


// Sets default values
AMyScreen::AMyScreen(const class FObjectInitializer &PCIP) : Super(PCIP)
{

	
	// added
	m_width = 50;
	m_height = 50;


	VideoSurfaceMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("VideoSurfaceMesh"));
	RootComponent = VideoSurfaceMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>ShapePlaneMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	//static ConstructorHelpers::FObjectFinder<UMaterialInterface>ShapeVideoMaterial(TEXT("Material'/Game/StarterContent/Materials/VideoMaterial.VideoMaterial'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>ShapeVideoMaterial(TEXT("Material'/Game/StarterContent/Materials/VideoMaterial.VideoMaterial2'"));

	VideoSurfaceMesh->SetStaticMesh(ShapePlaneMesh.Object);
	VideoSurfaceMesh->SetMaterial(0, ShapeVideoMaterial.Object);


	//VideoSurfaceMesh = new UStaticMeshComponent();
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor called"));
	
	i = std::rand()%100 + 1;
	
}

void AMyScreen::InitWidthHeight(int w, int h)
{

	m_width = w;
	m_height = h;

	
}

// Called when the game starts or when spawned
void AMyScreen::BeginPlay()
{
	//EnableInput();
	//EnableInput(GetWorld()->GetAuthGameMode()->DefaultPawnClass.GetDefaultObject);
	

	UE_LOG(LogTemp, Warning, TEXT("Log LOG Kdevelop"));

	Super::BeginPlay();
	Log();

	UE_LOG(LogTemp, Warning, TEXT("Test Vector"));
	
	//VideoFrameData.Init(FColor::MakeRandomColor(), 100*100); 
	VideoFrameData.Init(FColor::MakeRandomColor(), getWidth()*getHeight());

	

	InitVideoMaterialTexture();
	SetLocationOnCylinder();

	//InputComponent->BindAction("test", IE_Pressed, this, &AMyScreen::MoveHorizontally);
	//MoveHorizontally();

}

// Called every frame
void AMyScreen::Tick( float DeltaTime )
{
	//Super::Tick( DeltaTime );
	UpdateVideoFrame();

	SetActorLocation(GetActorLocation()+ FVector(0.0,0.0,sinf(UGameplayStatics::GetRealTimeSeconds(GetWorld())+i)*0.2));



}

void AMyScreen::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//VideoSource->Close();
	UE_LOG(LogTemp, Warning, TEXT("End of MyScreen"));
}

void AMyScreen::MoveHorizontally()
{
	UE_LOG(LogTemp, Warning, TEXT("MoveMove"));
	//if (GetName() == "MyMyScreen7")	return;


	SetActorScale3D(GetActorScale3D() + FVector(1.08, 1.92, 0.0));
	UE_LOG(LogTemp, Warning, TEXT("Successful Input Mapping"));
}

void AMyScreen::ScaleY(float value)
{

	SetActorScale3D(GetActorScale3D() + FVector(0.0, value, 0.0));

}

void AMyScreen::SetLocationOnCylinder()
{

	int hauteurMax = 200;
	int hauteur = FMath::RandRange(0, hauteurMax);
	float angle = FMath::RandRange(0.0f, 3.14f);
	FVector BasePoint = FVector(0,0,100);
	float radius = 400;

	FVector newPosition = BasePoint + FVector(radius * FMath::Sin(angle), radius * FMath::Cos(angle),hauteur);
	
	UE_LOG(LogTemp, Warning, TEXT("Setting new Pos"));
                UE_LOG(LogTemp, Warning, TEXT("Welcome on Linux"));
	SetActorLocation(newPosition);
	//SetActorRotation(FVector(90.0f,0.0f,-90.0f*FMath::Cos(angle)));

	SetActorRotation(FRotator(90, 0, -90 * FMath::Cos(angle)));
}


void AMyScreen::Log()
{

	UE_LOG(LogTemp, Warning, TEXT("Log From MyScreen"));

}

bool AMyScreen::IsActive()
{

	return isActive;
}

void AMyScreen::SetActive(bool NewMyScreenState)
{

	isActive = NewMyScreenState;
}

void AMyScreen::ResizeUp()
{
	SetActorScale3D(GetActorScale3D() + FVector(1.08, 1.92, 0.0));
	UE_LOG(LogTemp, Warning, TEXT("Successful Resize Up"));
}

void AMyScreen::ResizeDown()
{
	SetActorScale3D(GetActorScale3D() - FVector(1.08, 1.92, 0.0));
	UE_LOG(LogTemp, Warning, TEXT("Successful Resize Down"));
}



void AMyScreen::UpdateVideoFrame()
{
	uint8* DestinationImageBuffer = (uint8*)VideoFrameData.GetData();

	//VideoSource->GetFrameImage(DestinationImageBuffer);
	GetFrameImage(DestinationImageBuffer);

	UpdateTextureRegions(VideoTexture, (int32)0, (uint32)1, VideoTextureRegion, (uint32)(4 * getWidth()), (uint32)4, DestinationImageBuffer, false);
	//UpdateTextureRegions(VideoTexture, (int32)0, (uint32)1, VideoTextureRegion, (uint32)(4 * 100), (uint32)4, DestinationImageBuffer, false);

}

void AMyScreen::UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData)
{
	
	if (Texture && Texture->Resource)
	{

		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			uint32 NumRegions;
			FUpdateTextureRegion2D* Regions;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};
		
		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
		RegionData->MipIndex = MipIndex;
		RegionData->NumRegions = NumRegions;
		RegionData->Regions = Regions;
		RegionData->SrcPitch = SrcPitch;
		RegionData->SrcBpp = SrcBpp;
		RegionData->SrcData = SrcData;
		//UE_LOG(LogTemp, Warning, TEXT("We Came this far"));
		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
			UpdateTextureRegionsData,
			FUpdateTextureRegionsData*, RegionData, RegionData,
			bool, bFreeData, bFreeData,
			{
				for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
				{
					int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
					if (RegionData->MipIndex >= CurrentFirstMip)
					{
						RHIUpdateTexture2D(
							RegionData->Texture2DResource->GetTexture2DRHI(),
							RegionData->MipIndex - CurrentFirstMip,
							RegionData->Regions[RegionIndex],
							RegionData->SrcPitch,
							RegionData->SrcData
							+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
							+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
						);
					}
				}
		if (bFreeData)
		{
			FMemory::Free(RegionData->Regions);
			FMemory::Free(RegionData->SrcData);
		}
		delete RegionData;

			});

		//UE_LOG(LogTemp, Warning, TEXT("And this far"));

	}

	//else
	//	UE_LOG(LogTemp, Warning, TEXT("Issue Texture"));

}


void AMyScreen::InitVideoMaterialTexture()
{
	// First find the dynamic material
	TArray<UPrimitiveComponent*> Primitives;
	this->GetComponents<UPrimitiveComponent>(Primitives);
	uint16 PrimitivesCount = Primitives.Num();
	for (uint16 i = 0; i != PrimitivesCount; ++i)
	{
		UPrimitiveComponent* Primitive = Primitives[i];
		uint16 MaterialsCount = Primitive->GetNumMaterials();
		for (uint16 m = 0; m != MaterialsCount; ++m)
		{
			UMaterialInterface* Material = Primitive->GetMaterial(m);
			UTexture* Texture = nullptr;
			if (!Material)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Reach Material"));
				continue;
			}

			if (Material->GetTextureParameterValue("VideoTexture", Texture))
			{
				UMaterialInstanceDynamic* DynamicMaterialInstance = Cast<UMaterialInstanceDynamic>(Material);
				if (!DynamicMaterialInstance)
				{
					DynamicMaterialInstance = UMaterialInstanceDynamic::Create(Material, Primitive);
					Primitive->SetMaterial(m, DynamicMaterialInstance);
				}
				VideoMaterial = DynamicMaterialInstance;
				// now that we have dynamic video material, create transient texture to draw video to, and set the material VideoTexture parameter
				//VideoTexture = UTexture2D::CreateTransient(100, 100); // Pour l'instannt 100*100, à l'avenir -> 
				VideoTexture = UTexture2D::CreateTransient(getWidth(), getHeight());
				VideoTexture->UpdateResource();
				VideoMaterial->SetTextureParameterValue(FName("VideoTexture"), VideoTexture);
				//VideoTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, 100, 100); 
				//to change with  
				VideoTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, getWidth(), getHeight()); 
				break;
			}

			else
				UE_LOG(LogTemp, Warning, TEXT("Cannot Reach VideoTexture"));
		}
	}
}

void AMyScreen::GetFrameImage(uint8* DestinationImageBuffer)
{
	//UE_LOG(LogTemp, Warning, TEXT("Getting Frame Image"));


	int Width = getWidth();
	int Height = getHeight();
	uint8* DestinationPointer = NULL;
	uint8* SourcePointer = NULL;



	bool CameraUpsideDown = true;
	if (true) {

		DestinationPointer = DestinationImageBuffer;
		for (int32 x = 0; x < Width; x++)
		{
			for (int32 y = 0; y < Height; y++)
			{
				if (x < Width/2 && y < Height)
				{
					*DestinationPointer++ = 0;
					*DestinationPointer++ = 0;
					*DestinationPointer++ = 255;
					*DestinationPointer++ = 0xFF;

				}

				else {
					*DestinationPointer++ = 255;
					*DestinationPointer++ = 0;
					*DestinationPointer++ = 0;
					*DestinationPointer++ = 0xFF;

				}


			}
		}

	}
	//i=(i+1)%100;
	
	}
