#include "printlib.h"

void printHeap(string prefix, vector<int>& arr, int cur, bool isLeft){
    int size = arr.size();
    cout << prefix;
    cout << (isLeft ? "|--" : "|__" );
    // print the value of the node
    cout << arr[cur] << endl;

    // enter the next tree level - left and right branch
    if(2 * cur + 1 < size ){
        printHeap( prefix + (isLeft ? "|   " : "    "), arr, 2*cur+1, true);
    }
    if(2*( cur + 1 ) < size ){
        printHeap( prefix + (isLeft ? "|   " : "    "), arr, 2*(cur+1), false);
    }
}

void printHeap(vector<int>& arr){
    printHeap("", arr, 0, false);
}


void printTree(string prefix, Node* root, bool isLeft){
    if(!root) return;
    cout << prefix;
    cout << (isLeft ? "|--" : "|__" );
    // print the value of the node
    cout << "<" << root->val << " , " << root->height << ">" << endl;

    printTree(prefix + (isLeft ? "|   " : "    "), root->lchild, true);
    printTree(prefix + (isLeft ? "|   " : "    "), root->rchild, false);
}

void printTree(Node* root){
    printTree("", root, false);
    // cout << "print tree end\n";
}
