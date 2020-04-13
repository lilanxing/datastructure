#include <iostream>
#include <vector>

void OutputIntArray(const std::vector<int>& nums) {
    std::vector<int>::const_iterator iter = nums.begin();
    while (iter != nums.end()) std::cout << *iter++ << " ";
    std::cout << std::endl;
}

void Heapify(std::vector<int>& nums, int n, int i) {
    int largest = i;
    int c = 2 * i + 1;
    if (c + 1 < n && nums[c] < nums[c + 1]) ++c;
    if (c < n && nums[c] > nums[largest]) largest = c;

    if (largest != i) {
	std::swap(nums[i], nums[largest]);
	Heapify(nums, n, largest);
    }
}

void HeapSort(std::vector<int>& nums) {
    const int N = nums.size();

    for (int i = N / 2; i >= 0; --i) Heapify(nums, N, i);
    OutputIntArray(nums);
    
    for (int i = N - 1; i > 0; --i) {
	std::swap(nums[0], nums[i]);
	Heapify(nums, i, 0);
	OutputIntArray(nums);
    }
}

int main() {
    std::vector<int> nums = {4, 2, 4, 3, 2, 6, 90, 89, 1, 78};
    HeapSort(nums);
    OutputIntArray(nums);
}
