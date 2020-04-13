#include <iostream>
#include <vector>

std::vector<int> sup;

void OutputIntArray(const std::vector<int>& nums) {
    std::vector<int>::const_iterator iter = nums.begin();
    while (iter != nums.end()) std::cout << *iter++ << " ";
    std::cout << std::endl;
}

void Merge(std::vector<int>& nums, int low, int mid, int high) {
    int i, j, k;
    for (k = low; k <= high; ++k) sup[k] = nums[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k) {
	if (sup[i] <= sup[j]) nums[k] = sup[i++];
	else nums[k] = sup[j++];
    }

    while (i <= mid) nums[k++] = sup[i++];
    while (j <= high) nums[k++] = sup[j++];
}

void MergeSortCore(std::vector<int>& nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    MergeSortCore(nums, low, mid);
    MergeSortCore(nums, mid + 1, high);
    Merge(nums, low, mid, high);
}

void MergeSort(std::vector<int>& nums) {
    MergeSortCore(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {4, 2, 4, 3, 2, 6, 90, 89, 1, 78};
    sup = nums;
    MergeSort(nums);
    OutputIntArray(nums);
}
