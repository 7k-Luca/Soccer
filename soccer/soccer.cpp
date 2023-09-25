#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int starterMenu();
void getTeamData();
void displayTeamRoster();
void calcTeamGoals();
void displayTeamStars();

// Player Structure
struct Player {
    string name;
    int number;
    int goals;
    // constructor 
    Player() {
        name = "";
        number = 0;
        goals = 0;
    }
    // Constructor to initialize details of a single player
    Player(string n, int num, int g) {
        name = n;
        number = num;
        goals = g;
    }
    };

// Array of structures
Player team[11];

int main()
{
    int num;
    // Do-while statement
    do
    {
        cout << "\nSoccer Team Goals ..." << endl << endl;
        num = starterMenu();


        switch (num) {
        case 1:
            // calling getTeamData()
            getTeamData();
            break;
        case 2:
            // calling displayTeamRoster()
            displayTeamRoster();
            break;
        case 3:
            // calling calcTeamGoals()
            calcTeamGoals();
            break;
        case 4:
            // calling displayTeamStars()
            displayTeamStars();
            break;
        case 5:
            cout << "GoodBye";
            break;

        };

    } while (num != 5);
}

// Displays the choices for user
int starterMenu() {
    int choice;
    cout << "Choose one of the following options: " << endl;
    cout << "\t1. Load Team's information." << endl;
    cout << "\t2. Display team's roster." << endl;
    cout << "\t3. Display team's goals." << endl;
    cout << "\t4. Display team's star(s)." << endl;
    cout << "\t5. Quit." << endl;
    cout << "Option: ";
    cin >> choice;

    // Ensuring numbers between 1 and 5 are chosen
    while (choice > 5 || choice < 1) { 
        starterMenu();
        cin >> choice;
    }

    return choice;
};

void getTeamData() {
    ifstream dataIn;
    string fileName;
    // Inputting file
    cout << "\nEnter File Name: "; //AtlantaUnited.txt
    cin >> fileName;
    dataIn.open(fileName.c_str()); // Opening the file
    string name, number, goals;
    for (int i = 0; i <= 11; i++) { 
        // Collecting the data inside the file
        getline(dataIn, name);
        getline(dataIn, number);
        getline(dataIn, goals);
        // Inputing the data into the array of structures
        team[i] = Player(name, stoi(number), stoi(goals));
    }
    // Closing the file
    dataIn.close();
};

void displayTeamRoster() {
    // The Header of the display table
    cout << "\nPlayer Name" << setw(10) << "Number" << setw(10) << "Goals\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < 11; i++) { // printing details of each player
        cout << fixed << setw(15) << left << team[i].name << setw(5) << right << team[i].number << setw(10) << right << team[i].goals << endl;  
    }
    cout << endl;
};

void calcTeamGoals() {
    // adding each goal to total and displaying it 
    int total = 0;
    for (int i = 0; i < 11; i++) {
        total += team[i].goals;
    }
    cout << "\nTotal goals scored: " << total << endl;  
};

void displayTeamStars() {
    // Identifying which player had the highest amount of goals and displaying it 
    string bestPlayer = team[0].name;
    int best = team[0].goals;
    for (int i = 0; i < 11; i++) {
        if (team[i].goals > best) {
            best = team[i].goals;
            bestPlayer = team[i].name;
        }
    }

    cout << "\nTop team player(s):" << setw(15) << bestPlayer << " ( " << best << " goals )" << endl;
};