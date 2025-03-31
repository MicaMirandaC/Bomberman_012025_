// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"


// Sets default values
ABloque::ABloque()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Para la creacion de la malla 
	MeshBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloque"));
	MeshBloque->SetupAttachment(RootComponent);

	//static  solo pude existir una sola vez en una clase, se define un objeto estatico
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if (ObjetoMeshBloque.Succeeded())
	{
		MeshBloque->SetStaticMesh(ObjetoMeshBloque.Object);

		MeshBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Panel.M_Tech_Panel'"));
	if (ObjetoBloqueMaterial.Succeeded())
	{
		MeshBloque->SetMaterial(0, ObjetoBloqueMaterial.Object);

	}

	// Inicializar variables para la velocidad y la rotacion del bloque 
	FloatSpeed = 5.0f;
	RotationSpeed = 3.0f;

	// Inicializar variables para el movimiento del bloque
	bPuedeMoverse = FMath::RandBool();
	// Establecer el tamaño inicial del bloque
	AjustarTamano(FVector(2.8f, 2.8f, 2.8f));
}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//para el movimiento
	if (bPuedeMoverse)
	{
		//para el movimiento de arriba abajo
		FVector NewLocation = GetActorLocation();
		NewLocation.Z += DireccionMovimiento * FloatSpeed;

		if (FMath::Abs(NewLocation.Z - PosicionInicial.Z) >= AmplitudMovimiento)
		{
			DireccionMovimiento *= -1; // Invertir dirección al alcanzar el límite
		}

		SetActorLocation(NewLocation);
	}
}

void ABloque::AjustarTamano(FVector NuevoTamano)
{
	MeshBloque->SetWorldScale3D(NuevoTamano);
}