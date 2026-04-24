#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        int size = nums.size(), sizeQ = queries.size();
        vector<long long> answer(sizeQ, 0);

        sort(nums.begin(), nums.end());
        vector<long long> s(size + 1, 0);
        for (int i = 0; i < size; i++)
        {
            s[i + 1] = s[i] + nums[i];
        }

        for (int i = 0; i < sizeQ; i++)
        {
            long long query = queries[i];
            int position = lower_bound(nums.begin(), nums.end(), query) - nums.begin();

            long long left = query * position - s[position];
            long long rght = (s[size] - s[position]) - query * (size - position);
            answer[i] = left + rght;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 1, 6, 8};
    vector<int> queries = {1, 5};

    vector<long long> answer = solution.minOperations(nums, queries);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
