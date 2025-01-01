#include "Items/Item.h"
#include "Slas/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/SlashCharacter.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshomponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverLap);
}

float AItem::SinTransform()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::CosTransform(float value)
{
	return Amplitude * FMath::Cos(value * TimeConstant);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverLappingItem(this);
	}
}

void AItem::OnSphereEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverLappingItem(nullptr);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;
	if (ItemState == EItemState::EIS_Hovering)
	{
		AddActorWorldOffset(FVector(0.f, 0.f, SinTransform()));
	}
}

