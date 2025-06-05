#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int find(vector<int> &fa, int x)
    {
        if (fa[x] != x)
            fa[x] = find(fa, fa[x]);

        return fa[x];
    }

    void merge(vector<int> &fa, int x, int y)
    {
        auto [small, big] = minmax(find(fa, x), find(fa, y));
        fa[big] = small;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        string answer = "";
        int size = s1.size(), base_size = baseStr.size();

        vector<int> fa(26);
        for (int i = 0; i < 26; i++)
            fa[i] = i;

        for (int i = 0; i < size; i++)
            merge(fa, s1[i] - 'a', s2[i] - 'a');

        for (int i = 0; i < base_size; i++)
            answer.push_back(find(fa, baseStr[i] - 'a') + 'a');

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s1 = "cgokcgerolkgksgbhgmaaealacnsshofjinidiigbjerdnkolc";
    string s2 = "rjjlkbmnprkslilqmbnlasardrossiogrcboomrbcmgmglsrsj";
    string baseStr = "bxbwjlbdazfejdsaacsjgrlxqhiddwaeguxhqoupicyzfeupcn";

    string answer = solution.smallestEquivalentString(s1, s2, baseStr);
    cout << answer << endl;

    return 0;
}
