#include <iostream>
#include <vector>

int Partition(std::vector<int>& nums, int low, int high)  {
    int pivot = nums[low];
    while (low < high) {
	while (low < high && nums[high] >= pivot) --high;
	nums[low] = nums[high];
	while (low < high && nums[low] <= pivot) ++low;
	nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}


void QuickSortCore(std::vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int k = Partition(nums, low, high);
    QuickSortCore(nums, low, k - 1);
    QuickSortCore(nums, k + 1, high);
}

void QuickSort(std::vector<int>& nums) {
    QuickSortCore(nums, 0, nums.size() - 1);
}

void OutputIntArray(const std::vector<int>& nums) {
    std::vector<int>::const_iterator iter = nums.begin();
    while (iter != nums.end()) std::cout << *iter++ << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {4, 2, 4, 3, 2, 6, 90, 89, 1, 78};
    QuickSort(nums);
    OutputIntArray(nums);
}
