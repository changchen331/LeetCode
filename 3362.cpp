#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int size = nums.size(), time = queries.size();
        vector<int> diff(size + 1, 0);
        sort(queries.begin(), queries.end(),
             [](const auto &a, const auto &b)
             {
                 return a[0] < b[0];
             });

        priority_queue<int> pq;
        for (int i = 0, j = 0, sum = 0; i < size; i++)
        {
            sum += diff[i];

            while (j < time && queries[j][0] <= i)
                pq.push(queries[j++][1]);

            while (sum < nums[i] && !pq.empty() && pq.top() >= i)
            {
                sum++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if (sum < nums[i])
                return -1;
        }

        return pq.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{2, 0, 2};
    vector<vector<int>> queries{{0, 2}, {0, 2}, {1, 1}};

    int answer = solution.maxRemoval(nums, queries);
    cout << answer << endl;

    return 0;
}
