#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 二分搜索
void binarySearch(vector<int> &nums, int target)
{
    cout << "数组: ";
    for (auto &&num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "target = " << target << endl;

    int left, right, middle;
    middle = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    cout << "\nlower_bound: nums[" << middle << "] = " << nums[middle] << endl;

    // 左闭右闭
    left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            break;
        }
    }
    cout << "\n左闭右闭 Left: nums[" << left << "] = " << nums[left] << endl;
    cout << "左闭右闭 Middle: nums[" << middle << "] = " << nums[middle] << endl;
    cout << "左闭右闭 Right: nums[" << right << "] = " << nums[right] << endl;

    // 左闭右开
    left = 0, right = nums.size();
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else if (nums[middle] > target)
        {
            right = middle;
        }
        else
        {
            break;
        }
    }
    cout << "\n左闭右开 Left: nums[" << left << "] = " << nums[left] << endl;
    cout << "左闭右开 Middle: nums[" << middle << "] = " << nums[middle] << endl;
    cout << "左闭右开 Right: nums[" << right << "] = " << nums[right] << endl;

    // 左开右闭（答案错误）
    // left = -1, right = nums.size() - 1;
    // while (left < right)
    // {
    //     middle = left + (right - left) / 2;
    //     if (nums[middle] < target)
    //     {
    //         left = middle;
    //     }
    //     else if (nums[middle] > target)
    //     {
    //         right = middle - 1;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // cout << "\n左开右闭 Left: nums[" << left << "] = " << nums[left] << endl;
    // cout << "左开右闭 Middle: nums[" << middle << "] = " << nums[middle] << endl;
    // cout << "左开右闭 Right: nums[" << right << "] = " << nums[right] << endl;

    // 左开右开
    left = -1, right = nums.size();
    while (left + 1 < right)
    {
        middle = left + (right - left) / 2;
        if (nums[middle] < target)
        {
            left = middle;
        }
        else if (nums[middle] > target)
        {
            right = middle;
        }
        else
        {
            break;
        }
    }
    cout << "\n左开右开 Left: nums[" << left << "] = " << nums[left] << endl;
    cout << "左开右开 Middle: nums[" << middle << "] = " << nums[middle] << endl;
    cout << "左开右开 Right: nums[" << right << "] = " << nums[right] << endl;
    cout << endl;
}

void bubbleSort(vector<int> &nums)
{
    cout << "原数组: ";
    for (auto &&num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 1; j < nums.size() - i; j++)
        {
            if (nums[j - 1] > nums[j])
            {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }

    cout << "排序后: ";
    for (auto &&num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // 二分搜索
    vector<int> binary_nums = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 13;
    // binarySearch(binary_nums, target);

    // 冒泡排序
    vector<int> bubble_nums = {5, 4, 3, 2, 1, 0};
    bubbleSort(bubble_nums);

    return 0;
}
