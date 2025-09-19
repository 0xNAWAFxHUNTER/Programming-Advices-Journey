
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;



enum enGame { Stone = 1, Paper = 2, Scissor = 3 };

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}

enGame Machine() {

    short Number = RandomNumber(1, 3);
    switch (Number) {

    case 1:
        return enGame::Stone;

    case 2:
        return enGame::Paper;

    case 3:
        return enGame::Scissor;
    }
}
enGame User() {

    short Number;
    do
    {
        cin >> Number;
        switch (Number) {

        case 1:
            return enGame::Stone;

        case 2:
            return enGame::Paper;

        case 3:
            return enGame::Scissor;
        }
    } while (Number == 1 || Number == 2 || Number == 3);
}

string Winning(enGame User, enGame Machine) {

    if (User == Machine)
        return "[No Winner]";


    if (User == enGame::Stone && Machine == enGame::Paper)
        return "User";
    if (User == enGame::Stone && Machine == enGame::Scissor)
        return "Machine";

    if (User == enGame::Paper && Machine == enGame::Stone)
        return "User";
    if (User == enGame::Paper && Machine == enGame::Scissor)
        return "Machine";

    if (User == enGame::Scissor && Machine == enGame::Paper)
        return "User";
    if (User == enGame::Scissor && Machine == enGame::Stone)
        return "Machine";
}

string FinalWinner(short UserWinTimes, short MachineWinTimes) {

    if (UserWinTimes == MachineWinTimes)
        return "No Winner";
    else if (UserWinTimes < MachineWinTimes)
        return "User won";
    else
        return "Machine won";
}

short NumberOfReptitions() {

    short Number;

    cout << "How many rounds (1 to 10) ? ";
    cin >> Number;

    return Number;
}

void StoreResults(string Winner, short& UserWinTimes, short& MachineWinTimes, short& DrawTimes) {

    if (Winner == "Machine")
        MachineWinTimes++;
    else if (Winner == "User")
        UserWinTimes++;
    else
        DrawTimes++;
}

void ViewGameResults(short NumberOfRounds, short UserWinTimes,short MachineWinTimes,short DrawTimes) {

    cout << "\n\n\n";
    cout << "    ____________________________________________";
    cout << "\n             +++ G a m e   O v e r +++\n";
    cout << "    ____________________________________________";
                   
    cout << "\n    ______________[Game Results]________________";
    cout << "\n    Game Rounds        :" << NumberOfRounds;
    cout << "\n    User won times     :" << UserWinTimes;
    cout << "\n    Machine won times  :" << MachineWinTimes;
    cout << "\n    Draw times         :" << DrawTimes;
    cout << "\n    Final winner       :" << FinalWinner(UserWinTimes, MachineWinTimes);
    cout << "\n    ___________________________________________";

}

void StartGame() {
    
    enGame UserChoice;
    enGame MachineChoice;
    string Winner;

    short NumberOfRounds = NumberOfReptitions();
    short UserWinTimes = 0;
    short MachineWinTimes = 0;
    short DrawTimes = 0;

    char RepeatGame;
    do {

        for (short Count = 1; Count <= NumberOfRounds; Count++)
        {
            cout << "\n\n\n\nRound [" << Count << "] begins: " << endl;

            cout << "Your choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
            UserChoice = User();
            MachineChoice = Machine();
            Winner = Winning(UserChoice, MachineChoice);

            cout << "\n____________Round [" << Count << "]_____________\n";
            cout << "\nUser Choice: " << UserChoice;
            cout << "\nMachine Choice: " << MachineChoice;
            cout << "\nRound Winner   : " << Winner;
            cout << "\n________________________________________";

            StoreResults(Winner ,UserWinTimes, MachineWinTimes, DrawTimes);
        }
        ViewGameResults(NumberOfRounds, UserWinTimes, MachineWinTimes, DrawTimes);
        
        cout << "\n\n    Do you want to play again? (Y/N): ";
        cin >> RepeatGame;
    } while (toupper(RepeatGame) == 'Y');
}


//--------------------------------------------------------------------Main---------------------------------------------------------------------------------------------------


int main()
{
    cout << "\n\n\n";
    srand((unsigned)time(NULL));



    StartGame();



    system("pause");
    cout << "\n\n\n";
}
