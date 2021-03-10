#pragma once
#include "Engine/GameEngine.h"

//Prints debug message for 5 sec. with optional parameters in Yellow
#define DM_Y(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(x), __VA_ARGS__));}
//Prints debug message for 5 sec. with optional parameters in Red
#define DM_R(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT(x), __VA_ARGS__));}
//Prints debug message for 5 sec. with optional parameters in Blue
#define DM_B(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT(x), __VA_ARGS__));}
//Prints debug message for 5 sec. with optional parameters in Green
#define DM_G(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT(x), __VA_ARGS__));}