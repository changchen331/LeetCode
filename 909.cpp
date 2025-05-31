#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int size = board.size();
        vector<int8_t> vis(size * size + 1);

        vector<int> q = {1};
        for (int step = 0; !q.empty(); step++)
        {
            vector<int> temp = q;
            q.clear();

            for (auto &&x : temp)
            {
                if (x == size * size)
                    return step;

                for (int y = x + 1; y <= min(x + 6, size * size); y++)
                {
                    int r = (y - 1) / size, c = (y - 1) % size;

                    if (r % 2)
                        c = size - 1 - c;

                    int nxt = board[size - 1 - r][c];
                    if (nxt < 0)
                        nxt = y;

                    if (!vis[nxt])
                    {
                        vis[nxt] = true;
                        q.push_back(nxt);
                    }
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> board{{-1, -1, -1, -1, -1, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, 35, -1, -1, 13, -1},
                              {-1, -1, -1, -1, -1, -1},
                              {-1, 15, -1, -1, -1, -1}};

    int answer = solution.snakesAndLadders(board);
    cout << answer << endl;

    return 0;
}
