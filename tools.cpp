#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> POWER_OF_TWO;

int init = []
{
    for (int i = 0; i < 31; i++)
    {
        POWER_OF_TWO.emplace_back(1 << i);
    }
    return 0;
}();

struct Comparator
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }

        return a.second < b.second;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(int argc, char const *argv[])
{
    // 二进制字符串转 int
    int num = 11111;
    string s = to_string(num);
    cout << stoi(s, nullptr, 2) << endl;

    // 自定义排序规则
    vector<pair<int, int>> pairs = {{1, 2}, {2, 3}, {3, 2}, {4, 2}, {5, 2}};
    sort(pairs.begin(), pairs.end(), Comparator());

    // 创建二叉树
    vector<int> root = {1, 0, 1, 0, 1, 0, 1};
    TreeNode *head = new TreeNode(root[0]);
    queue<TreeNode *> nodes;
    nodes.push(head);
    int position = 1;
    while (!nodes.empty())
    {
        TreeNode *node = nodes.front();
        nodes.pop();

        if (position < root.size())
        {
            nodes.push(node->left = new TreeNode(root[position++]));
        }

        if (position < root.size())
        {
            nodes.push(node->right = new TreeNode(root[position++]));
        }
    }

    // 二分
    vector<int> nums = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int left, right, middle, target = 3;
    middle = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    cout << "lower_bound: nums[" << middle << "] = " << nums[middle] << endl;
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

    return 0;
}
