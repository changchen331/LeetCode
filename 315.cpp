#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int lowbit(int idx)
    {
        return idx & (-idx);
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 0);

        int max_size = 10'000;
        vector<int> bit(2 * (max_size + 1), 0);
        for (int i = size - 1; i > -1; i--)
        {
            int idx = nums[i] + max_size + 1;

            int query = 0;
            for (int j = idx - 1; j > 0; j -= lowbit(j))
            {
                query += bit[j];
            }
            answer[i] = query;

            for (int j = idx; j < 2 * (max_size + 1); j += lowbit(j))
            {
                bit[j] += 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 2, 6, 1};

    vector<int> answer = solution.countSmaller(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
