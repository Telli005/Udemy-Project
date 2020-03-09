#include <iostream> 
#include <ctime>



void PrintIntroduction(int Difficulty)
{
    // Setting Ambiance
    std::cout << Difficulty;
    std::cout << "You are a secret agent breaking into a secure server room...\n";
    std::cout << "The coast is clear and you approach the heavy metal door.\n";
    std::cout << "Next to the door is a terminal with a keypad.\n";
    std::cout << "On the terminal screen it says, 'Enter Secure PIN for Entry'.\n";
    std::cout << "You wave your watch over the terminal, you hear the AI in your ear,\n";
    std::cout << "'There are three numbers in the code, they multiply to \n"; 
    std::cout << CodeProduct;
    std::cout << " and add up to "; 
    std::cout << CodeSum;
    std::cout << ". Enter the three numbers followed by x...'\n";
}


bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

     //Initialized Preset Code
    int CodeA = rand() % (5 * Difficulty) +1;
    int CodeB = rand() % (5 * Difficulty) +1;
    int CodeC = rand() % (5 * Difficulty) +1;

    //Use these variables to determine answer
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    int GuessA, GuessB, GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    
    
    
    //Storing Player Guess
    std::cin >> GuessA >> GuessB >> GuessC;
    //Win Condition
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You hear a beep from the terminal and the sound of pressure being released, like a refridgerator. The door swings open slowly, and you walk inside."
        return ++Difficulty;
    }

    else
    {
        std::cout << "A loud alarm begins to sound, and red lights flash from what seems like everywhere. You are Doomed."
        return Difficulty;
    }
}



int main()
{
    srand(time(NULL));// create new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty)//Loop game until all lvls are completed
    {
        bool bLevelComplete = PlayGame();
        PlayGame(LevelDifficulty);
        std::cin.clear();//clears any errors
        std::cin.ignore();//discards the buffer

        if(bLevelComplete) 
        {
            //increment lvl difficulty
            ++LevelDifficulty;
        }
    }
    
    return 0;
}