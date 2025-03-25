#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        vector<int> answer;

        sort(items.begin(), items.end(), [](const std::vector<int> &a, const std::vector<int> &b)
             { return a[0] < b[0]; });
        map<int, int> pairs;
        int max = 0;
        for (auto &&item : items)
            if (item[1] > max)
                pairs[item[0]] = max = item[1];

        for (auto &&query : queries)
        {
            int maximum = 0;
            for (auto &&pair : pairs)
            {
                if (pair.first > query)
                    break;
                maximum = pair.second;
            }
            answer.push_back(maximum);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> items{{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries{1, 2, 3, 4, 5, 6};

    vector<int> answer = solution.maximumBeauty(items, queries);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
