// Fill out your copyright notice in the Description page of Project Settings.

#include "ArmyUnit.h"
#define AttackState 0
//might define or enum


AArmyUnit::AArmyUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AArmyUnit::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AArmyUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentState == AttackState) {//1 stands for attacking state
		AttackTarget->ReceivedTotalDamage += DeltaTime*Damage;
	}
}


void AArmyUnit::MoveTo(float x, float y)
{

}

void AArmyUnit::Attack(ARedAlertObjectBase *Target)
{

}