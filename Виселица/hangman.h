#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
using namespace std;
void Rules();
void printHangman(int mistakes);//виселица
string getRandomAnimals();// животные
string getRandomFlowers();//цветы
string getRandomNyam();//еда
string getRandomTower();//города
void Subject();//темы
void Menu();
void back();

