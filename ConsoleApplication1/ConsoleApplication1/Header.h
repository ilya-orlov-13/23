#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <ctime>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Структура узла дерева
class Node {
public:
    int Data;
    Node* Left;
    Node* Right;
    bool Camera = false;

    Node(int data) : Data(data), Left(nullptr), Right(nullptr) {}
};

// Псевдоним для указателя на узел
typedef Node* PNode;

// Функции для работы с деревом
void AddToBST(PNode& Root, int Val);
void PrintTree(PNode Root, int Level); 
void PrintTreeStyledWrapper(PNode Root);
void DeleteTree(PNode Node);
void BuildBST(PNode& Root, int Mode);

// Состояния для жадного алгоритма
const int STATE_NODE_NOT_COVERED = 0;
const int STATE_NODE_HAS_CAMERA = 1;
const int STATE_NODE_COVERED_NO_CAMERA = 2;

// Функция для подсчета минимального количества камер
int MinCamerasGreedy(PNode Root);

#endif // HEADER_H