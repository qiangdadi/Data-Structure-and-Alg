#include <iostream>
#include "tree.h"

void Test01(){
    struct Node<int>* root = new Node<int>();
    root->val = 5;
    root->parent = nullptr;
    root->left = nullptr;
    root->right = nullptr;

    Tree<int> t(root);
    if(t.getRoot()->val == 5){
        std::cout << "Test succeed!\n";
    }else{
        std::cout << "Test filed!\n";
    }
}

int main(){
    Test01();
    return 0;
}