#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_set<int> has_secret = {0};

    struct Comparator
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[2] < b[2];
        }
    };

    void dfs(unordered_set<int> &vis, unordered_map<int, vector<int>> &g, int x)
    {
        vis.insert(x);
        has_secret.insert(x);
        for (int y : g[x])
            if (vis.find(y) == vis.end())
                dfs(vis, g, y);
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<int> answer;
        int size = meetings.size();

        sort(meetings.begin(), meetings.end(), Comparator());
        has_secret.insert(firstPerson);

        for (int i = 0; i < size;)
        {
            unordered_map<int, vector<int>> g;
            int time = meetings[i][2];
            for (; i < size && meetings[i][2] == time; i++)
            {
                int x = meetings[i][0], y = meetings[i][1];
                g[x].push_back(y);
                g[y].push_back(x);
            }

            unordered_set<int> vis;
            for (auto &&[x, _] : g)
                if (has_secret.find(x) != has_secret.end() && vis.find(x) == vis.end())
                    dfs(vis, g, x);
        }

        answer = vector(has_secret.begin(), has_secret.end());
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 6;
    vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int firstPerson = 1;

    vector<int> answer = solution.findAllPeople(n, meetings, firstPerson);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
