#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        // 超时
        // int answer = 0, size = target.size();
        // long long sum = 0;
        // for (auto &&t : target)
        //     sum += t;

        // target.emplace_back(0);
        // int head = 0, tail = size;
        // while (head < size)
        // {
        //     int minimum = *min_element(target.begin() + head, target.begin() + tail);
        //     for (int i = head; i < tail; i++)
        //         target[i] -= minimum;
        //     answer += minimum;
        //     sum -= (tail - head) * minimum;
        //     if (sum == 0)
        //         break;

        //     while (target[head] == 0)
        //         head++;
        //     tail = head + 1;
        //     while (target[tail] > 0)
        //         tail++;
        // }

        // 官解
        int answer = target[0], size = target.size();
        for (int i = 1; i < size; i++)
            answer += max(target[i] - target[i - 1], 0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> target = {5, 5, 3};

    int answer = solution.minNumberOperations(target);
    cout << answer << endl;

    return 0;
}
