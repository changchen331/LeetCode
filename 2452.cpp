#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> answer;

        int sizeQ = queries.size(), sizeD = dictionary.size();
        int length = queries[0].size();

        for (int i = 0; i < sizeQ; i++)
        {
            string &query = queries[i];
            for (int j = 0; j < sizeD; j++)
            {
                string &dic = dictionary[j];

                int count = 0;
                for (int k = 0; k < length; k++)
                {
                    count += query[k] != dic[k];
                    if (count > 2)
                    {
                        break;
                    }
                }
                if (count <= 2)
                {
                    answer.emplace_back(query);
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"wood", "joke", "moat"};

    vector<string> answer = solution.twoEditWords(queries, dictionary);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
