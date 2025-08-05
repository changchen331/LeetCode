#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int answer = 0, size = fruits.size();

        for (int i = 0; i < size; i++)
        {
            int current = fruits[i];

            int position = 0;
            while (position < size && current > baskets[position])
                position++;

            if (position < size)
                baskets[position] = 0;
            else
                answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> fruits{4, 2, 5};
    vector<int> baskets{3, 5, 4};

    int answer = solution.numOfUnplacedFruits(fruits, baskets);
    cout << answer << endl;

    return 0;
}
