#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::boolalpha;

int binarySearch(vector<int>& arr, int num){
    int size = arr.size();
    //binary search
        int start = 0, end = size - 1;
        int mid = 0;
        while(start <= end){
            mid = (end + start) / 2;
            if(arr[mid] == num) return num;
            if(arr[mid] < num){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
}


int main(){
    vector<int> arr;
    arr.resize(1000);
    for(int i = 1; i <= 1000; i++){
        arr[i-1] = i; 
    }
    cout << boolalpha << binarySearch(arr, 16);
}