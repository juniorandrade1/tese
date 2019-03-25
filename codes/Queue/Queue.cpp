#include "../BST/OrderedMap.cpp"

using namespace std;

namespace Retroactivity {
  template<typename T>
  class FullQueue {
    BST::OrderedMap<int, T> enq;
    BST::OrderedMap<int, bool> deq;
  public:
    void Insert_Enqueue(int t, const T &x) {
      enq.insert(t, x);
    }
    void Insert_Dequeue(int t) {
      deq.insert(t, 1);
    }
    void Delete_Enqueue(int t) {
      enq.remove(t);
    }
    void Delete_Dequeue(int t) {
      deq.remove(t);
    }
    T getKth(int t, int k) {
      int f = deq.count(t);
      return enq.kth(k + f);
    }
    T front(int t) {
      return getKth(t, 1);
    }
  };

  template<typename T>
  class PartialQueue {
    BST::OrderedMap<int, T> enq;
    BST::OrderedMap<int, bool> deq;
  public:
    void Insert_Enqueue(int t, T &x) {
      enq.insert(t, x);
    }
    void Insert_Dequeue(int t) {
      deq.insert(t, 1);
    }
    void Delete_Enqueue(int t) {
      enq.remove(t);
    }
    void Delete_Dequeue(int t) {
      deq.remove(t);
    }
    T getKth(int t, int k) {
      int f = deq.count(t);
      return enq.kth(k + f);
    }
    T front() {
      return getKth((int)1e9, 1);
    }
  };
}