#include <iostream>
#include <string>

using namespace std;

struct Matriculant {
    string fullName;
    int direction;
    union
    {
        struct { int physics, mathematics; } InfSystems;
        struct { int chemistry, biology; } Medical;
    };
    int russian;
    string telephoneNumber;
};

Matriculant createMatriculant(int direction) {
    Matriculant matriculant;

    cout << "Enter full name: ";
    while (matriculant.fullName == "") {
        getline(cin, matriculant.fullName);
    }

    matriculant.direction = direction;
    if (direction == 1) {
        cout << "Points in physics: ";
        cin >> matriculant.InfSystems.physics;
        cout << "Points in mathematics: ";
        cin >> matriculant.InfSystems.mathematics;
    } else {
        cout << "Points in chemistry: ";
        cin >> matriculant.Medical.chemistry;
        cout << "Points in biology: ";
        cin >> matriculant.Medical.biology;
    }

    cout << "Points in russian: ";
    cin >> matriculant.russian;
    cout << "Phone number: ";
    while (matriculant.telephoneNumber == "") {
        getline(cin, matriculant.telephoneNumber);
    }
    return matriculant;
}

void printMatriculant(Matriculant matriculant) {
    cout << "Name: " << matriculant.fullName << "\n";
    if (matriculant.direction == 1) {
        cout << "Direction: Information Systems and Technology\n";
        cout << "Points: " << matriculant.InfSystems.physics << ", " << matriculant.InfSystems.mathematics << ", ";
    }
    else {
        cout << "Direction: Medical\n";
        cout << "Points: " << matriculant.Medical.chemistry << ", " << matriculant.Medical.biology << ", ";
    }
    cout << matriculant.russian << "\n";
    cout << "Telephone number: " << matriculant.telephoneNumber << "\n";
}

int main()
{
    Matriculant dataBase[10], matriculant = { "", 0, {0, 0}, 0, "" };
        
    int i, j;
    for (i = 0; i < sizeof(dataBase) / sizeof(matriculant); i++) {
        dataBase[i] = matriculant;
    }

    while (true) {
        cout << "    Menu:\n"
            << "1. Data input.\n"
            << "2. Output of information about the matriculant.\n"
            << "3. Output of all information.\n"
            << "4. Delete information about matriculant.\n"
            << "5. Delete of all information.\n"
            << "6. Finish the job.\n"
            << ">";
        cin >> i;

        switch (i) {
        case 1: 
            cout << "Number of matriculant: "; cin >> i;
            cout << "Direction (1-Information systems, 2-Medical): "; cin >> j;
            dataBase[i - 1] = createMatriculant(j); 
            break;
        case 2: 
            cout << "Number of matriculant: "; cin >> i;
            printMatriculant(dataBase[i - 1]); 
            break;
        case 3: 
            for (i = 0; i < sizeof(dataBase) / sizeof(matriculant); i++) {
                if (dataBase[i].direction != 0) {
                    cout << "Matriculant #" << i + 1 << ':' << "\n";
                    printMatriculant(dataBase[i]);
                }
            }
            break;
        case 4: 
            cout << "Number of matriculant: "; cin >> i;
            dataBase[i - 1] = matriculant;
            break;
        case 5: 
            for (i = 0; i < sizeof(dataBase) / sizeof(matriculant); i++) {
                dataBase[i] = matriculant;
            }
            break;
        case 6:
            return 0;
        default: cout << "Repeat input!\n";
        }
    }
}