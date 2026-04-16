#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int sizeN = nums.size(), sizeQ = queries.size();
        vector<int> answer(sizeQ, -1);

        // 超时
        // int turn = ceil((double)(sizeN - 1) / 2);
        // for (int i = 0; i < sizeQ; i++)
        // {
        //     int query = queries[i];

        //     for (int j = 1; j <= turn; j++)
        //     {
        //         int right = nums[(query + j) % sizeN];
        //         int left = nums[(query - j + sizeN) % sizeN];

        //         if (left == nums[query] || right == nums[query])
        //         {
        //             answer[i] = j;
        //             break;
        //         }
        //     }
        // }

        unordered_map<int, vector<int>> memories;
        for (int i = 0; i < sizeN; i++)
        {
            memories[nums[i]].push_back(i);
        }

        for (int i = 0; i < sizeQ; i++)
        {
            int query = queries[i];
            int num = nums[query];
            auto &memory = memories[num];
            if (memory.size() == 1)
            {
                continue;
            }

            // int temp = INT_MAX;
            // for (auto &&memo : memory)
            // {
            //     if (memo == query)
            //     {
            //         continue;
            //     }

            //     int diff = abs(query - memo);
            //     temp = min(temp, min(diff, sizeN - diff));
            // }
            // if (temp != INT_MAX)
            // {
            //     answer[i] = temp;
            // }

            int j = lower_bound(memory.begin(), memory.end(), query) - memory.begin();
            int left = memory[(j - 1 + memory.size()) % memory.size()];
            int right = memory[(j + 1) % memory.size()];
            int tempA = min(abs(left - query), sizeN - abs(left - query));
            int tempB = min(abs(query - right), sizeN - abs(query - right));
            answer[i] = min(tempA, tempB);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {14, 14, 4, 2, 19, 19, 14, 19, 14};
    vector<int> queries = {2, 4, 8, 6, 3};

    vector<int> answer = solution.solveQueries(nums, queries);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
