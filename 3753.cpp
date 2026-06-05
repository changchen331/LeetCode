#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    string str1, str2;
    int diff;
    vector<vector<vector<vector<long long>>>> memories;

    long long dfs(int i, int count, int cam, int digit, bool limit_low, bool limit_high)
    {
        if (i == str2.length())
        {
            return count;
        }

        long long &ref = memories[i][count][cam + 1][digit];
        if (!limit_low && !limit_high && ref)
        {
            return ref - 1;
        }

        int low = (limit_low && i >= diff) ? str1[i - diff] - '0' : 0;
        int high = limit_high ? str2[i] - '0' : 9;

        long long response = 0;
        bool is_num = !limit_low || i > diff;
        for (int d = low; d <= high; d++)
        {
            // 当前填的数不是最高位，cmp 才有意义
            int c = is_num ? (d > digit) - (d < digit) : 0;
            int w = count + (c * cam < 0);
            response += dfs(i + 1, w, c, d, limit_low && d == low, limit_high && d == high);
        }

        if (!limit_low && !limit_high)
        {
            ref = response + 1;
        }

        return response;
    }

public:
    long long totalWaviness(long long num1, long long num2)
    {
        str1 = to_string(num1);
        str2 = to_string(num2);
        int length1 = str1.length();
        int length2 = str2.length();

        diff = length2 - length1;

        memories.resize(length2, vector<vector<vector<long long>>>(length2, vector<vector<long long>>(3, vector<long long>(10))));

        long long answer = dfs(0, 0, 0, 0, true, true);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long num1 = 331;
    long long num2 = 612;

    long long answer = solution.totalWaviness(num1, num2);
    cout << answer << endl;

    return 0;
}
