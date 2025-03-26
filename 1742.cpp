#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int decompose(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> boxes(46, 0);

        int temp = decompose(lowLimit);
        int start = lowLimit;
        for (int i = 0; i < 10 && start <= highLimit; i++)
        {
            if (start % 10 == 0)
                break;
            else
                start++;
            boxes[temp++]++;
        }

        if (start > highLimit)
            return *max_element(boxes.begin() + 1, boxes.end());

        temp = decompose(highLimit);
        int end = highLimit;
        for (int i = 0; i < 10 && end >= start; i++)
        {
            if (end % 10 == 9)
                break;
            else
                end--;
            boxes[temp--]++;
        }

        while (start <= end)
        {
            temp = decompose(start);
            for (int i = 0; i < 10; i++)
                boxes[temp++]++;
            start += 10;
        }

        return *max_element(boxes.begin() + 1, boxes.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int lowLimit = 1;
    int highLimit = 10;

    int answer = solution.countBalls(lowLimit, highLimit);
    cout << answer << endl;

    return 0;
}
