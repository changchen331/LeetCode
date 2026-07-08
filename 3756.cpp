#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const int M = 1'000'000'007;
vector<long long> power_ten(100'001);
int init = []
{
    power_ten[0] = 1;
    for (int i = 1; i < 100'001; i++)
    {
        power_ten[i] = (power_ten[i - 1] * 10) % M;
    }
    return 0;
}();

class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {

        int size = queries.size();
        vector<int> answer(size, 0);

        int length = s.length() + 1;
        vector<int> pre_sum(length, 0);
        vector<long long> pre_dig(length, 0);
        vector<int> pre_cnt(length, 0);
        for (int i = 1; i < length; i++)
        {
            int num = s[i - 1] - '0';
            pre_sum[i] = pre_sum[i - 1] + num;
            pre_dig[i] = pre_dig[i - 1];
            pre_cnt[i] = pre_cnt[i - 1];
            if (num > 0)
            {
                pre_dig[i] = (pre_dig[i] * 10 + num) % M;
                pre_cnt[i]++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            int x = queries[i][0], y = queries[i][1];
            long long sum = pre_sum[y + 1] - pre_sum[x];

            long long diff = power_ten[pre_cnt[y + 1] - pre_cnt[x]];
            long long pre = pre_dig[x] * diff;
            long long dig = ((pre_dig[y + 1] - pre) % M + M) % M;

            answer[i] = (sum * dig) % M;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "10203004";
    vector<vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};

    vector<int> answer = solution.sumAndMultiply(s, queries);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
