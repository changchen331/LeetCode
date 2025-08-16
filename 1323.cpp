#include <iostream>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        int answer = 0;

        string str_num = to_string(num);
        for (auto &&c : str_num)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }

        answer = stoi(str_num);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int num = 669;

    int answer = solution.maximum69Number(num);
    cout << answer << endl;

    return 0;
}
