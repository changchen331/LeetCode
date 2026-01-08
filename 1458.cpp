#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> memories;

    int dfs(vector<int> &nums1, vector<int> &nums2, int x, int y)
    {
        if (x < 0 || y < 0)
            return INT_MIN;
        if (memories[x][y] != INT_MIN)
            return memories[x][y];

        int response = INT_MIN;

        // 选 nums1[x] 和 nums2[y]
        int sub = max(0, dfs(nums1, nums2, x - 1, y - 1));
        int pick = nums1[x] * nums2[y] + sub;

        // 不选 nums1[x]
        int skipx = dfs(nums1, nums2, x - 1, y);
        // 不选 nums2[y]
        int skipy = dfs(nums1, nums2, x, y - 1);

        response = max(pick, max(skipx, skipy));
        return memories[x][y] = response;
    }

public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int answer = 0, size1 = nums1.size(), size2 = nums2.size();
        memories.resize(size1, vector<int>(size2, INT_MIN));

        answer = dfs(nums1, nums2, size1 - 1, size2 - 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    int answer = solution.maxDotProduct(nums1, nums2);
    cout << answer << endl;

    return 0;
}
