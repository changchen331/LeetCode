#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int answer = 0, size = fruits.size();
        if (size == 1 || size == 2)
            return size;

        for (int head = 1; head <= size - answer; head++)
        {
            int count = 1;
            int a = fruits[head - 1], b = -1;
            for (int tail = head; tail < size; tail++)
            {
                int current = fruits[tail];
                if (b == -1 && a != current)
                    b = current;

                if (current == a || current == b)
                    count++;
                else
                    break;
            }
            answer = max(answer, count);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> fruits{0, 1, 6, 6, 4, 4, 6};

    int answer = solution.totalFruit(fruits);
    cout << answer << endl;

    return 0;
}
