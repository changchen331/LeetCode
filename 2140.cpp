#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    long long dfs(vector<vector<int>> &questions, vector<long long> &memories, int position)
    {
        if (position >= questions.size())
            return 0;

        long long &memory = memories[position];
        if (memory > 0)
            return memory;

        return memory = max(dfs(questions, memories, position + questions[position][1] + 1) + questions[position][0],
                            dfs(questions, memories, position + 1));
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        long long answer = 0;
        int size = questions.size();

        vector<long long> memories(size);
        answer = dfs(questions, memories, 0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> questions{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    long long answer = solution.mostPoints(questions);
    cout << answer << endl;

    return 0;
}
