#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> Jump;
    int size;

    int bfs()
    {
        vector<int> mem(size, -1);
        queue<int> q;
        mem[0] = 0;
        q.push(0);

        int left = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            // 向左
            for (; left < cur; left++)
            {
                if (mem[left] == -1)
                {
                    mem[left] = mem[cur] + 1;
                    q.push(left);
                }
            }

            // 向右
            int right = cur + Jump[cur];
            if (right >= size)
            {
                return mem[cur] + 1;
            }
            else if (mem[right] == -1)
            {
                mem[right] = mem[cur] + 1;
                q.push(cur + Jump[cur]);
            }
        }

        return -1;
    }

public:
    int minJump(vector<int> &jump)
    {
        int answer = 0;
        Jump = jump;
        size = jump.size();

        answer = bfs();

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> jump = {2, 5, 1, 1, 1, 1};

    int answer = solution.minJump(jump);
    cout << answer << endl;

    return 0;
}
