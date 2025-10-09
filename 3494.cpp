#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        long long answer = 0;
        int size_wizard = skill.size(), size_potion = mana.size();

        vector<long long> memories(size_wizard, 0L);
        for (int i = 0; i < size_potion; i++)
        {
            int &mp = mana[i];
            memories[0] += skill[0] * mp;

            // 算最大值
            for (int j = 1; j < size_wizard; j++)
                memories[j] = max(memories[j], memories[j - 1]) + skill[j] * mp;

            // 整理时间
            for (int j = size_wizard - 2; j >= 0; j--)
                memories[j] = memories[j + 1] - skill[j + 1] * mp;
        }

        answer = memories.back();
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> skill = {1, 2, 3, 4};
    vector<int> mana = {1, 2};

    long long answer = solution.minTime(skill, mana);
    cout << answer << endl;

    return 0;
}
