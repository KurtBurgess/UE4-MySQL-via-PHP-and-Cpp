// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Runtime/Json/Public/Json.h"
#include "MyActorComponent.generated.h"
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARSBRIDGE_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyActorComponent();

	FHttpModule* Http;

	UFUNCTION(BlueprintCallable, Category = "System Information")
		FString MyHttpCall(int userID, FString path);//int userID

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	// Sets default values for this actor's properties
	UMyActorComponent(const class FObjectInitializer& ObjectInitializer);

	FString allText;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
