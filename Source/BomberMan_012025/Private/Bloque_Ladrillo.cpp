// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Bloque_Ladrillo.h"


// Sets default values
ABloque_Ladrillo::ABloque_Ladrillo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshBloque_Ladrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloque_Ladrillo"));
	MeshBloque_Ladrillo->SetupAttachment(RootComponent);

	//static  solo pude existir una sola vez en una clase, se define un objeto estatico
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloque_Ladrillo(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloque_Ladrillo.Succeeded())
	{
		MeshBloque_Ladrillo->SetStaticMesh(ObjetoMeshBloque_Ladrillo.Object);

		MeshBloque_Ladrillo->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloque_LadrilloMaterial(TEXT("/Script/Engine.Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Old_D.T_Brick_Clay_Old_D'"));
	if (ObjetoBloque_LadrilloMaterial.Succeeded())
	{
		MeshBloque_Ladrillo->SetMaterial(0, ObjetoBloque_LadrilloMaterial.Object);

	}

	velocidad = 0.5f;
	amplitud = 50.0f;
	AjustarTamanoAcero(FVector(2.0f, 2.0f, 2.0f)); // Tamaño por defecto
}

// Called when the game starts or when spawned
void ABloque_Ladrillo::BeginPlay()
{
	Super::BeginPlay();
	// Guardar la posición inicial en el eje Z
	PosicionInicial = GetActorLocation().Z;

}

// Called every frame
void ABloque_Ladrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calcular la nueva posición en el eje Z
	FVector NewLocation = GetActorLocation();
	float Tiempo = GetWorld()->GetTimeSeconds(); // Tiempo actual del juego

	// Movimiento oscilatorio en el eje Z (arriba y abajo)
	NewLocation.Z = PosicionInicial + FMath::Sin(Tiempo * velocidad) * amplitud;

	// Actualizar la posición del actor
	SetActorLocation(NewLocation);
}

void ABloque_Ladrillo::AjustarTamanoAcero(FVector NuevoTamano)
{
	MeshBloque_Ladrillo->SetWorldScale3D(NuevoTamano);
}