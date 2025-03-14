// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;
UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloque();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	//malla del bloque
	UPROPERTY()
	UStaticMeshComponent* MeshBloque;
	// Es * eso es punturo
	UMaterialInterface* BloqueMaterial;

	UFUNCTION(BlueprintCallable)
	void AjustarTamano(FVector NuevoTamano);
	float FloatSpeed;
	float RotationSpeed;
	bool bPuedeMoverse;

private:
	FVector PosicionInicial;
	float AmplitudMovimiento = 100.0f; // Distancia máxima de movimiento
	float DireccionMovimiento = 1.0f; // 1 = hacia arriba, -1 = hacia abajo

};