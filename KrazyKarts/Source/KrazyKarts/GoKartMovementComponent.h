// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"

USTRUCT()
struct FGoKartMove
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float Throttle;
	
	UPROPERTY()
	float SteeringThrow;
	
	UPROPERTY()
	float DeltaTime;

	UPROPERTY()
	float StartTime;

	bool IsValid() const
	{
		return FMath::Abs(Throttle) <= 1 && FMath::Abs(SteeringThrow) <= 1;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KRAZYKARTS_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SimulateMove(const FGoKartMove& Move);

	FVector GetVelocity() { return Velocity; }
	void SetVelocity(FVector NewVelocity) { Velocity = NewVelocity; }
	
	void SetThrottle(float NewThrottle) { Throttle = NewThrottle; }
	void SetSteeringThrow(float NewSteeringThrow) { SteeringThrow = NewSteeringThrow; }

	FGoKartMove GetLastMove() { return LastMove; }

private:
	FGoKartMove CreateMove(float DeltaTime);
	
	FVector GetAirResistance();
	FVector GetRollingResistance();
	
	void ApplyRotation(float DeltaTime, float MoveSteeringThrow);
	void UpdateLocationFromVelocity(float DeltaTime);

	// Mass of the car (kg)
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	// Force applied to the car when the throttle is fully down (N)
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// Minimum radius of the car turning circle ar full lock (m)
	UPROPERTY(EditAnywhere)
	float MinTurningRadius = 10;

	// Higher means more drag (Kg/m)
	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	// Higher means more rolling resistance (Kg/m)
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015;

	FVector Velocity;
	
	float Throttle;
	
	float SteeringThrow;

	FGoKartMove LastMove;
};
