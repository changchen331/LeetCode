#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX = 1'000'001;
vector<int> prime_factors[MAX];

int init = []
{
    for (int i = 2; i < MAX; i++)
    {
        if (prime_factors[i].empty())
        {
            for (int j = i; j < MAX; j += i)
            {
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution
{
public:
    int minJumps(vector<int> &nums)
    {
        int size = nums.size();
        int answer = 0;

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < size; i++)
        {
            for (auto &&p : prime_factors[nums[i]])
            {
                groups[p].push_back(i);
            }
        }

        vector<bool> vis(size);
        vis[0] = true;
        vector<int> q = {0};

        while (true)
        {
            auto temp = q;
            q.clear();
            for (auto &&t : temp)
            {
                if (t == size - 1)
                {
                    return answer; // 到达终点
                }

                auto &idx = groups[nums[t]];
                idx.push_back(t + 1);
                if (t > 0)
                {
                    idx.push_back(t - 1);
                }
                for (int j : idx)
                {
                    // 可以从 t 跳到 j
                    if (!vis[j])
                    {
                        vis[j] = true;
                        q.push_back(j);
                    }
                }
                idx.clear(); // 避免重复访问下标列表
            }
            answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 4, 7, 9};

    int answer = solution.minJumps(nums);
    cout << answer << endl;

    return 0;
}
