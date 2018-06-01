// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "Camera/CameraComponent.h"

#define ScreenMoveDelta 100;
// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Arm->SetupAttachment(RootComponent);
	Arm->TargetArmLength = 1500;
	FRotator Ro(-70, 0, 0);
	Arm->RelativeRotation = Ro;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(Arm);
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

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ��ÿһ֡���������ƶ��������ֵ������Ӧ�����Ƿֱ���"MoveX"��"MoveY"��
	//InputComponent->BindAxis("MoveX", this, &ACameraPawn::Move_XAxis);
	//InputComponent->BindAxis("MoveY", this, &ACameraPawn::Move_YAxis);
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
