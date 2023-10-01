#pragma once 
#include <vector>
#include "Tree.h"

template <class T>
class TreeSet{
private:
    Tree<T> treeSet;
public:
    explicit TreeSet(){};
    explicit TreeSet(std::vector<T>& eles);
};

template <class T>
TreeSet<T>::TreeSet(std::vector<T>& eles){
    
}