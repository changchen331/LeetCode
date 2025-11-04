#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int top_x;
    int length_k;

    int calculate_x_sum(vector<int> subnums)
    {
        unordered_map<int, int> memories;
        for (int i = 0; i < subnums.size(); i++)
            memories[subnums[i]]++;

        if (memories.size() < top_x)
            return accumulate(subnums.begin(), subnums.end(), 0);

        vector<pair<int, int>> num_freq_pair(memories.begin(), memories.end());
        sort(num_freq_pair.begin(), num_freq_pair.end(),
             [](const auto &a, const auto &b)
             {
                 if (a.second != b.second)
                     return a.second > b.second;
                 return a.first > b.first;
             });

        int response = 0;
        for (int i = 0; i < top_x; i++)
            response += num_freq_pair[i].first * num_freq_pair[i].second;
        return response;
    }

public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        vector<int> answer;
        int size = nums.size();

        top_x = x;
        length_k = k;

        for (int i = 0; i + k <= size; i++)
        {
            vector<int> subnums(nums.begin() + i, nums.begin() + i + k);
            answer.push_back(calculate_x_sum(subnums));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 8, 7, 8, 7, 5};
    int k = 2;
    int x = 2;

    vector<int> answer = solution.findXSum(nums, k, x);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
