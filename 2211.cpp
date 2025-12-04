#include <iostream>
using namespace std;

class Solution
{
public:
    int countCollisions(string directions)
    {
        int answer = 0, length = directions.length();

        int left = 0, right = length - 1;
        for (; left < length; left++)
            if (directions[left] != 'L')
                break;
        for (; right > -1; right--)
            if (directions[right] != 'R')
                break;

        // 模拟
        // for (; left <= right; left++)
        // {
        //     char &current = directions[left];
        //     if (current == 'S')
        //         continue;

        //     if (current == 'L')
        //         answer++;
        //     else if (current == 'R')
        //     {
        //         for (int i = left + 1; i < length; i++)
        //         {
        //             if (directions[i] == 'L')
        //             {
        //                 answer += 2;
        //                 directions[i] = 'S';
        //                 break;
        //             }
        //             else if (directions[i] == 'S')
        //             {
        //                 answer++;
        //                 break;
        //             }
        //         }
        //     }
        //     current = 'S';
        // }

        // 计算
        for (; left <= right; left++)
            answer += (directions[left] != 'S');

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string directions = "LLRR";

    int answer = solution.countCollisions(directions);
    cout << answer << endl;

    return 0;
}
