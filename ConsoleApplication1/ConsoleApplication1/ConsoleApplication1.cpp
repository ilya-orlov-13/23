#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian"); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);   

    cout << "TreeFun9" << endl;
    PNode Tree = nullptr;

    int Mode;
	cout << "1-заполнить с клавиатуры, 2-случайно, 3-из файла: ";
	cin >> Mode;
	BuildBST(Tree, Mode);

    int camerasNeeded = MinCamerasGreedy(Tree);
    PrintTreeStyledWrapper(Tree);
    cout << endl << endl;
    PrintTree(Tree, 0);
    cout << "Мнмальное количество камер: " << camerasNeeded << endl;

    DeleteTree(Tree);

    return 0;
}
