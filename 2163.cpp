#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        long long answer = 0;
        int size = nums.size(), n = size / 3;

        priority_queue<int, vector<int>, greater<>> min_pq(nums.end() - n, nums.end());
        long long sum = reduce(nums.end() - n, nums.end(), 0LL);

        vector<long long> suf_max(size - n + 1);
        suf_max[size - n] = sum;
        for (int i = size - n - 1; i >= n; i--)
        {
            int v = nums[i];
            if (v > min_pq.top())
            {
                sum += v - min_pq.top();
                min_pq.pop();
                min_pq.push(v);
            }
            suf_max[i] = sum;
        }

        priority_queue<int> max_pq(nums.begin(), nums.begin() + n);
        long long pre_min = reduce(nums.begin(), nums.begin() + n, 0LL);

        answer = pre_min - suf_max[n];
        for (int i = n; i < size - n; i++)
        {
            int v = nums[i];
            if (v < max_pq.top())
            {
                pre_min += v - max_pq.top();
                max_pq.pop();
                max_pq.push(v);
            }
            answer = min(answer, pre_min - suf_max[i + 1]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 1, 2};

    long long answer = solution.minimumDifference(nums);
    cout << answer << endl;

    return 0;
}
