#include <vector>
#include <iostream>
using namespace std;

class OrderedStream
{
private:
    vector<string> strings;
    int current = 0;

public:
    OrderedStream(int n)
    {
        strings.resize(n);
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> response;
        strings[idKey - 1] = value;
        for (; current < strings.size(); current++)
            if (strings[current].size() > 0)
                response.push_back(strings[current]);
            else
                break;
        return response;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main(int argc, char const *argv[])
{
    OrderedStream *orderedStream;
    vector<string> commands{"OrderedStream", "insert", "insert", "insert", "insert", "insert"};
    vector<pair<int, string>> values{{5, ""}, {3, "ccccc"}, {1, "aaaaa"}, {2, "bbbbb"}, {5, "eeeee"}, {4, "ddddd"}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        if (command == "OrderedStream")
        {
            orderedStream = new OrderedStream(values[i].first);
            cout << "null ";
        }
        else
        {
            vector<string> strings = orderedStream->insert(values[i].first, values[i].second);
            cout << "[";
            for (int i = 0; i < strings.size(); i++)
                cout << strings[i] << (i < strings.size() - 1 ? "," : "");
            cout << "] ";
        }
    }

    return 0;
}
