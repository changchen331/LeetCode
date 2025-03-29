#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int answer = -1, size = edges.size();

        vector<int> records(size);
        for (int i = 0, current = 1; i < size; i++)
        {
            if (answer >= size / 2)
                break;
            if (edges[i] == -1)
                continue;

            int s = i, start = current;
            for (; s != -1 && records[s] == 0; s = edges[s])
                records[s] = current++;
            if (s != -1 && records[s] >= start)
                answer = max(answer, current - records[s]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> edges{2, -1, 3, 1};

    int answer = solution.longestCycle(edges);
    cout << answer << endl;

    return 0;
}
