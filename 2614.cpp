#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(int num) // 判断是否为质数
    {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;

        for (int i = 5; i * i <= num; i += 6)
            if ((num % i == 0) || (num % (i + 2) == 0))
                return false;
        return true;
    }

public:
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int answer = 0, size = nums.size(), length = nums[0].size() - 1;

        for (int x = 0; x < size; x++)
        {
            int num1 = nums[x][x], num2 = nums[x][length - x];
            if (check(num1))
                answer = max(answer, num1);
            if (num1 == num2)
                continue;
            if (check(num2))
                answer = max(answer, num2);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> nums{{1, 2, 3}, {5, 17, 7}, {9, 11, 10}};

    int answer = solution.diagonalPrime(nums);
    cout << answer << endl;

    return 0;
}
