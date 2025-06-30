#include "Header.h"

// Добавление в дерево поиска
void AddToBST(PNode& Root, int Val) {
    if (!Root) {
        Root = new Node(Val);
        return;
    }
    if (Val >= Root->Data) AddToBST(Root->Right, Val);
    else AddToBST(Root->Left, Val);
}

// Заполнение случайными числами
void AddRandomToBST(PNode& Root) {
	srand(static_cast<unsigned int>(time(0)));
    int Count = rand() % 20;
    for (int i = 0; i < Count; i++) {
        int Val = rand() % 50;
        AddToBST(Root, Val);
    }
}

// Заполнение с клавиатуры
void AddInputToBST(PNode& Root) {
    int Count;
    cout << "Введите количество узлов: ";
    cin >> Count;
    for (int i = 0; i < Count; i++) {
        int Val;
        cout << "Введите значение узла: ";
        cin >> Val;
        AddToBST(Root, Val);
    }
}

// Заполнение из файла
void AddFileToBST(PNode& Root) {
    string FileName;
	cout << "Введите имя файла: ";
	cin >> FileName;
    ifstream file(FileName);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << FileName << endl;
        return;
    }
    int Val;
    while (file >> Val) {
        AddToBST(Root, Val);
    }
    file.close();
}

void BuildBST(PNode& Root, int Mode) {
    switch (Mode) {
        case 1: // Ввод с клавиатуры
            AddInputToBST(Root);
            break;
        case 2: // Случайные числа
            AddRandomToBST(Root);
            break;
        case 3: // Чтение из файла
            AddFileToBST(Root);
            break;
        default:
            cout << "Неверно" << endl;
    }
}

// Вывод дерева боком
void PrintTree(PNode Root, int Level) {
    if (!Root) {
        return;
    }
    PrintTree(Root->Right, Level + 1);
    for (int i = 0; i < Level; i++) {
        cout << "   ";
    }
    cout << Root->Data <<"(" << Root->Camera<<")" << endl;
    PrintTree(Root->Left, Level + 1);
}


//
void PrintTreeStyled(PNode Root, const string& Prefix, bool IsLeft) {
    if (Root == nullptr) {
        return;
    }

    cout << Prefix;
    cout << (IsLeft ? "├──" : "└──");
    cout << Root->Data << endl;

    string childPrefixLeft = Prefix + (IsLeft ? "│   " : "    ");
    string childPrefixRight = Prefix + (IsLeft ? "│   " : "    "); 

    PrintTreeStyled(Root->Left, Prefix + (Root->Right != nullptr ? "│   " : "    "), true);
    PrintTreeStyled(Root->Right, Prefix + "    ", false);

}

void PrintTreeStyledInternal(PNode Root, const string& Prefix, bool IsLastChild, bool IsRoot) {
    if (Root == nullptr) {
        return;
    }

    cout << Prefix;

    if (!IsRoot) {
        cout << (IsLastChild ? "└──" : "├──");
    }
    cout << Root->Data << "(" << Root->Camera << ")" << endl;

    PNode leftChild = Root->Left;
    PNode rightChild = Root->Right;

    vector<PNode> children;
    if (leftChild) children.push_back(leftChild);
    if (rightChild) children.push_back(rightChild);

    for (size_t i = 0; i < children.size(); ++i) {
        bool isLast = (i == children.size() - 1);
        string newPrefix = Prefix + (!IsRoot ? (IsLastChild ? "    " : "│   ") : "");
        PrintTreeStyledInternal(children[i], newPrefix, isLast, false);
    }
}

void PrintTreeStyledWrapper(PNode Root) {
    if (Root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }
    PrintTreeStyledInternal(Root, "", true, true);
}
//


// Освобождение памяти
void DeleteTree(PNode Node) {
    if (Node == nullptr) {
        return;
    }
    DeleteTree(Node->Left);
    DeleteTree(Node->Right);
    delete Node;
}

// TreeFun9
int SolveGreedyRecursive(PNode CurrentNode, int& CamerasCount) {
    if (CurrentNode == nullptr) {
        return STATE_NODE_COVERED_NO_CAMERA;
    }

    // Рекурсивно получаем состояния левого и правого детей
    int leftState = SolveGreedyRecursive(CurrentNode->Left, CamerasCount);
    int rightState = SolveGreedyRecursive(CurrentNode->Right, CamerasCount);

    // Если хотя бы один из детей не покрыт
    if (leftState == STATE_NODE_NOT_COVERED || rightState == STATE_NODE_NOT_COVERED) {
        CamerasCount++;
		CurrentNode->Camera = true;
        return STATE_NODE_HAS_CAMERA;
    }

    // Если хотя бы один из детей имеет камеру
    if (leftState == STATE_NODE_HAS_CAMERA || rightState == STATE_NODE_HAS_CAMERA) {
        return STATE_NODE_COVERED_NO_CAMERA;
    }

    return STATE_NODE_NOT_COVERED;
}

int MinCamerasGreedy(PNode Root) {
    if (Root == nullptr) {
        return 0;
    }

    int cameras = 0;
    // Если после обхода всего дерева корень остался в состоянии NOT_COVERED
    if (SolveGreedyRecursive(Root, cameras) == STATE_NODE_NOT_COVERED) {
        cameras++;
    }
    return cameras;
}