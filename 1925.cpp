#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> square;

int init = []
{
    square.insert(25);
    square.insert(100);
    for (int i = 13; i <= 250; i++)
        square.insert(i * i);

    return 0;
}();

class Solution
{
public:
    int countTriples(int n)
    {
        int answer = 0;

        int limitation = n * n;
        for (int i = 3; i < n; i++)
        {
            int x = i * i;
            for (int j = i + 1; j <= n; j++)
            {
                int y = j * j;
                if (x + y > limitation)
                    break;
                if (square.find(x + y) != square.end())
                    answer += 1 + (x != y);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 12;

    int answer = solution.countTriples(n);
    cout << answer << endl;

    return 0;
}
