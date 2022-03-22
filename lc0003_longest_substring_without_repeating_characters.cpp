#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0, rk = 0;
    unordered_set<char> set;
    for (int i = 0; i < s.length(); ++i) {
      if (rk == s.length()) {
        break;
      }
      if (i != 0) {
        set.erase(s[i-1]);
      }
      while (rk < s.length() && !set.count(s[rk])) {
        set.insert(s[rk]);
        ++rk;
      }
      ans = max(ans, rk - i);
    }
    return ans;
  }
};

void test1() {
  string s = "asad";
  Solution solu;
  int ans = solu.lengthOfLongestSubstring(s);
  cout << ans << endl;
  return;
}

int main() {
  test1();
  return 0;
}