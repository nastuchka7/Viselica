#include "hangman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;
void printHangman(int mistakes) {
    switch (mistakes) {
    case 0:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 1:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 2:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "    |     |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 3:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "   /|     |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 4:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "   /|\\    |" << endl;
        cout << "          |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 5:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "   /|\\    |" << endl;
        cout << "   /      |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    case 6:
        cout << "     _____" << endl;
        cout << "    |     |" << endl;
        cout << "    O     |" << endl;
        cout << "   /|\\    |" << endl;
        cout << "   / \\    |" << endl;
        cout << "          |" << endl;
        cout << "============" << endl;
        break;
    }
}
void back() {
    int choice;
    do {
        cout << "������ ������� ��� ���? (1 - ��, 2 - ���): ";
        cin >> choice;
      
        if (choice < 1 || choice > 2) {
            cout << "������: ������� 1 ��� 2." << endl;
        }
    } while (choice < 1 || choice > 2);
    if (choice == 1) {
        Menu(); 
    }
    else {
        cout << "�������� ���!" << endl;
        exit(0);   
    }
}
string getRandomAnimals() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Animals.txt");
    if (!file.is_open()) {
        cout << "������: ���� Animals.txt �� ������." << endl;
        return "";
    }
    string words[5];
    int count = 0;
    while (file >> words[count] && count < 5)
    {
        count++;
    }
    file.close();
    if (count == 0) {
        cout << "������: ���� Animals.txt ����." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "�����: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "������� ����� ����� (�� 1 �� " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "������: �������� ����� �����." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "������� �����: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "�������! ������� ��������� �����: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "�� ��������!" << endl;
                back();
            }
        }
        else {
            cout << "������: ����� �� ���������. �������� �������: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "������� 'r', ����� ������� �������, ��� ����� ������ �������, ����� ����������: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "�� ���������! ���������� ����� ����: " << animal << endl;
    back();
    return "";
}
string getRandomFlowers() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Flowers.txt");
    if (!file.is_open()) {
        cout << "������: ���� Flowers.txt �� ������." << endl;
        return "";
    }
    string words[5];
    int count = 0;
    while (file >> words[count] && count < 5)
    {
        count++;
    }
    file.close();
    if (count == 0) {
        cout << "������: ���� Flowers.txt ����." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "�����: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "������� ����� ����� (�� 1 �� " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "������: �������� ����� �����." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "������� �����: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "�������! ������� ��������� �����: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "�� ��������!" << endl;
                back();
            }
        }
        else {
            cout << "������: ����� �� ���������. �������� �������: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "������� 'r', ����� ������� �������, ��� ����� ������ �������, ����� ����������: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "�� ���������! ���������� ����� ����: " << animal << endl;
    back();
    return "";
    
}
string getRandomNyam() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Nyam.txt");
    if (!file.is_open()) {
        cout << "������: ���� Nyam.txt �� ������." << endl;
        return "";
    }
    string words[5];
    int count = 0;
    while (file >> words[count] && count < 5)
    {
        count++;
    }
    file.close();
    if (count == 0) {
        cout << "������: ���� Nyam.txt ����." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "�����: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "������� ����� ����� (�� 1 �� " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "������: �������� ����� �����." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "������� �����: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "�������! ������� ��������� �����: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "�� ��������!" << endl;
                back();
            }
        }
        else {
            cout << "������: ����� �� ���������. �������� �������: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "������� 'r', ����� ������� �������, ��� ����� ������ �������, ����� ����������: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "�� ���������! ���������� ����� ����: " << animal << endl;
    back();
    return "";
    
}
string getRandomTower(){
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Tower.txt");
    if (!file.is_open()) {
        cout << "������: ���� Tower.txt �� ������." << endl;
        return "";
    }
    string words[5];
    int count = 0;
    while (file >> words[count] && count < 5)
    {
        count++;
    }
    file.close();
    if (count == 0) {
        cout << "������: ���� Tower.txt ����." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "�����: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "������� ����� ����� (�� 1 �� " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "������: �������� ����� �����." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "������� �����: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "�������! ������� ��������� �����: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "�� ��������!" << endl;
                back();
            }
        }
        else {
            cout << "������: ����� �� ���������. �������� �������: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "������� 'r', ����� ������� �������, ��� ����� ������ �������, ����� ����������: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "�� ���������! ���������� ����� ����: " << animal << endl;
    back();
    return "";
}
void Menu() {
    int choice;
    do {
        cout << "==========��������==========" << endl;
        cout << "1. �������" << endl;
        cout << "2. �����" << endl;
        cout << "3.�����" << endl;
        cout << "�������� �����: ";

        cin >> choice;

        switch (choice) {
        case 1:
            Rules();
            cout << endl;
            break;

        case 2:
            cout << "��������� ����..." << endl;
            Subject();
            break;
        case 3:cout << "�������� ���!" << endl; exit(0);
            break;
        default:
            cout << "������: �������� ����� �����, ���������� �����" << endl;
            break;
        }

    } while (choice != 3 && choice != 2);

  
}
void Rules() {
    cout << "������� ������� ����..." << endl;
    cout << "������� ���� ��������:" << endl;
    cout << "1. ��������� ���������� ����� �� ������." << endl;
    cout << "2. ����� �������� ������� ����� � �����, ����� �� �� �����." << endl;
    cout << "3. ���� ����� ��������� �����, �� ��� ������������ �� ������ � ��������������� ������." << endl;
    cout << "4. ���� ����� ���������, �� � �������� ����������� ���� �� ������ ����." << endl;
    cout << "5. ����� ������ ������� ����� �� ����, ��� � �������� ����� ��������� ��������� ����� ����." << endl;
    cout << "6. ���� ����� ������ �����, �� �� ���������, � ��������� ������ �� �����������." << endl;
    cout << "7. ����� �������� �� ����������, �������������� ����� ������ ���� ��������������." << endl;
}

void Subject() {
    int choice;
    string animal;
    do {
        cout << "�������� ���� ��� ����: " << endl;
        cout << "1. ��������" << endl;  
        cout << "2. �����" << endl;
        cout << "3. ���" << endl;
        cout << "4. ������" << endl;
        cout << "5. ��������� � ����" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << getRandomAnimals() << endl;
            break;
        case 2:getRandomFlowers();
            break;
        case 3:getRandomNyam();
            break;
        case 4:getRandomTower();
            break;
        case 5:Menu();
            break;
        default:
            cout << "������������ ����, ���������� �����!" << endl;  
        }
    } while (choice <=0 && choice<5); 
}



 

