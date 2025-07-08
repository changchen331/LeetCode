#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int size = events.size();
        if (k == 1)
        {
            int maximum = 0;
            for (auto &&event : events)
                maximum = max(maximum, event[2]);
            return maximum;
        }

        sort(events.begin(), events.end(), [](const vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        vector<vector<int>> memories(size + 1, vector<int>(k + 1));
        for (int i = 0; i < size; i++)
        {
            int p = lower_bound(events.begin(), events.begin() + i, events[i][0], [](auto &e, int lower)
                                { return e[1] < lower; }) -
                    events.begin();

            for (int j = 1; j <= k; j++)
                memories[i + 1][j] = max(memories[i][j], memories[p][j - 1] + events[i][2]);
        }

        return memories[size][k];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    int k = 2;

    int answer = solution.maxValue(events, k);
    cout << answer << endl;

    return 0;
}
