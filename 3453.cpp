#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    double getAreaBelow(vector<vector<int>> &squares, double h)
    {
        double response = 0;

        for (auto &&square : squares)
        {
            int y = square[1];
            int l = square[2];

            double top = y + l;
            double height = max(0.0, min(top, h) - y);
            response += height * l;
        }

        return response;
    }

public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double answer = 0;
        int size = squares.size();

        double total = 0;
        for (auto &&square : squares)
            total += 1.0 * square[2] * square[2];
        double target = total / 2.0;

        // 确定上下界
        double low = squares[0][1];
        double high = squares[0][1] + squares[0][2];
        for (auto &&square : squares)
        {
            low = min(low, 1.0 * square[1]);
            high = max(high, 1.0 * (square[1] + square[2]));
        }

        // 二分答案
        for (int i = 0; i < 50; i++)
        {
            double mid = low + (high - low) / 2;
            if (getAreaBelow(squares, mid) >= target)
                high = mid; // 面积足够，说明分界线在 mid 或更下方
            else
                low = mid; // 面积不够，说明分界线在 mid 上方
        }

        answer = high;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> squares = {{0, 0, 1}, {2, 2, 1}};

    double answer = solution.separateSquares(squares);
    cout << answer << endl;

    return 0;
}
