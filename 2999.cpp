#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    string Start, Finish, S;
    int Limit, Diff;
    vector<long long> memories;

    long long dfs(int i, bool is_low, bool is_high)
    {
        if (i == Finish.length())
        {
            return 1;
        }
        if (!is_low && !is_high && (memories[i] != -1))
        {
            return memories[i];
        }

        int l = is_low ? Start[i] - '0' : 0;
        int h = is_high ? Finish[i] - '0' : 9;

        long long response = 0;
        if (i < Diff)
        {
            for (int d = l; d <= min(h, Limit); d++)
            {
                response += dfs(i + 1, is_low && (d == l), is_high && (d == h));
            }
        }
        else
        {
            int x = S[i - Diff] - '0';
            if (l <= x && x <= h && x <= Limit)
            {
                response = dfs(i + 1, is_low && (x == l), is_high && (x == h));
            }
        }

        if (!is_low && !is_high)
        {
            memories[i] = response;
        }

        return response;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        Start = to_string(start);
        Finish = to_string(finish);
        int lengthS = Start.length(), lengthF = Finish.size();
        Start = string(lengthF - lengthS, '0') + Start;
        S = s;

        Limit = limit;
        Diff = lengthF - s.length();

        memories.resize(lengthF, -1);

        long long answer = dfs(0, true, true);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string s = "124";

    long long answer = solution.numberOfPowerfulInt(start, finish, limit, s);
    cout << answer << endl;

    return 0;
}
