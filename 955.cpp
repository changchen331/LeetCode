#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int answer = 0, size = strs.size(), length = strs[0].length();

        vector<string> temp(size, "");
        for (int i = 0; i < length; i++)
        {
            bool deleted = false;
            for (int j = 0; j < size - 1; j++)
            {
                if (temp[j] + strs[j][i] > temp[j + 1] + strs[j + 1][i])
                {
                    answer++;
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
                for (int j = 0; j < size; j++)
                    temp[j] += strs[j][i];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"zyx", "wvu", "tsr"};

    int answer = solution.minDeletionSize(strs);
    cout << answer << endl;

    return 0;
}
