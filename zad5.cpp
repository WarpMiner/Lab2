#include "include/tree.h"

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

void BubbleSort(vector<int>& leaves) {
    int n = leaves.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (leaves[j] > leaves[j + 1]) {
                swap(leaves[j], leaves[j + 1]);
            }
        }
    }
}

vector<int> FindLeaves(NodeT* node, vector<int>& leaves) {
    if (node == nullptr) return leaves;

    if(node->left == nullptr && node->right == nullptr) {
        leaves.push_back(node->data);
    }
    FindLeaves(node->left, leaves);
    FindLeaves(node->right, leaves);

    return leaves;
}

int main() {
    string str;
    BinaryTree tree = MakeTree(str);
    vector<int> leaves;
    leaves = FindLeaves(tree.root, leaves);
    
    BubbleSort(leaves);

    for (int i : leaves) {
        cout << i << " ";
    }
    return 0;
}
