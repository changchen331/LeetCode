#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        long long answer = 0;
        int size = conflictingPairs.size();

        vector<vector<int>> groups(n + 1);
        for (auto &&conflictingPair : conflictingPairs)
        {
            int a = conflictingPair[0], b = conflictingPair[1];
            if (a > b)
                swap(a, b);
            groups[a].push_back(b);
        }

        vector<long long> extra(n + 2);
        vector<int> b = {n + 1, n + 1};

        for (int i = n; i > 0; i--)
        {
            // 维护最小 b 和次小 b
            b.insert(b.end(), groups[i].begin(), groups[i].end());
            sort(b.begin(), b.end());
            b.resize(2);

            answer += b[0] - i;
            extra[b[0]] += b[1] - b[0];
        }

        return answer + *max_element(extra.begin(), extra.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    vector<vector<int>> conflictingPairs{{2, 3}, {1, 4}};

    long long answer = solution.maxSubarrays(n, conflictingPairs);
    cout << answer << endl;

    return 0;
}
