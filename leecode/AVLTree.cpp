
/*
*This is a library to build an AVL tree.
*The properity of AVL tree is height balance, i.e., |height(left) - height(right)| <= 1.
*/
#include "printlib.h"
#include "tree.h"


Node* buildAVLTree(vector<int> arr){
    return nullptr;
}

Node* leftRotation(Node* pivot){
    Node* root = pivot->rchild;
    pivot->rchild = root->lchild;
    root->lchild = pivot;
    return root;
}

Node* rightRotation(Node* pivot){
    Node* root = pivot->lchild;
    pivot->lchild = root->rchild;
    root->rchild = pivot;
    return root;
}

Node* adjLLImblance(Node* pivot){
    return nullptr;
}

Node* adjRRImblance(Node* pivot){
    return nullptr;
}

Node* adjLRImblance(Node* pivot){
    return nullptr;
}

Node* adjRLImblance(Node* pivot){
    return nullptr;
}

void testLeftRotation(){
    //creat a RR imbalance
    Node* root = new Node;
    Node* rchild = new Node;
    Node* rrchild = new Node; 

    root->val = 1;
    rchild->val = 2;
    rrchild->val = 3;

    root->rchild = rchild;
    root->lchild = nullptr;
    rchild->rchild = rrchild;
    rchild->lchild = nullptr;
    rrchild->rchild = nullptr;
    rrchild->lchild = nullptr;

    std::cout << "tree befor left rotation\n";
    printTree(root);
    root = leftRotation(root);
    std::cout << "tree after left rotation\n";
    printTree(root);

    delete root;
    delete rchild;
    delete rrchild;
}

void testRightRotation(){
    //creat a RR imbalance
    Node* root = new Node;
    Node* lchild = new Node;
    Node* llchild = new Node; 

    root->val = 1;
    lchild->val = 2;
    llchild->val = 3;

    root->lchild = lchild;
    root->rchild = nullptr;
    lchild->lchild = llchild;
    lchild->rchild = nullptr;
    llchild->lchild = nullptr;
    llchild->rchild = nullptr;

    std::cout << "tree befor right rotation\n";
    printTree(root);
    root = rightRotation(root);
    std::cout << "tree after right rotation\n";
    printTree(root);

    delete root;
    delete lchild;
    delete llchild;
}

int main(){

    testRightRotation();

    return 0;
}