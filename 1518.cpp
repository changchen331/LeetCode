#include <iostream>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int answer = 0;

        int water = numBottles, no_water = 0;
        while ((water + no_water) >= numExchange)
        {
            answer += water;

            no_water += water;
            water = no_water / numExchange;
            no_water %= numExchange;
        }
        answer += water;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numBottles = 9;
    int numExchange = 3;

    int answer = solution.numWaterBottles(numBottles, numExchange);
    cout << answer << endl;

    return 0;
}
