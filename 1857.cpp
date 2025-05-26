#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> dfs(string &colors, vector<vector<int>> &g, vector<vector<int>> &memories, int x)
    {
        if (!memories[x].empty())
            return memories[x];

        memories[x] = {0};
        vector<int> response(26);
        for (auto &&y : g[x])
        {
            vector<int> cy = dfs(colors, g, memories, y);
            if (cy.size() <= 1)
                return cy;
            for (int i = 0; i < 26; i++)
                response[i] = max(response[i], cy[i]);
        }

        response[colors[x] - 'a']++;
        return memories[x] = response;
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int answer = 0, length = colors.length();
        vector<vector<int>> g(length);

        for (auto &&edge : edges)
        {
            int x = edge[0], y = edge[1];
            if (x == y)
                return -1;
            g[x].emplace_back(y);
        }

        vector<vector<int>> memories(length);
        for (int x = 0; x < length; x++)
        {
            vector<int> response = dfs(colors, g, memories, x);
            if (response.size() <= 1)
                return -1;
            answer = max(answer, response[colors[x] - 'a']);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string colors = "abaca";
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {3, 4}};

    int answer = solution.largestPathValue(colors, edges);
    cout << answer << endl;

    return 0;
}
