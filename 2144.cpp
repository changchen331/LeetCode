#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int s = cost.size();
        int answer = 0;

        sort(cost.begin(), cost.end(), greater());
        for (int i = 0, count = 0; i < s; i++)
        {
            if (count < 2)
            {
                answer += cost[i];
                count++;
            }
            else
            {
                count = 0;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> cost = {6, 5, 7, 9, 2, 2};

    int answer = solution.minimumCost(cost);
    cout << answer << endl;

    return 0;
}
