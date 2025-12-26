#include <iostream>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int length = customers.length();
        int answer = length;

        int penalty = 0;
        for (auto &&customer : customers)
            penalty += customer == 'N';

        int minimum = penalty;
        for (int i = length - 1; i >= 0; i--)
        {
            if (customers[i] == 'Y')
                penalty++;
            else
                penalty--;

            if (penalty <= minimum)
            {
                if (penalty < minimum)
                    minimum = penalty;
                answer = i;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string customers = "YYNY";

    int answer = solution.bestClosingTime(customers);
    cout << answer << endl;

    return 0;
}
