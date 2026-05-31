#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int size = asteroids.size();
        sort(asteroids.begin(), asteroids.end());

        long long m = mass;
        for (int i = 0; i < size; i++)
        {
            int current = asteroids[i];
            if (m < current)
            {
                return false;
            }
            m += current;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};

    bool answer = solution.asteroidsDestroyed(mass, asteroids);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
