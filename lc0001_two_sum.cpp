#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
      mp.insert(make_pair(nums[i], i + 1));
    }

    int ans1, ans2;
    for (int i = 0; i < nums.size(); ++i) {
      if (mp.count(target - nums[i]) > 0 && mp[target - nums[i]] != i + 1) {
        ans1 = i;
        ans2= mp[target - nums[i]] - 1;
        break;
      }
    }
    return vector<int>{ans1, ans2};
  }
};

void test1() {
  vector<int> nums = {2, 3, 4};
  int target = 6;
  Solution solu;
  vector<int> ans = solu.twoSum(nums, target);
  for (auto i:ans) {
    cout << i << " ";
  }
  cout << endl;
  return;
}

void test2() {
  vector<int> nums = {3, 3};
  int target = 6;
  Solution solu;
  vector<int> ans = solu.twoSum(nums, target);
  for (auto i:ans) {
    cout << i << " ";
  }
  cout << endl;
  return;
}

int main() {
  test1();
  test2();

  // system("pause");

  return 0;
}