#include <iostream>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int answer = 0;

        int has_water = numBottles, no_water = 0;
        while ((has_water + no_water) >= numExchange)
        {
            answer += has_water;
            no_water = no_water + has_water - numExchange++;
            has_water = 1;
        }

        return answer + has_water;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numBottles = 13;
    int numExchange = 6;

    int answer = solution.maxBottlesDrunk(numBottles, numExchange);
    cout << answer << endl;

    return 0;
}
