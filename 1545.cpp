#include <vector>
#include <iostream>
using namespace std;

vector<string> binaries;
int init = []
{
    binaries.emplace_back("0");
    for (int i = 0; i < 20; i++)
    {
        string last = binaries.back();
        string temp = "1";
        for (int j = last.size() - 1; j > -1; j--)
        {
            temp.push_back(last[j] == '1' ? '0' : '1');
        }
        binaries.emplace_back(last + temp);
    }

    return 0;
}();

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (k == 1)
        {
            return '0';
        }

        return binaries[n - 1][k - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    int k = 1;

    char answer = solution.findKthBit(n, k);
    cout << answer << endl;

    return 0;
}
