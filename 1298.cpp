#include <vector>
#include <cstdint>
#include <iostream>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> &candies, vector<vector<int>> &keys,
             vector<vector<int>> &containedBoxes, int &answer,
             vector<int> &has_key, vector<uint8_t> &has_box, int current)
    {
        answer += candies[current];
        has_box[current] = false;

        for (auto &&key : keys[current])
        {
            has_key[key] = true;
            if (has_box[key])
                dfs(candies, keys, containedBoxes, answer, has_key, has_box, key);
        }

        for (auto &&containedBox : containedBoxes[current])
        {
            has_box[containedBox] = true;
            if (has_key[containedBox])
                dfs(candies, keys, containedBoxes, answer, has_key, has_box, containedBox);
        }
    }

public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int answer = 0;

        vector<int> &has_key = status;
        vector<uint8_t> has_box(status.size());
        for (auto &&initialBox : initialBoxes)
            has_box[initialBox] = true;

        for (auto &&initialBox : initialBoxes)
            if (has_key[initialBox] && has_box[initialBox])
                dfs(candies, keys, containedBoxes, answer, has_key, has_box, initialBox);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    int answer = solution.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << answer << endl;

    return 0;
}
