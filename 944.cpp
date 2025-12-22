#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int answer = 0, size = strs.size(), length = strs[0].length();

        for (int i = 0; i < length; i++)
        {
            for (int j = 1; j < size; j++)
            {
                if (strs[j][i] < strs[j - 1][i])
                {
                    answer++;
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"cba", "daf", "ghi"};

    int answer = solution.minDeletionSize(strs);
    cout << answer << endl;

    return 0;
}
