// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueMadera.generated.h"

class UStaticMeshComponent;


UCLASS()
class BOMBERMAN_012025_API ABloqueMadera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloqueMadera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	UPROPERTY()
	UStaticMeshComponent* MeshBloqueMadera;

	bool bAbriendo;
	float VelocidadMovimiento;
	float DistanciaApertura; // Distancia máxima al abrir
	FVector PosicionInicial; // Posición inicial


	UFUNCTION(BlueprintCallable)
	void AjustarTamanoMadera(FVector NuevoTamano);
};