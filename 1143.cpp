#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int answer = 0, length1 = text1.length(), length2 = text2.length();

        vector<vector<int>> memories(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 0; i < length1; i++)
        {
            for (int j = 0; j < length2; j++)
            {
                if (text1[i] == text2[j])
                    memories[i + 1][j + 1] = memories[i][j] + 1;
                else
                    memories[i + 1][j + 1] = max(memories[i + 1][j], memories[i][j + 1]);
            }
        }

        answer = memories[length1][length2];
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string text1 = "abcde";
    string text2 = "ace";

    int answer = solution.longestCommonSubsequence(text1, text2);
    cout << answer << endl;

    return 0;
}
