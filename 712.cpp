#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int answer = 0, length1 = s1.length(), length2 = s2.length();
        int total = reduce(s1.begin(), s1.end(), 0) + reduce(s2.begin(), s2.end(), 0);

        vector<vector<int>> memories(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 0; i < length1; i++)
        {
            for (int j = 0; j < length2; j++)
            {
                if (s1[i] == s2[j])
                    memories[i + 1][j + 1] = memories[i][j] + s2[j];
                else
                    memories[i + 1][j + 1] = max(memories[i + 1][j], memories[i][j + 1]);
            }
        }

        answer = total - memories[length1][length2] * 2;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s1 = "delete";
    string s2 = "leet";

    int answer = solution.minimumDeleteSum(s1, s2);
    cout << answer << endl;

    return 0;
}
