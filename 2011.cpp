#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int answer = 0;

        for (auto &&operation : operations)
        {
            if (operation[1] == '+')
                answer++;
            else
                answer--;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> operations = {"--X", "X++", "X++"};

    int answer = solution.finalValueAfterOperations(operations);
    cout << answer << endl;

    return 0;
}
