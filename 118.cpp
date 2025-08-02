#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answers = {{1}, {1, 1}};

int init = []
{
    for (int i = 2; i < 30; i++)
    {
        vector<int> temp = {1};
        for (int j = 1; j < i; j++)
            temp.push_back(answers[i - 1][j - 1] + answers[i - 1][j]);
        temp.push_back(1);
        answers.push_back(temp);
    }

    return 0;
}();

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> answer;

        for (int i = 0; i < numRows; i++)
            answer.push_back(answers[i]);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numRows = 5;

    vector<vector<int>> answer = solution.generate(numRows);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
