#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int answer = 0;
        int size = colors.size();

        int left = colors.front(), right = colors.back();
        // 锁定最左边
        for (int i = size - 1; i > 0; i--)
        {
            if (colors[i] != left)
            {
                answer = max(answer, i);
                break;
            }
        }

        // 锁定最右边
        for (int i = 0; i < size - 1; i++)
        {
            if (colors[i] != right)
            {
                answer = max(answer, size - 1 - i);
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> colors = {1, 8, 3, 8, 3};

    int answer = solution.maxDistance(colors);
    cout << answer << endl;

    return 0;
}
