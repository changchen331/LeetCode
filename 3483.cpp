#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> Digits;
  vector<bool> mem;
  vector<bool> used;
  int size;

  int dfs(int digit, int num) {
    int response = 0;
    if (digit == 3) {
      return num % 2 == 0;
    }

    for (int i = 0; i < size; i++) {
      int cur = Digits[i];
      if (digit == 0 && cur == 0) {
        continue;
      }
      if (used[i]) {
        continue;
      }

      int n = num * 10 + cur;
      if (digit == 2) {
        if (mem[n]) {
          continue;
        } else {
          mem[n] = true;
        }
      }
      used[i] = true;
      response += dfs(digit + 1, n);
      used[i] = false;
    }

    return response;
  }

public:
  int totalNumbers(vector<int> &digits) {
    Digits = digits;
    size = digits.size();
    mem = vector<bool>(1'000, false);
    used = vector<bool>(size, false);

    int answer = dfs(0, 0);

    return answer;
  }
};

int main() {
  Solution solution;
  vector<int> digits = {0, 2, 2};

  int answer = solution.totalNumbers(digits);
  cout << answer << endl;

  return 0;
}