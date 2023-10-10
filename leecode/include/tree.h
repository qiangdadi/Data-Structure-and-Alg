#pragma once 


struct Node{
    Node* pa;
    Node* lchild;
    Node* rchild;
    int val;
    //some argument about subtree property
    int height;
};
