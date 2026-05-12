#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct Comparator
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            int a_diff = a[0] - a[1];
            int b_diff = b[0] - b[1];
            return a_diff < b_diff;
        }
    };

public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        int size = tasks.size();
        int answer = 0;

        sort(tasks.begin(), tasks.end(), Comparator());
        int s = 0;
        for (auto &&task : tasks)
        {
            int actual = task[0], minimum = task[1];
            answer = max(answer, s + minimum);
            s += actual;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> tasks = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};

    int answer = solution.minimumEffort(tasks);
    cout << answer << endl;

    return 0;
}
