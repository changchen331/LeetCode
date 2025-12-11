#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    struct ComparatorX
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        }
    };

    struct ComparatorY
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            if (a[1] != b[1])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        }
    };

public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        int answer = 0, size = buildings.size();
        unordered_map<int, vector<int>> x, y;

        sort(buildings.begin(), buildings.end(), ComparatorX());
        for (auto &&building : buildings)
            x[building[0]].emplace_back(building[1]);

        sort(buildings.begin(), buildings.end(), ComparatorY());
        for (auto &&building : buildings)
            y[building[1]].emplace_back(building[0]);

        for (auto &&xn : x)
        {
            if (xn.second.size() <= 2)
                continue;

            int xx = xn.first;
            vector<int> &temp = xn.second;
            for (int i = 1; i < temp.size() - 1; i++)
                answer += (y[temp[i]][0] != xx) && (y[temp[i]].back() != xx);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    vector<vector<int>> buildings = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};

    int answer = solution.countCoveredBuildings(n, buildings);
    cout << answer << endl;

    return 0;
}
