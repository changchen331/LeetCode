#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    // 随机化分区函数（Lomuto方案）
    int partition(vector<int> &arr, int left, int right)
    {
        // 随机选择基准元素并交换到末尾
        int pivotIndex = left + rand() % (right - left + 1);
        swap(arr[pivotIndex], arr[right]);

        int pivot = arr[right], i = left - 1; // 记录小于基准的区域的右边界
        for (int j = left; j < right; j++)
            if (arr[j] <= pivot)
                swap(arr[++i], arr[j]);

        // 将基准元素放到正确位置
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    // 快速排序递归实现
    void quickSort(vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            // 随机化分区
            int pivotPos = partition(arr, left, right);

            // 递归排序左右子数组
            quickSort(arr, left, pivotPos - 1);
            quickSort(arr, pivotPos + 1, right);
        }
    }

public:
    void sortColors(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{2, 0, 2, 1, 1, 0};

    solution.sortColors(nums);
    for (auto &&num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
