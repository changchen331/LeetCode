#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> answer;
        int size = nums.size();

        vector<pair<int, int>> mem;
        for (int i = 0; i < size; i++)
        {
            mem.push_back({nums[i], i});
        }
        mem.push_back({INT_MAX, size});
        size++;

        sort(mem.begin(), mem.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.first < b.first;
             });

        int left = 0, right = 1;
        for (; right < size; right++)
        {
            if (mem[right].first - mem[right - 1].first > limit)
            {
                vector<int> pos;
                for (int i = 0; i < right - left; i++)
                {
                    pos.push_back(mem[left + i].second);
                }
                sort(pos.begin(), pos.end());
                for (int i = 0; i < right - left; i++)
                {
                    nums[pos[i]] = mem[left + i].first;
                }
                left = right;
            }
        }

        answer = nums;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    vector<int> answer = solution.lexicographicallySmallestArray(nums, limit);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i != answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
