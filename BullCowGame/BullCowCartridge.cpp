// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"





void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(FString::Printf(TEXT("The PassCode is: %s, and %i digits long"), *HiddenWord, HiddenWord.Len()));//DEBUG Line   
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    //if game is over, clear screen and SetupGame();
    //else check PlayerGuess
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else//Checking the Players Guess
    {
        ProcessGuess(Input);
        

    }   
    
} 

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake");
    ChancesRemaining = 3;
    bGameOver = false;

    PrintLine(TEXT("You approach the next door. It is sealed shut, with a keypad next to it."));
    PrintLine(TEXT("Input the %i digit Password, and press Enter."), HiddenWord.Len());

    const TCHAR HW[] = TEXT("cake");
    PrintLine(TEXT("Character 1 of the hidden word i s: %c"), HiddenWord[0]);//prints c
    PrintLine(TEXT("The 4th character fo the hidden word is :%c"), HiddenWord[3]);
    
    
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again"));
}

void UBullCowCartridge:: ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
        {
            PrintLine(TEXT("CORRECT, PROCEED"));
            EndGame();
            return;
        }
    if(ChancesRemaining > 0)
    {
        PrintLine(TEXT("Lost a life!"));
        PrintLine(TEXT("%i lives remaining"), --ChancesRemaining); 
        if (Guess.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("Wrong number of letters, guess again."));
            return;
        }
        if (!IsIsogram(Guess))
        {
            PrintLine(TEXT("No repeating letters, guess again."));
            return;
        }
    }

}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index +1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }
    //for (int32 Index = 0; Index < Word.Len(); Index++)
    //{
    //    PrintLine(TEXT("%c"), Word[Index]);
    //}
    //start at element {0}
    //check
    //Until we reach {Guess.Len -1}

    return true;
}

//Start Game
//Welcome Message
//Set the PassCode
//Prompt the Player for Input
//Recieve Input
//Test Input vs Passcode *and Incorrect Inputs
//Win conditions or Lose conditions