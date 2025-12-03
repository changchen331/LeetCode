#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int MOD = 1'000'000'007;

public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int answer = 0, size = points.size();
        unordered_map<int, int> count;

        for (auto &&point : points)
        {
            int x = point[0], y = point[1];
            count[y]++;
        }

        int s = 0;
        for (auto &&[_, c] : count)
        {
            long long temp = 1L * c * (c - 1) / 2;
            answer = ((answer % MOD) + (s * temp) % MOD) % MOD;
            s = s + temp;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> points = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};

    int answer = solution.countTrapezoids(points);
    cout << answer << endl;

    return 0;
}
