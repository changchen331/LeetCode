#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<string> strings;
    vector<int> counts0;
    vector<vector<vector<int>>> memories;

    int dfs(int i, int m, int n)
    {
        if (i < 0)
            return 0;

        int &memory = memories[i][m][n];
        if (memory != -1)
            return memory;

        memory = dfs(i - 1, m, n);
        int count0 = counts0[i];
        int count1 = strings[i].length() - count0;
        if (m >= count0 && n >= count1)
            memory = max(memory, dfs(i - 1, m - count0, n - count1) + 1);

        return memory;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int answer = 0, size = strs.size();
        strings = strs;

        counts0 = vector<int>(size, 0);
        for (int i = 0; i < size; i++)
            for (auto &&cha : strs[i])
                counts0[i] += (cha == '0');

        memories = vector(size, vector(m + 1, vector<int>(n + 1, -1)));

        answer = dfs(size - 1, m, n);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;

    int answer = solution.findMaxForm(strs, m, n);
    cout << answer << endl;

    return 0;
}
