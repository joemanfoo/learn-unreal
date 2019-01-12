#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

class FBullCowGame {
  public:
    FBullCowGame(); // constructor

    void Reset(); // TODO make a more rich returh value
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckGuessValidity(FString);
    // counts bulls and cows, and increasing try # assuming valid guess
    FBullCowCount SubmitGuess(FString);

  private:
    // see constructor for initialization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};