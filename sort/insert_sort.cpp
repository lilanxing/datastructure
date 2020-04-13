#include <iostream>
#include <vector>

std::vector<int> InsertSort(const std::vector<int>& src_nums) {
    if (src_nums.size() <= 1) return src_nums;
    
    std::vector<int> nums(src_nums);
    for (int i = 1; i < nums.size(); ++i) {
	int key = nums[i];
	int j = i;
	while (j > 0 && nums[j - 1] > key) {
	    nums[j] = nums[j - 1];
	    --j;
	}
	nums[j] = key;
    }
    
    return nums;
}

void OutputIntArray(const std::vector<int>& nums) {
    std::vector<int>::const_iterator iter = nums.begin();
    while (iter != nums.end()) std::cout << *iter++ << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> src_nums = {4, 2, 4, 3, 2, 6, 90, 89, 1, 78};
    OutputIntArray(InsertSort(src_nums));
}
