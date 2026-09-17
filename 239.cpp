#include <map>
#include <deque>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> answer;
        int size = nums.size();

        // 方法一
        // map<int, int> mem;
        // int maxi = INT_MIN;
        // for (int i = 0; i < k; i++)
        // {
        //     int cur = nums[i];
        //     mem[cur]++;
        //     maxi = max(maxi, cur);
        // }
        // answer.push_back(maxi);
        // for (int i = k; i < size; i++)
        // {
        //     int l = nums[i - k];
        //     int r = nums[i];
        //     if (--mem[l] == 0)
        //     {
        //         mem.erase(l);
        //     }
        //     mem[r]++;
        //     answer.push_back(mem.rbegin()->first);
        // }

        // 方法二
        deque<int> dq;
        for (int i = 0; i < size; i++)
        {
            int cur = nums[i];
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= cur)
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i < k - 1)
            {
                continue;
            }
            answer.push_back(nums[dq.front()]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, -1};
    int k = 1;

    vector<int> answer = solution.maxSlidingWindow(nums, k);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i < answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
