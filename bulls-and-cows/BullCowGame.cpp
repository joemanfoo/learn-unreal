#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

// passed a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
  // incriment turn number
  MyCurrentTry++;
  
  // setup return variable
  FBullCowCount BullCowCount;

  // loop through all letters in the guess
  int32 HiddenWordLength = MyHiddenWord.length();
  int32 GuessLength = Guess.length();

  for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
  {
    // compare letters against the hidden word
    for (int32 GChar = 0; GChar < GuessLength; GChar++)
    {
      if (MyHiddenWord[MHWChar] == Guess[GChar]) {
        // if they're in the same place
        if (MHWChar == GChar) {
          BullCowCount.Bulls++;
        } else {
          BullCowCount.Cows++;
        }
      } else {
        // the guess letter isn't in the hidden word...
      }
    }
  }
  return BullCowCount;
}
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 8;
  MyMaxTries = MAX_TRIES;

  const FString HIDDEN_WORD = "planet";
  MyHiddenWord = HIDDEN_WORD;

  MyCurrentTry = 1;
  return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
  return false;
}