#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int size_spells = spells.size(), size_potions = potions.size();
        vector<int> answer(size_spells, 0);
        sort(potions.begin(), potions.end());

        for (int i = 0; i < size_spells; i++)
        {
            int &spell = spells[i];

            // 超时
            // for (int j = 0; j < size_potions; j++)
            // {
            //     int &potion = potions[j];
            //     if (1L * spell * potion >= success)
            //     {
            //         answer[i] = size_potions - j;
            //         break;
            //     }
            // }

            // 二分
            int left = 0, right = size_potions - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if ((1L * spell * potions[mid]) < success)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            right++;
            answer[i] = right < size_potions ? (size_potions - right) : 0;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> answer = solution.successfulPairs(spells, potions, success);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
