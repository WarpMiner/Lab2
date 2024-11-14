#include "include/tree.h"
#include "include/stack.h"

BinaryTree MakeTree(string str) {
    BinaryTree tree;
    string numbers;
    cout << "Введите через пробел числа для дерева: ";
    getline(cin, numbers);
    stringstream stream(numbers);
    string number;
    while(getline(stream, number, ' ')) {
        tree.insert(stoi(number));
    }

    return tree;
}

int countNodes(NodeT* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void DFS(NodeT* root, int countNodes) {
    if (root == nullptr) return;

    Stack<NodeT*> stack(countNodes);
    stack.push(root);

    while (!stack.isEmpty()) {
        NodeT* current = stack.peek();
        stack.pop();
        cout << current->data << " "; // Обрабатываем узел

        // Сначала добавляем правого ребенка, чтобы левый обрабатывался первым
        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }
}

int main() {
    string str;
    BinaryTree tree = MakeTree(str);
    int CountOfNodes = countNodes(tree.root);

    cout << "Обход в глубину (DFS): ";
    DFS(tree.root, CountOfNodes);
    cout << endl;
}
