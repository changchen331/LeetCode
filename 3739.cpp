#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int size;
    vector<int> preffix;
    vector<long long> bit;

    int lowbit(int idx)
    {
        return idx & (-idx);
    }

    void update(int idx, int value)
    {
        for (int i = idx; i <= 2 * size + 1; i += lowbit(i))
        {
            bit[i] += value;
        }
    }

    long long query(int idx)
    {
        long long resp = 0L;
        for (int i = idx; i > 0; i -= lowbit(i))
        {
            resp += bit[i];
        }
        return resp;
    }

public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        long long answer = 0L;
        size = nums.size();

        preffix.resize(size + 1, 0);
        for (int i = 1; i < size + 1; i++)
        {
            int pre = (nums[i - 1] == target) ? 1 : -1;
            preffix[i] = preffix[i - 1] + pre;
        }

        // 统计正序对
        bit.resize(2 * size + 2, 0);
        for (int i = 0; i < size + 1; i++)
        {
            int idx = preffix[i] + size + 1;
            answer += query(idx - 1);
            update(idx, 1);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 2, 2};
    int target = 2;

    long long answer = solution.countMajoritySubarrays(nums, target);
    cout << answer << endl;

    return 0;
}
