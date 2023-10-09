#include <vector>
#include <iostream>
#include <algorithm>

int ans;
void quickSelected(std::vector<int>& nums, int k, int start, int end){
    //choose the pivot at 0
    int i = start+1, j = end;
    std::cout << "quickSelected  " << "start: " << start << "  end: " << end << "  i: " << i << "  j: " << j << "  k: " << k << std::endl;
    std::cout << "vector:" << std::endl;
    for(int m = start; m <=end; m++){
        std::cout << nums[m] << " ";
    }
    std::cout << std::endl;
    while(i <= j){
        while(i <= end && nums[i] <= nums[start]) i++;
        std::cout << "find ith greater than start!!! i: " << i << std::endl;
        while(j >= start && nums[j] > nums[start]) j--;
        std::cout << "find jth reversely lower than start!!! j: " << j << std::endl;
        if(i < j){
            //swap the nums[i] and nums[j]
            std::swap(nums[i], nums[j]);
        }
    }

    std::cout << "sort done!!! j: " << j << "  k: " << k << std::endl;
    std::cout << "sort done!!! i: " << i << "  k: " << k << std::endl;

    std::swap(nums[start], nums[j]);

    if(k == (j+1)){
        ans=nums[j];
        std::cout << "find ans !!!!"<<"  k: " << k << "  j+1: " << j+1 << std::endl;
        return;
    }
    if(k > (j+1)){
        quickSelected(nums, k, i, end);
    }else{
        quickSelected(nums, k, start, j-1);
    }
}
int findKthLargest(std::vector<int>& nums, int k) {
    int n = nums.size();
    quickSelected(nums, n-k+1, 0, n-1);
    std::cout << "ans: " << ans << std::endl;
    return ans;
}

int main(){
    std::vector<int> v = {7,6,5,4,3,2,1};
    findKthLargest(v, 5);
}