#include <vector>
#include <iostream>
using namespace std;

class Robot
{
private:
    int x_limit, y_limit;
    int x = 0, y = 0, direction = 1;
    vector<string> directions = {"North", "East", "South", "West"};

    int perimeter, total = 0;
    int xl, yl;

public:
    Robot(int width, int height)
    {
        x_limit = width;
        y_limit = height;

        perimeter = 2 * (width - 1) + 2 * (height - 1);
        xl = width - 1;
        yl = height - 1;
    }

    void step(int num)
    {
        // 模拟(超时)
        // while (num > 0)
        // {
        //     switch (direction)
        //     {
        //     case 0:
        //         // North
        //         if (y + 1 < y_limit)
        //         {
        //             y++;
        //             num--;
        //         }
        //         else
        //         {
        //             direction = (direction + 3) % 4;
        //         }
        //         break;
        //     case 1:
        //         // East
        //         if (x + 1 < x_limit)
        //         {
        //             x++;
        //             num--;
        //         }
        //         else
        //         {
        //             direction = (direction + 3) % 4;
        //         }
        //         break;
        //     case 2:
        //         // South
        //         if (y - 1 >= 0)
        //         {
        //             y--;
        //             num--;
        //         }
        //         else
        //         {
        //             direction = (direction + 3) % 4;
        //         }
        //         break;
        //     case 3:
        //         // West
        //         if (x - 1 >= 0)
        //         {
        //             x--;
        //             num--;
        //         }
        //         else
        //         {
        //             direction = (direction + 3) % 4;
        //         }
        //         break;
        //     default:
        //         break;
        //     }
        // }

        // 计算
        total = (total + (num % perimeter)) % perimeter;
        if (0 < total && total < x_limit)
        {
            y = 0;
            x = total;
            direction = 1;
        }
        else if (xl < total && total < xl + y_limit)
        {
            x = xl;
            y = total - xl;
            direction = 0;
        }
        else if (xl + yl < total && total < xl + yl + x_limit)
        {
            y = yl;
            x = xl - (total - (xl + yl));
            direction = 3;
        }
        else
        {
            x = 0;
            y = total ? yl - (total - (xl + yl + xl)) : 0;

            direction = 2;
        }
    }

    vector<int> getPos()
    {
        return {x, y};
    }

    string getDir()
    {
        return directions[direction];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main(int argc, char const *argv[])
{
    vector<string> commands = {"Robot", "step", "step", "getPos", "getDir", "step", "getPos", "getDir", "getPos", "getDir"};
    vector<vector<int>> values = {{20, 13}, {12}, {21}, {}, {}, {17}, {}, {}, {}, {}};

    Robot *obj;
    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        auto value = values[i];

        if (command == "Robot")
        {
            int width = value[0];
            int height = value[1];
            obj = new Robot(width, height);
            cout << "null" << " ";
        }
        else if (command == "getPos")
        {
            vector<int> response = obj->getPos();
            cout << "[" << response[0] << ", " << response[1] << "] ";
        }
        else if (command == "getDir")
        {
            string response = obj->getDir();
            cout << response << " ";
        }
        else
        {
            obj->step(value[0]);
            cout << "null" << " ";
        }
    }

    return 0;
}
