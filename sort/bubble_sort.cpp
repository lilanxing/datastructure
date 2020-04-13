#include <iostream>
#include <vector>

std::vector<int> BubbleSort(const std::vector<int>& src_nums) {
    std::vector<int> nums(src_nums);
    const int N = nums.size();
    
    for (int i = 0; i < N - 1; ++i) {
	bool ordered = true;
	for (int j = N - 1; j > i; --j) {
	    if (nums[j - 1] > nums[j]) {
		int tmp = nums[j - 1];
		nums[j - 1] = nums[j];
		nums[j] = tmp;
		ordered = false;
	    }
	}
	if (ordered) return nums;
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
    OutputIntArray(BubbleSort(src_nums));
}
