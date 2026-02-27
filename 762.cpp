#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int answer = 0;
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        for (; left <= right; left++)
        {
            int count = 0, temp = left;
            while (temp > 0)
            {
                count += (temp & 1);
                temp >>= 1;
            }
            answer += (primes.find(count) != primes.end());
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int left = 6;
    int right = 10;

    int answer = solution.countPrimeSetBits(left, right);
    cout << answer << endl;

    return 0;
}
