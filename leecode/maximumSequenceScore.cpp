/*
Thought: 
    1. Sorting nums2 array in descending order.
    2. Selecting the kth minimum value in nums2 and the value in nums1 with the same index.
    3. Finding the maxmium k-1 sum in nums1 then plus the corresponding value in nums1.
    4. Repeating 1-3 with deleting the maximum value in B.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include "randomGeneration.h"

using std::vector;
using std::multimap;
using std::swap;
using std::make_pair;
using std::cout;
using std::endl;

int kSum = 0;
void minHeapfy(vector<int>& arr, int i, int size){
    int left = 2 * i + 1;
    int right = 2 * (i + 1);
    int smallest = i;

    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minHeapfy(arr, smallest, size);
    }
}

void insertHeapk(vector<int>& heapk, int num){
    heapk.push_back(num);
    kSum += num;
    int size = heapk.size();
    for(int i = (size / 2 - 1); i >= 0; i--){
        minHeapfy(heapk, i, size);
    }
}

void maintainHeapk(vector<int>& heapk, int num, int k){
    if(num > heapk.front()){
        kSum -= heapk.front();
        heapk[0] = num;
        kSum += num;
        minHeapfy(heapk, 0, k);
    }
}

void heapInsert(vector<int>& heapk, int num, int k){
    int size = heapk.size();
    if(size < k){
        insertHeapk(heapk, num);
    }else{
        maintainHeapk(heapk, num, k);
    }
}

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    
    namespace time = std::chrono;
    time::time_point<time::system_clock> start, end;

    start = time::system_clock::now();
    //map to sort the nums2.
    multimap<int, int> m2;
    for(int i = 0; i < nums2.size(); i++){
        m2.insert(make_pair(nums2[i], i));
    }
    end = time::system_clock::now();
    time::duration<double> elapsed_seconds = end - start;
    std::cout << "sorting nums2 cost " << elapsed_seconds.count() << "s\n";

    start = time::system_clock::now();
    vector<int> heapk;
    auto it = m2.rbegin();
    heapInsert(heapk, nums1[it->second], k);
    for(int i = 1; i < k; i++){
        it++;
        heapInsert(heapk, nums1[it->second], k);
    }
    int ans = (it->first) * kSum;
    it++;
    while(it != m2.rend()){
        //maintainHeapk(heapk,nums ,k)
        heapInsert(heapk, nums1[it->second], k);
        int tmp = (it->first) * kSum;
        if( tmp > ans) ans = tmp;
        it++;
    }
    end = time::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "finding maximum cost " << elapsed_seconds.count() << "s\n";

    return ans;
}

int main(){
    
    vector<int> nums1;
    nums1.resize(10000);
    for(int i = 0; i < 10000; i++){
        nums1[i] = generateARandom(1, 100000); 
    }
    
    vector<int> nums2;
    nums2.resize(10000);
    for(int i = 0; i < 10000; i++){
        nums2[i] = generateARandom(1, 100000); 
    }
    int k = 3878;

    cout << "ans is:" << maxScore(nums1, nums2, k) << endl;
}