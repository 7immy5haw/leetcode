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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* ptr1 = dummy;
    ListNode* ptr2 = dummy;
    while (n > 0) {
      ptr1 = ptr1->next;
      --n;
    }
    while (ptr1->next) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    ListNode* del = new ListNode();
    del = ptr2->next;
    ptr2->next = ptr2->next->next;
    delete del;
    del = nullptr;
    head = dummy->next;
    delete dummy;
    dummy = nullptr;
    return head;
  }
};

ListNode* listGenerator(vector<int> &nums) {
  ListNode *head = new ListNode();
  ListNode *dummy = head;
  for (int i = 0; i < nums.size(); ++i) {
    ListNode *tmp = new ListNode(nums[i]);
    head->next = tmp;
    head = head->next;
  }
  return dummy->next;
}

void printList(ListNode *num) {
  ListNode *ptr = num;
  while (ptr) {
    cout << ptr->val;
    ptr = ptr->next;
  }
  cout << endl;
  return;
}

void test1() {
  vector<int> list = {1,2,3,4,5,6};
  ListNode* head = listGenerator(list);
  Solution solu;
  head = solu.removeNthFromEnd(head, 3);
  printList(head);
  return; 
}

int main() {
  test1();
  return 0;
}