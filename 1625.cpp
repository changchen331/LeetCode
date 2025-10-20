#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        string answer = s;
        int length = s.length();

        // 构建所有可能的值
        int size = b % 2 ? 100 : 10;
        // 偶数位
        vector<string> odds(size / 10, "");
        for (int i = 0; i < size / 10; i++)
            for (int j = 0; j < length; j += 2)
                odds[i].append(to_string((s[j] - '0' + i * a) % 10));
        // 奇数位
        vector<string> evens(10, "");
        for (int i = 0; i < 10; i++)
            for (int j = 1; j < length; j += 2)
                evens[i].append(to_string((s[j] - '0' + i * a) % 10));
        // 合并偶数奇数位
        vector<string> memories(size, "");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < length / 2; j++)
            {
                memories[i].push_back(odds[i / 10][j]);
                memories[i].push_back(evens[i % 10][j]);
            }
            answer = min(answer, memories[i]);
        }

        // 构建所有顺序
        string temp = s;
        for (int i = 1; i < length; i++)
        {
            for (auto &&memory : memories)
            {
                for (int j = 0; j < length; j++)
                    temp[(j + i * b) % length] = memory[j];
                answer = min(answer, temp);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "74";
    int a = 5;
    int b = 1;

    string answer = solution.findLexSmallestString(s, a, b);
    cout << answer << endl;

    return 0;
}
