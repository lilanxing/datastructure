#include <iostream>
#include <vector>

std::vector<int> ShellSort(const std::vector<int>& src_nums) {
    if (src_nums.size() <= 1) return src_nums;
    
    std::vector<int> nums(src_nums);
    const int N = nums.size();

    for (int gap = N / 2; gap >= 1; gap /= 2) {
	for (int i = gap; i < N; ++i) {
	    int tmp = nums[i];
	    int j = i;
	    while (j >= gap && nums[j - gap] > tmp) {
		nums[j] = nums[j - gap];
		j -= gap;
	    }
	    nums[j] = tmp;
	}
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
    OutputIntArray(ShellSort(src_nums));
}
