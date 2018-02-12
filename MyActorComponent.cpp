// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"
#include <string>

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;
	//When the object is constructed, Get the HTTP module
	Http = &FHttpModule::Get();
	
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	//MyHttpCall();
	Super::BeginPlay();

	// ...
	
}


/*Http call*/
FString UMyActorComponent::MyHttpCall(int userID, FString path)//int userID
{
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UMyActorComponent::OnResponseReceived);
	//This is the url on which to process the request
	FString url = "http://localhost/";
	url.Append(path);
	url.Append(FString::FromInt(userID));
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->ProcessRequest();
	//FString IntAsString = allText;//FString::FromInt(numberThing);
	return allText;
}

/*Assigned function on successfull http call*/
void UMyActorComponent::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		//Get the value of the json object by field name
		allText = JsonObject->GetStringField("customData");
		//Output it to the engine
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(recievedInt));
		//UE_LOG(LogTemp, Log, TEXT("The number is %d"), recievedInt);
		//numberThing = recievedInt;
	}
}
// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

