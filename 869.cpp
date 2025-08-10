#include <vector>
#include <iostream>
using namespace std;

vector<string> POWER_OF_TWO;
int init = []
{
    for (int i = 0; i < 31; i++)
        POWER_OF_TWO.push_back(to_string(1 << i));
    return 0;
}();

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string num = to_string(n);
        int length = num.length();

        for (auto &&pot : POWER_OF_TWO)
        {
            int p_length = pot.length();
            if (length < p_length)
                break;
            if (length > p_length)
                continue;
            if (length == p_length)
            {
                string temp = num;
                bool flag = true;
                for (auto &&p : pot)
                {
                    int position = temp.find(p);
                    if (position != -1)
                        temp[position] = 'e';
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 23;

    bool answer = solution.reorderedPowerOf2(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
