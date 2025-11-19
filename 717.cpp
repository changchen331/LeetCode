#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int size = bits.size();

        int i = 0;
        for (; i < size - 1; i++)
        {
            int bit = bits[i];
            if (bit)
                i++;
        }

        return (i == size - 1) && (bits[i] == 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> bits = {1, 1, 0};

    bool answer = solution.isOneBitCharacter(bits);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
