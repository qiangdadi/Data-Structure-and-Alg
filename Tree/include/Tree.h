#pragma once

// #include <iostream>

template <class T>
struct Node{
    T val;
    Node* parent;
    Node* left;
    Node* right;
};

template <class T>
class Tree{
private:
    Node<T>* root;
public:
    explicit Tree(Node<T>* root);// explict key word forbiden implicit conversions and  copy-initialization
    Node<T>* getRoot() const;
    int insert(Node<T>* parent, Node<T>* node);
};

template <class T>
Tree<T>::Tree(Node<T>* root){
    this->root = root;
}

template <class T>
Node<T>* Tree<T>::getRoot() const{
    return this->root;
}

/*
    exit code:
    0 insertion error;
    1 no insertion error;
*/
template <class T>
int Tree<T>::insert(Node<T>* parent, Node<T>* node){
    if(!parent){
        if(!this->root){
            this->root = node;
        }else{
            
        }
    }
    return 0;
}