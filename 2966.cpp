#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<vector<int>> answer(size / 3);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i += 3)
        {
            int mini = nums[i], mid = nums[i + 1], maxi = nums[i + 2];
            if (maxi - mini > k || maxi - mid > k || mid - mini > k)
                return {};
            answer[i / 3] = {mini, mid, maxi};
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;

    vector<vector<int>> answer = solution.divideArray(nums, k);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
