#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    int answer = INT_MAX;
    int size;
    vector<vector<int>> memory; // 记录所有结果

    void dfs(string &floor, int white_num, int position, int currentCarpet, int numCarpets, int carpetLen)
    {
        for (int i = 0; i < carpetLen && position < size && white_num > 0; i++)
            if (floor[position++] == '1')
                white_num--;
        if (++currentCarpet == numCarpets || position == size || white_num == 0)
        {
            answer = min(answer, white_num);
            return;
        }

        for (int i = position; i < size; i++)
            dfs(floor, white_num, i, currentCarpet, numCarpets, carpetLen);
    }

    int DFS(string &floor, int x, int y, int carpetLen)
    {
        if (y < x * carpetLen)
            return 0;

        int &current = memory[x][y];
        if (current != -1)
            return current;

        if (x == 0)
            return current = DFS(floor, x, y - 1, carpetLen) + (floor[y] - '0');
        return current = min(DFS(floor, x, y - 1, carpetLen) + (floor[y] - '0'), DFS(floor, x - 1, y - carpetLen, carpetLen));
    }

public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        size = floor.size();

        // 我的方法（超时）
        // int white_num = 0;
        // for (int i = 0; i < size; i++)
        //     if (floor[i] == '1')
        //         white_num++;
        // if (white_num == 0)
        //     return 0;
        // for (int i = 0; i < size; i++)
        //     dfs(floor, white_num, i, 0, numCarpets, carpetLen);
        // return answer;

        // 官解
        memory.resize(numCarpets + 1, vector<int>(size, -1));
        return DFS(floor, numCarpets, size - 1, carpetLen);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string floor = "1000000000001000000100111100001101111000000001001111110000000000";
    int numCarpets = 6;
    int carpetLen = 4;

    int answer = solution.minimumWhiteTiles(floor, numCarpets, carpetLen);
    cout << answer << endl;

    return 0;
}
