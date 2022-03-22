#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    bool carry = false;
    ListNode *head = new ListNode();
    ListNode *dummy = head;
    while (l1 || l2) {
      ListNode *tmp = new ListNode();
      if (l1 && l2) {
        int sum = l1->val + l2->val + carry;
        tmp->val = sum % 10;
        head->next = tmp;
        head = head->next;
        carry = sum > 9 ? true : false;
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1) {
        int sum = l1->val + carry;
        tmp->val = sum % 10;
        head->next = tmp;
        head = head->next;
        carry = sum > 9 ? true : false;
        l1 = l1->next;
      } else if (l2) {
        int sum = l2->val + carry;
        tmp->val = sum % 10;
        head->next = tmp;
        head = head->next;
        carry = sum > 9 ? true : false;
        l2 = l2->next;
      }
    }
    if (carry) {
      ListNode *tmp = new ListNode(1);
      head->next = tmp;
    }
    return dummy->next;
  }
};

ListNode *numberGenerator(vector<int> &nums) {
  // ListNode *head = new ListNode();
  // ListNode *dummy = head;
  // for (int i = 0; i < nums.size(); ++i) {
  //   ListNode *tmp = new ListNode();
  //   tmp->val = nums[i];
  //   head = tmp;
  //   head = head->next;
  // }
  // return dummy->next;

  ListNode *head = new ListNode();
  ListNode *dummy = head;
  for (int i = 0; i < nums.size(); ++i) {
    ListNode *tmp = new ListNode(nums[i]);
    head->next = tmp;
    head = head->next;
  }
  return dummy->next;
}

void printNumber(ListNode *num) {
  ListNode *ptr = num;
  while (ptr) {
    cout << ptr->val;
    ptr = ptr->next;
  }
  cout << endl;
  return;
}

void test1() {
  vector<int> num1 = {1,2,3};
  vector<int> num2 = {1,2,3};
  ListNode *l1 = numberGenerator(num1);
  ListNode *l2 = numberGenerator(num2);
  Solution solu;
  ListNode *ans = solu.addTwoNumbers(l1, l2);
  printNumber(ans);
  return;
}

void test2() {
  vector<int> num1 = {1, 1, 1};
  vector<int> num2 = {9, 9, 9, 9};
  ListNode *l1 = numberGenerator(num1);
  ListNode *l2 = numberGenerator(num2);
  Solution solu;
  ListNode *ans = solu.addTwoNumbers(l1, l2);
  printNumber(ans);
  return;
}

int main() {
  test1();
  test2();
  return 0;
}