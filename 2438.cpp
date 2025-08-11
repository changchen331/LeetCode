#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        int size = queries.size(), MOD = 1'000'000'007;
        vector<int> answer(size);
        vector<long long> binaries;

        // 二分分解
        for (int i = 0; n > 0; i++)
        {
            if (n & 1)
                binaries.push_back(1 << i);
            n /= 2;
        }

        // 计算
        for (int i = 0; i < size; i++)
        {
            answer[i] = binaries[queries[i][0]];
            for (int j = queries[i][0] + 1; j <= queries[i][1]; j++)
            {
                long long temp = ((answer[i] % MOD) * binaries[j] % MOD) % MOD;
                answer[i] = temp;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    vector<vector<int>> queries{{0, 0}};

    vector<int> answer = solution.productQueries(n, queries);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
