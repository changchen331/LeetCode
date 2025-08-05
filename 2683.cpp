#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int size = derived.size();

        int current = 1;
        for (int i = 0; i < size - 1; i++)
        {
            if (derived[i] == 1)
                current = 1 - current;
        }

        return (current ^ 1 == derived.back());
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> derived{1, 1, 0};

    bool answer = solution.doesValidArrayExist(derived);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
