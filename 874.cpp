#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int answer = 0;
        int sizec = commands.size(), sizeo = obstacles.size();

        unordered_map<int, set<int>> obstaclexs;
        unordered_map<int, set<int>> obstacleys;
        for (auto &&obstacle : obstacles)
        {
            obstaclexs[obstacle[0]].insert(obstacle[1]);
            obstacleys[obstacle[1]].insert(obstacle[0]);
        }

        int x = 0, y = 0, direction = 0;
        // vector<char> directions = {'N', 'E', 'S', 'W'};
        for (auto &&command : commands)
        {
            if (command < 0)
            {
                if (command == -1)
                {
                    direction = (direction + 1) % 4;
                }
                else
                {
                    direction = (direction + 3) % 4;
                }
            }
            else
            {
                switch (direction)
                {
                case 0:
                    // N
                    if (obstaclexs.find(x) != obstaclexs.end())
                    {
                        auto obstaclex = obstaclexs[x];
                        bool stuck = false;
                        for (auto &&yo : obstaclex)
                        {
                            if (y < yo && yo <= y + command)
                            {
                                y = yo - 1;
                                stuck = true;
                                break;
                            }
                        }
                        if (!stuck)
                        {
                            y += command;
                        }
                    }
                    else
                    {
                        y += command;
                    }
                    break;
                case 1:
                    // E
                    if (obstacleys.find(y) != obstacleys.end())
                    {
                        auto obstacley = obstacleys[y];
                        bool stuck = false;
                        for (auto &&xo : obstacley)
                        {
                            if (x < xo && xo <= x + command)
                            {
                                x = xo - 1;
                                stuck = true;
                                break;
                            }
                        }
                        if (!stuck)
                        {
                            x += command;
                        }
                    }
                    else
                    {
                        x += command;
                    }
                    break;
                case 2:
                    // S
                    if (obstaclexs.find(x) != obstaclexs.end())
                    {
                        auto obstaclex = obstaclexs[x];
                        bool stuck = false;
                        for (auto it = obstaclex.rbegin(); it != obstaclex.rend(); it++)
                        {
                            if (y - command <= *it && *it < y)
                            {
                                y = *it + 1;
                                stuck = true;
                                break;
                            }
                        }
                        if (!stuck)
                        {
                            y -= command;
                        }
                    }
                    else
                    {
                        y -= command;
                    }
                    break;
                case 3:
                    // W
                    if (obstacleys.find(y) != obstacleys.end())
                    {
                        auto obstacley = obstacleys[y];
                        bool stuck = false;
                        for (auto it = obstacley.rbegin(); it != obstacley.rend(); it++)
                        {
                            if (x - command <= *it && *it < x)
                            {
                                x = *it + 1;
                                stuck = true;
                                break;
                            }
                        }
                        if (!stuck)
                        {
                            x -= command;
                        }
                    }
                    else
                    {
                        x -= command;
                    }
                    break;
                default:
                    break;
                }

                answer = max(answer, (x * x + y * y));
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> commands = {6, -1, -1, 6};
    vector<vector<int>> obstacles = {{0, 0}};

    int answer = solution.robotSim(commands, obstacles);
    cout << answer << endl;

    return 0;
}
