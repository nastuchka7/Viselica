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
        cout << "Хотите сыграть еще раз? (1 - Да, 2 - Нет): ";
        cin >> choice;
      
        if (choice < 1 || choice > 2) {
            cout << "Ошибка: введите 1 или 2." << endl;
        }
    } while (choice < 1 || choice > 2);
    if (choice == 1) {
        Menu(); 
    }
    else {
        cout << "Заходите еще!" << endl;
        exit(0);   
    }
}
string getRandomAnimals() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Animals.txt");
    if (!file.is_open()) {
        cout << "Ошибка: файл Animals.txt не найден." << endl;
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
        cout << "Ошибка: файл Animals.txt пуст." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "Слово: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "Введите номер буквы (от 1 до " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "Ошибка: неверный номер буквы." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "Введите букву: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "Угадали! Текущее состояние слова: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "Вы победили!" << endl;
                back();
            }
        }
        else {
            cout << "Ошибка: буква не совпадает. Осталось попыток: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "Введите 'r', чтобы открыть правила, или любую другую клавишу, чтобы продолжить: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "Вы проиграли! Загаданное слово было: " << animal << endl;
    back();
    return "";
}
string getRandomFlowers() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Flowers.txt");
    if (!file.is_open()) {
        cout << "Ошибка: файл Flowers.txt не найден." << endl;
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
        cout << "Ошибка: файл Flowers.txt пуст." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "Слово: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "Введите номер буквы (от 1 до " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "Ошибка: неверный номер буквы." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "Введите букву: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "Угадали! Текущее состояние слова: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "Вы победили!" << endl;
                back();
            }
        }
        else {
            cout << "Ошибка: буква не совпадает. Осталось попыток: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "Введите 'r', чтобы открыть правила, или любую другую клавишу, чтобы продолжить: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "Вы проиграли! Загаданное слово было: " << animal << endl;
    back();
    return "";
    
}
string getRandomNyam() {
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Nyam.txt");
    if (!file.is_open()) {
        cout << "Ошибка: файл Nyam.txt не найден." << endl;
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
        cout << "Ошибка: файл Nyam.txt пуст." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "Слово: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "Введите номер буквы (от 1 до " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "Ошибка: неверный номер буквы." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "Введите букву: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "Угадали! Текущее состояние слова: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "Вы победили!" << endl;
                back();
            }
        }
        else {
            cout << "Ошибка: буква не совпадает. Осталось попыток: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "Введите 'r', чтобы открыть правила, или любую другую клавишу, чтобы продолжить: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "Вы проиграли! Загаданное слово было: " << animal << endl;
    back();
    return "";
    
}
string getRandomTower(){
    int mistakes = 0;
    srand(time(nullptr));
    ifstream file("Tower.txt");
    if (!file.is_open()) {
        cout << "Ошибка: файл Tower.txt не найден." << endl;
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
        cout << "Ошибка: файл Tower.txt пуст." << endl;
        return "";
    }
    string animal = words[rand() % count];
    int len = animal.length();
    printHangman(mistakes);
    cout << "Слово: ";
    for (int i = 0; i < len; i++) {
        cout << "_";
    }
    cout << endl;
    int errors = 0;
    string guessed_word(len, '_');
    while (errors < 6) {
        cout << "Введите номер буквы (от 1 до " << len << "): ";
        int index;
        cin >> index;
        if (index < 1 || index > len) {
            cout << "Ошибка: неверный номер буквы." << endl;
            errors++;
            continue;
        }

        char guess;

        cout << "Введите букву: ";
        cin >> guess;

        guess = tolower(guess);
        if (tolower(animal[index - 1]) == guess) {
            guessed_word[index - 1] = guess;
            cout << "Угадали! Текущее состояние слова: " << guessed_word << endl;
            printHangman(mistakes);
            if (guessed_word == animal) {
                cout << "Вы победили!" << endl;
                back();
            }
        }
        else {
            cout << "Ошибка: буква не совпадает. Осталось попыток: " << 5 - errors << endl;
            errors++;
            mistakes++;
            printHangman(mistakes);
        }

        cout << "Введите 'r', чтобы открыть правила, или любую другую клавишу, чтобы продолжить: ";
        char choice;
        cin >> choice;
        if (choice == 'r') {
            Rules();
        }
    }
    cout << "Вы проиграли! Загаданное слово было: " << animal << endl;
    back();
    return "";
}
void Menu() {
    int choice;
    do {
        cout << "==========ВИСЕЛИЦА==========" << endl;
        cout << "1. Правила" << endl;
        cout << "2. Старт" << endl;
        cout << "3.Выход" << endl;
        cout << "Выберите опцию: ";

        cin >> choice;

        switch (choice) {
        case 1:
            Rules();
            cout << endl;
            break;

        case 2:
            cout << "Запускаем игру..." << endl;
            Subject();
            break;
        case 3:cout << "Заходите еще!" << endl; exit(0);
            break;
        default:
            cout << "Ошибка: неверный выбор опции, попробуйте снова" << endl;
            break;
        }

    } while (choice != 3 && choice != 2);

  
}
void Rules() {
    cout << "Выводим правила игры..." << endl;
    cout << "Правила игры Виселица:" << endl;
    cout << "1. Компьютер загадывает слово из списка." << endl;
    cout << "2. Игрок пытается угадать буквы в слове, вводя их по одной." << endl;
    cout << "3. Если игрок угадывает букву, то она отображается на экране в соответствующих местах." << endl;
    cout << "4. Если игрок ошибается, то к виселице добавляется одна из частей тела." << endl;
    cout << "5. Игрок должен угадать слово до того, как к виселице будет добавлена последняя часть тела." << endl;
    cout << "6. Если игрок угадал слово, то он побеждает, в противном случае он проигрывает." << endl;
    cout << "7. Слова написаны на английском, соответственно буквы должны быть тожеанглийские." << endl;
}

void Subject() {
    int choice;
    string animal;
    do {
        cout << "Выберите тему для игры: " << endl;
        cout << "1. Животные" << endl;  
        cout << "2. Цветы" << endl;
        cout << "3. Еда" << endl;
        cout << "4. Города" << endl;
        cout << "5. Вернуться в меню" << endl;
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
            cout << "Неправильный ввод, попробуйте снова!" << endl;  
        }
    } while (choice <=0 && choice<5); 
}



 

