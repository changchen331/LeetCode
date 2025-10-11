#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    vector<int> keys;
    unordered_map<int, int> powers;
    vector<long long> memories;

    long long dfs(int position)
    {
        if (position < 0)
            return 0;
        long long &memory = memories[position];
        if (memory != -1)
            return memory;

        int key = keys[position], temp = position - 1;
        while (temp > -1 && keys[temp] >= key - 2)
            temp--;
        memory = max(dfs(position - 1), dfs(temp) + 1L * key * powers[key]); // max(不选, 选)
        return memory;
    }

public:
    long long maximumTotalDamage(vector<int> &power)
    {
        long long answer = 0L;
        int size = power.size();
        sort(power.begin(), power.end());

        // 初始化
        keys.emplace_back(power[0]);
        power.emplace_back(-1);
        for (int i = 1, count = 1; i <= size; i++)
        {
            int p = power[i];
            if (keys.back() != p)
            {
                powers[keys.back()] += count;
                keys.emplace_back(p);
                count = 1;
            }
            else
                count++;
        }
        size = keys.size();
        memories.resize(size, -1);

        answer = dfs(size - 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> power = {1, 1, 3, 4};
    long long answer = solution.maximumTotalDamage(power);
    cout << answer << endl;

    return 0;
}
