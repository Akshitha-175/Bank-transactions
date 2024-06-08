#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Node {
private:
  int an;
  int cb;
  Node *next;

public:
  Node(int d) {
    an = d;
    cb = 1000;
    next = NULL;
  }
  friend class SLL;
};
class SLL {
public:
  Node *first;
  Node *last;
  int len;

public:
  SLL() {
    first = NULL;
    last = NULL;
    len = 0;
  }
  void insertnode(int);
  int search(int);
  void print();
  void searchin(int, char, int);
  void searchr(int, char, int);
  void balance(int);
  void high();
  void funv(int);
};
class Node2 {
private:
  int AN;
  char ch;
  int m;
  Node2 *next;
  Node2 *prev;

public:
  Node2() {
    AN = 0;
    ch = '0';
    m = 0;
    next = NULL;
    prev = NULL;
  }
  Node2(int a, char c, int k) {
    AN = a;
    ch = c;
    m = k;
    next = NULL;
    prev = NULL;
  }
  friend class DLL;
};
class DLL {
public:
  Node2 *head;
  Node2 *tail;
  Node2 *cursor;
  int l;

public:
  DLL() {
    head = new Node2();
    tail = new Node2();
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    cursor = head;
    l = 0;
  }
  void insert(int, char, int);
  void insertafterk(int, char, int, int, SLL &);
  void printlist();
  void funf(int, SLL &);
  void funr(int, SLL &);
  void removeafter(int, int);
  void removebefore(int, int, SLL &);
  void fun(SLL &);
  void funs(int);
};
void SLL::funv(int x) {
  Node *temp = first;
  while (temp != NULL) {
    if (temp->an == x) {
      cout << temp->cb << "\n";
      break;
    }
    temp=temp->next;
  }
}
void SLL::high() {
  int max = first->cb;
  Node *temp = first;
  while (temp != NULL) {
    if (temp->cb > max)
      max = temp->cb;
    temp = temp->next;
  }
  temp = first;
  vector<int> a;
  while (temp != NULL) {
    if (temp->cb == max)
      a.push_back(temp->an);
    temp = temp->next;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < (int)a.size(); i++)
    cout << a[i] << " ";
  cout << '\n';
}
void SLL::balance(int x) {
  Node *temp = first;
  int ans = 0;
  while (temp != NULL) {
    if (temp->cb >= x)
      ans++;
    temp = temp->next;
  }
  cout << ans << '\n';
}
void DLL::funs(int y) {
  if(cursor==head) return;
  else{
  Node2 *temp = head->next;
  while (temp != cursor) {
    if (temp->AN == y) {
      cout << temp->AN << " " << temp->ch << " " << temp->m << '\n';
    }
    temp=temp->next;
  }
}
}
void DLL::removeafter(int a, int m) {
  if(cursor==tail) return;
  else{
    int check=0;
  Node2 *temp = cursor->next, *temp1;
  while (temp != tail && m != 0) {
    check=0;
    if (temp->AN == a) {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      // temp = temp->prev;
      // temp1 = temp;
      // delete temp1;
      temp1=temp->next;
      delete temp;
      m--;
      check=1;
    }
   if(check==1) temp = temp1;
    else temp=temp->next;
     }
}
}
void DLL::removebefore(int a, int m, SLL &list) {
    if(cursor==head) return;
  else{
    int check=0;
  Node2 *temp = cursor->prev, *temp1=head;
 // m=-1*m;
  while (temp != head && m != 0) {
    check=0;
    if (temp->AN == a) {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      list.searchr(temp->AN, temp->ch, temp->m);
      // temp = temp->prev;
      // temp1 = temp;
      // delete temp1;
      temp1=temp->prev;
      delete temp;
      m--;
      check=1;
    }
   if(check==1) temp = temp1;
    else temp=temp->prev;
  }
}
}
void DLL::insertafterk(int x, char c, int y, int k, SLL &list) {
  bool flag = false;
  if (list.search(x)) {
    Node2 *temp;
    temp = head->next;
    for (int i = 1; i < k; i++) {
      if (temp == cursor)
        flag = true;
      temp = temp->next;
    }
    Node2 *toadd = new Node2(x, c, y);
    toadd->next = temp->next;
    temp->next->prev = toadd;
    toadd->prev = temp;
    temp->next = toadd;
    if (!flag) {
      list.searchin(x, c, y);
    }
  }
}
void DLL::funr(int y, SLL &list1) {
  while (y != 0 && cursor != head) {
    list1.searchr(cursor->AN, cursor->ch, cursor->m);
    cursor = cursor->prev;
    y--;
  }
  // cursor=cursor->next;
}
void SLL::searchr(int x, char c, int y) {
  Node *temp = first;
  while (temp != NULL) {
    if (temp->an == x) {
      if (c == 'D')
        temp->cb -= y;
      else
        temp->cb += y;
      break;
    }
    temp = temp->next;
  }
}
void DLL::funf(int x, SLL &list1) {
  while (x != 0 && cursor != tail) {
    cursor = cursor->next;
    list1.searchin(cursor->AN, cursor->ch, cursor->m);
    x--;
  }
  // cursor=cursor->prev;
}
void DLL::fun(SLL &list1) {
  while (cursor != tail) {
    cursor = cursor->next;
    list1.searchin(cursor->AN, cursor->ch, cursor->m);
  }
  // cursor=cursor->prev;
}
void SLL::searchin(int x, char c, int y) {
  // cout<<" hi"<<endl;
  Node *temp = first;
  while (temp != NULL) {
    if (temp->an == x) {
      if (c == 'D')
        temp->cb += y;
      else
        temp->cb -= y;
    }
    temp = temp->next;
  }
}
void DLL::insert(int x, char c, int y) {
  Node2 *toadd = new Node2(x, c, y);
  tail->prev->next = toadd;
  toadd->next = tail;
  toadd->prev = tail->prev;
  tail->prev = toadd;
  cursor = head;
  l++;
}
void DLL::printlist() {
  Node2 *temp;
  temp = head->next;
  while (temp != tail) {
    cout << temp->AN << " " << temp->ch << " " << temp->m << '\n';
    temp = temp->next;
  }
}
void SLL::print() {
  // cout<<" print";
  Node *temp;
  temp = first;
  // cout<<first->an<<" * ";
  while (temp != NULL) {
    cout << temp->an << " " << temp->cb << "\n";
    temp = temp->next;
  }
  cout << endl;
}
void SLL::insertnode(int d) {
  Node *toadd = new Node(d);

  if (first == NULL) {
    // cout<<d<<" 1 ";
    first = toadd;
    last = toadd;
    len++;
  } else {
    // cout<<d<<" 5 ";
    last->next = toadd;
    last = toadd;
    len++;
  }
}
int SLL::search(int d) {
  Node *temp;
  temp = first;
  while (temp != NULL) {
    if (temp->an == d)
      return 1;
    temp = temp->next;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  SLL list1;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    list1.insertnode(a);
  }
  int t,t1;
  cin >> t;
  int x, y;
  char c;
  DLL list2;
  t1=t;
  for (int i = 0; i < t; i++) {
    // cout<<i<<" ";
    cin >> x >> c >> y;
    if (list1.search(x)) {
      // cout<<" valid "<<endl;
      list2.insert(x, c, y);
    } 
    else t1--;
        }
  string s;
  while (true) {
    cin >> s;
   // cout << s << endl;

    if (s == "F") {
      int x;
      cin >> x;
      // cout<<"x="<<x<<endl;
      list2.funf(x, list1);
     //  list1.print();
    }
   else if (s == "R") {
      int y;
      cin >> y;
      list2.funr(y, list1);
     // list1.print();
    }
   else if (s == "I") {
      int x, y, k;
      char c;
      cin >> x >> c >> y >> k;
      if (k <= t1) {
        list2.insertafterk(x, c, y, k, list1);
      }
    // list2.printlist();
    }
  else  if (s == "D") {
      int a, m;
      cin >> a >> m;
      if (m > 0) {
        list2.removeafter(a, m);
      }
      else
        list2.removebefore(a, abs(m), list1);
    }
  else  if (s == "C") {
      list2.fun(list1);
    }
   else if (s == "S") {
      int y;
      cin >> y;
      if (list1.search(y)) {
        list2.funs(y);
      }
    }
   else if (s == "G") {
      int x;
      cin >> x;
      list1.balance(x);
    }
   else if (s == "M") {
      list1.high();
    }
   else if (s == "V") {
      int x;
      cin >> x;
      list1.funv(x);
    } 
    else {
      break;
    }

    // cout<<endl;
  }

  //  list2.printlist();
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}
