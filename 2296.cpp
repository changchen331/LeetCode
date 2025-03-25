#include <vector>
#include <iostream>
using namespace std;

class TextEditor
{
private:
    string characters;
    int current;

public:
    TextEditor()
    {
        characters = "";
        current = 0; // 表示左边还剩下多少个字符
    }

    void addText(string text)
    {
        characters.insert(current, text);
        current += text.length();
    }

    int deleteText(int k)
    {
        int length = min(current, k);
        current -= length;
        characters.erase(characters.begin() + current, characters.begin() + current + length);
        return length;
    }

    string cursorLeft(int k)
    {
        current = max(0, current - k);
        int length = min(10, current);
        return characters.substr(current - length, length);
    }

    string cursorRight(int k)
    {
        current = min((int)characters.size(), current + k);
        int length = min(10, current);
        return characters.substr(current - length, length);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main(int argc, char const *argv[])
{
    TextEditor *textEditor;
    vector<string> commands{"TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"};
    vector<vector<string>> values{{""}, {"leetcode"}, {"4"}, {"practice"}, {"3"}, {"8"}, {"10"}, {"2"}, {"6"}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        string value = values[i][0];

        if (command == "TextEditor")
        {
            textEditor = new TextEditor();
            cout << "null";
        }
        else if (command == "addText")
        {
            textEditor->addText(value);
            cout << "null";
        }
        else if (command == "deleteText")
            cout << textEditor->deleteText(stoi(value));
        else if (command == "cursorLeft")
            cout << "\"" << textEditor->cursorLeft(stoi(value)) << "\"";
        else
            cout << "\"" << textEditor->cursorRight(stoi(value)) << "\"";
        cout << (i < commands.size() - 1 ? ", " : "");
    }

    return 0;
}
