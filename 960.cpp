#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool less_eq(vector<string> &strs, int i, int j)
    {
        for (auto &&str : strs)
            if (str[j] > str[i])
                return false;
        return true;
    }

public:
    int minDeletionSize(vector<string> &strs)
    {
        int answer = 0, size = strs.size(), length = strs[0].length();

        vector<int> f(length);
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < i; j++)
                if (f[j] > f[i] && less_eq(strs, i, j))
                    f[i] = f[j];
            f[i]++;
        }

        answer = length - *max_element(f.begin(), f.end());
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"ghi", "def", "abc"};

    int answer = solution.minDeletionSize(strs);
    cout << answer << endl;

    return 0;
}
