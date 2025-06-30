#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian"); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);   

    cout << "TreeFun9" << endl;
    PNode Tree = nullptr;

    int Mode;
	cout << "1-��������� � ����������, 2-��������, 3-�� �����: ";
	cin >> Mode;
	BuildBST(Tree, Mode);

    int camerasNeeded = MinCamerasGreedy(Tree);
    PrintTreeStyledWrapper(Tree);
    cout << endl << endl;
    PrintTree(Tree, 0);
    cout << "��������� ���������� �����: " << camerasNeeded << endl;

    DeleteTree(Tree);

    return 0;
}