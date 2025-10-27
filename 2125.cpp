#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int answer = 0, m = bank.size(), n = bank[0].length();

        int last = -1;
        for (auto &&floor : bank)
        {
            int count = 0;
            for (auto &&cell : floor)
                count += cell - '0';
            if (count == 0)
                continue;

            if (last == -1)
            {
                last = count;
                continue;
            }
            answer += last * count;
            last = count;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> bank = {"011001", "000000", "010100", "001000"};

    int answer = solution.numberOfBeams(bank);
    cout << answer << endl;

    return 0;
}
