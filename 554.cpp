#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        int size = wall.size();
        int answer = size;

        int maxi = 0;
        unordered_map<long long, int> cnt;
        for (int i = 0; i < size; i++)
        {
            int len = wall[i].size();
            if (len == 1)
            {
                continue;
            }

            long long pre = 0LL;
            for (int j = 0; j < len - 1; j++)
            {
                int cur = wall[i][j];
                pre += cur;
                maxi = max(maxi, ++cnt[pre]);
            }
        }

        answer = size - maxi;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> wall = {{1, 2, 2, 1},
                                {3, 1, 2},
                                {1, 3, 2},
                                {2, 4},
                                {3, 1, 2},
                                {1, 3, 1, 1}};

    int answer = solution.leastBricks(wall);
    cout << answer << endl;

    return 0;
}
