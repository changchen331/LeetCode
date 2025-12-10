#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int MOD = 1'000'000'007;

public:
    int countPartitions(vector<int> &nums, int k)
    {
        int answer = 0, size = nums.size();
        vector<int> f(size + 1);
        f[0] = 1;

        deque<int> min_q, max_q;
        long long sum_f = 0;
        for (int i = 0, left = 0; i < size; i++)
        {
            int num = nums[i];

            sum_f += f[i];
            while (!min_q.empty() && num <= nums[min_q.back()])
                min_q.pop_back();
            min_q.push_back(i);
            while (!max_q.empty() && num >= nums[max_q.back()])
                max_q.pop_back();
            max_q.push_back(i);

            while (nums[max_q.front()] - nums[min_q.front()] > k)
            {
                sum_f -= f[left++];
                if (min_q.front() < left)
                    min_q.pop_front();
                if (max_q.front() < left)
                    max_q.pop_front();
            }

            f[i + 1] = sum_f % MOD;
        }

        answer = f[size];
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {9, 4, 1, 3, 7};
    int k = 4;

    int answer = solution.countPartitions(nums, k);
    cout << answer << endl;

    return 0;
}
