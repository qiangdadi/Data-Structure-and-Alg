/*
*This is a library about heap and heap sorting.
*It constains three main parts:
*       1). heapfy an array.
*       2). build an array.
*       3). heap sorting.
*       [10][8][9][7][6][5][4]                              10
*         0  1  2  3  4  5  6                              /  \
*                                                         8    9         
*                                                        / \  / \              
*                                                       7   6 5  4         
* The property of heap:
*       The left child of i_th node is 2*i+1
*       The right child of i_th node is 2*(i+1)
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>


using std::swap;
using std::vector;
using std::cout;
using std::endl;
using std::string;

void maxHeapfy(vector<int>& arr, int cur, int size){
    // int size = arr.size();
    int lIndex = 2 * cur + 1;
    int rIndex = 2 * (cur + 1);
    int largest = cur;
    //find the maximum node
    if( lIndex < size && arr[lIndex] > arr[cur]){
        largest = lIndex;
    }
    if(rIndex < size && arr[rIndex] > arr[largest]){
        largest = rIndex;
    }
    //if the heap doesn't satisfy the property, heapfy it.
    if(largest != cur){
        swap(arr[largest], arr[cur]);
        maxHeapfy(arr, largest, size);
    }
}

void buildMaxHeap(vector<int>& arr){
    //all the leaf (N nodes ,the leaf start as N/2) are all max heap.
    //so for each non-leaf nodes, we adjust the original heap.
    int size = arr.size();
    for(int i = (size / 2 - 1); i >= 0; i--){
        maxHeapfy(arr, i, size);
    }
}

void heapSort(vector<int>& arr){
    //build a heap
    buildMaxHeap(arr);
    int size = arr.size();
    //swap the first node and the last node, than Pretend to delete the last node
    for( int i = 0; i < size; i++){
        maxHeapfy(arr, 0, size-i-1);
        swap(arr[0], arr[size-i-1]);
    }
}

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

//test the maxHeapy function 
void testMaxHeapfy(){
    vector<int> arr = {4, 8, 9, 7, 6, 5, 10};
    cout << "The original haep\n";
    printHeap(arr);
    maxHeapfy(arr, 0, arr.size());
    cout << "The heap after maxHeapying\n";
    printHeap(arr);
    maxHeapfy(arr, 0, arr.size());
    cout << "The heap after maxHeapying\n";
    printHeap(arr);
}

void testBuildHeap(){
    vector<int> arr = {1,4,3,7,8,9,10};
    cout << "The original haep\n";
    printHeap(arr);
    buildMaxHeap(arr);
    cout << "The heap after maxHeapying\n";
    printHeap(arr);
}

void testHeapSort(){
    vector<int> arr = {1,4,3,7,8,9,10};
    cout << "The original array\n";
    for(const auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    heapSort(arr);
    cout << "The array after heap sorting\n";
    for(const auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

int main(){

    testHeapSort();

    return 0;
}

