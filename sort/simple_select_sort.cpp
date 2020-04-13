#include <iostream>
#include <vector>

void Swap(std::vector<int>& nums, const int i, const int j) {
    if (i < 0 || i > nums.size() || j < 0 || j > nums.size()) return;
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void SelectSort(std::vector<int>& nums) {
    const int N = nums.size();
    for (int i = 0; i < N - 1; ++i) {
	int min = i;
	for (int j = i + 1; j < N; ++j) {
	    if (nums[j] < nums[min]) min = j;
	}
	if (min != i) Swap(nums, i, min);
    }
}

void OutputIntArray(const std::vector<int>& nums) {
    std::vector<int>::const_iterator iter = nums.begin();
    while (iter != nums.end()) std::cout << *iter++ << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {4, 2, 4, 3, 2, 6, 90, 89, 1, 78};
    SelectSort(nums);
    OutputIntArray(nums);
}
