#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int count(vector<vector<int>> &im1, vector<vector<int>> &im2) {
    int resp = 0;
    int size1 = im1.size();
    int size2 = im2.size();

    for (int i = -(size2 - 1); i < size2; i++) {
      for (int j = -(size2 - 1); j < size2; j++) {
        int temp = 0;

        for (int x1 = 0; x1 < size1; x1++) {
          int x2 = x1 + i;
          if (x2 >= size2) {
            break;
          }
          if (x2 < 0) {
            continue;
          }
          for (int y1 = 0; y1 < size1; y1++) {
            int y2 = y1 + j;
            if (y2 >= size2) {
              break;
            }
            if (y2 < 0) {
              continue;
            }
            temp += im1[x1][y1] == 1 && im2[x2][y2] == 1;
          }
        }

        resp = max(resp, temp);
      }
    }

    return resp;
  }

public:
  int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
    int answer = 0;

    answer = count(img1, img2);

    return answer;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> img1 = {{0, 1}, {0, 0}};
  vector<vector<int>> img2 = {{0, 0}, {1, 0}};

  int answer = solution.largestOverlap(img1, img2);
  cout << answer << endl;

  return 0;
}