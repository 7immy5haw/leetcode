#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class AnimalShelf {
private:
  // int index;
  deque<pair<int, int>> deq_cat;
  deque<pair<int, int>> deq_dog;

public:
  AnimalShelf() {
  }
  
  void enqueue(vector<int> animal) {
    if (animal[1] == 0) {
      deq_cat.push_back({animal[0], animal[1]});
    } else if (animal[1] == 1) {
      deq_dog.push_back({animal[0], animal[1]});
    }
  }
  
  vector<int> dequeueAny() {
    if (deq_dog.empty() && deq_cat.empty()) {
      return vector<int>{-1, -1};
    }
    if (deq_dog.empty() && !deq_cat.empty()) {
      return dequeueCat();
    }
    if (!deq_dog.empty() && deq_cat.empty()) {
      return dequeueDog();
    }
    if (deq_dog.front().first < deq_cat.front().first) {
      return dequeueDog();
    }
    return dequeueCat();
  }
  
  vector<int> dequeueDog() {
    if (deq_dog.empty()) {
      return vector<int>{-1, -1};
    }
    vector<int> dog = {deq_dog.front().first, deq_dog.front().second};
    deq_dog.pop_front();
    return dog;
  }
  
  vector<int> dequeueCat() {
    if (deq_cat.empty()) {
      return vector<int>{-1, -1};
    }
    vector<int> cat = {deq_cat.front().first, deq_cat.front().second};
    deq_cat.pop_front();
    return cat;
  }
};

void test1() {
  AnimalShelf* obj = new AnimalShelf();
  obj->enqueue({0, 0});
  obj->enqueue({1, 0});
  obj->enqueue({2, 1});
  vector<int> param_1 = obj->dequeueDog();
  vector<int> param_2 = obj->dequeueCat();
  vector<int> param_3 = obj->dequeueAny();
  cout << param_1[0] << " " << param_1[1] << endl;
  cout << param_2[0] << " " << param_2[1] << endl;
  cout << param_3[0] << " " << param_3[1] << endl;
  return;
}

int main() {
  test1();
  return 0;
}