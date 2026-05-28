#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    struct Node
    {
        vector<Node *> son{26};
        int min_len = INT_MAX;
        int best_index;
    };

    void clear(Node *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->son[i])
            {
                clear(node->son[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        int sizec = wordsContainer.size();
        int sizeq = wordsQuery.size();
        vector<int> answer(sizeq, 0);

        Node *root = new Node();
        for (int i = 0; i < sizec; i++)
        {
            string &wordc = wordsContainer[i];
            int length = wordc.length();
            if (length < root->min_len)
            {
                root->min_len = length;
                root->best_index = i;
            }

            Node *current = root;
            for (int j = length - 1; j > -1; j--)
            {
                int index = wordc[j] - 'a';
                if (current->son[index] == nullptr)
                {
                    current->son[index] = new Node();
                }
                current = current->son[index];
                if (length < current->min_len)
                {
                    current->min_len = length;
                    current->best_index = i;
                }
            }
        }

        for (int i = 0; i < sizeq; i++)
        {
            Node *current = root;
            string wordq = wordsQuery[i];
            int length = wordq.length();
            for (int j = length - 1; j > -1 && (current->son[wordq[j] - 'a']); j--)
            {
                current = current->son[wordq[j] - 'a'];
            }
            answer[i] = current->best_index;
        }

        clear(root);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
    vector<string> wordsQuery = {"cd", "bcd", "xyz"};

    vector<int> answer = solution.stringIndices(wordsContainer, wordsQuery);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
