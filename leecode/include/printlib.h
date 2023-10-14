#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
#include "tree.h"

using std::string;
using std::string_view;
using std::vector;
using std::max;
using std::cout;
using std::endl;


void printHeap(vector<int>& arr);
void printTree(Node* root);