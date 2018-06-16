// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"

#define ScreenMoveDelta 100;
// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	FVector NPos = GetActorLocation();
	NPos.Z = 1000;
	RootComponent->SetWorldLocation(NPos);

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Arm->SetupAttachment(RootComponent);
	Arm->TargetArmLength = 100;
	FRotator Ro(-60, 0, 0);
	Arm->RelativeRotation = Ro;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(Arm);
	//Camera->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
	
}




void ACameraPawn::Move_XAxis(float AxisValue)
{
	// ��ÿ��100��λ���ٶ���ǰ������ƶ�
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void ACameraPawn::Move_YAxis(float AxisValue)
{
	// ��ÿ��100��λ���ٶ����һ������ƶ�
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}
