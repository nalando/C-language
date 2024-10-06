// 一些好用的內建資料結構

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <bitset>
using namespace std;

int main(){
    // 1. vector: 可存放多個元素，長度可隨意伸縮
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector: ";
    for(int i=0; i<vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
    vec.push_back(1);
    for(int i=0; i<vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
    vec.pop_back();
    for(int i=0; i<vec.size(); i++) cout << vec[i] << " ";
    cout << endl;
    vec.clear();
    cout << "Vector size: " << vec.size() << endl;
    
    // 2. string: 字串類別
    string str = "Hello, World!";
    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;
    str += " I am alive!";
    cout << "String after concatenation: " << str << endl;
    cout << "Substring: " << str.substr(6, 5) << endl;

    // 3. deque: 可以在最前面加東西和刪東西的vector
    deque<int> dq = {1, 2, 3, 4, 5};
    cout << "Deque: ";
    for(int i=0; i<dq.size(); i++) cout << dq[i] << " ";
    cout << endl;
    dq.push_front(0);
    for(int i=0; i<dq.size(); i++) cout << dq[i] << " ";
    cout << endl;
    dq.pop_front();
    for(int i=0; i<dq.size(); i++) cout << dq[i] << " ";
    cout << endl;
    dq.clear();
    cout << "Deque size: " << dq.size() << endl;
    
    // 4. list:一個雙向鏈結(double linked)結構，可以用很快的方式知道每一項的前項及後項
    list<int> lst = {1, 2, 3, 4, 5};
    cout << "List: ";
    for(auto it=lst.begin(); it!=lst.end(); it++) cout << *it << " ";
    cout << endl;
    lst.push_front(0);
    for(auto it=lst.begin(); it!=lst.end(); it++) cout << *it << " ";
    cout << endl;
    lst.pop_front();
    for(auto it=lst.begin(); it!=lst.end(); it++) cout << *it << " ";
    cout << endl;
    lst.insert(lst.begin(),1,2);
    for(auto it=lst.begin(); it!=lst.end(); it++) cout << *it << " ";
    cout << endl;
    lst.erase(lst.begin());
    for(auto it=lst.begin(); it!=lst.end(); it++) cout << *it << " ";
    cout << endl;
    lst.clear();
    cout << "List size: " << lst.size() << endl;

    // 5. stack: 後進先出(LIFO)的結構
    stack<int> stk;
    cout << "Stack: ";
    for(int i=0; i<5; i++) stk.push(i);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    cout << "Stack size: " << stk.size() << endl;
    
    // 6. queue: 先進先出(FIFO)的結構
    queue<int> que;
    cout << "Queue: ";
    for(int i=0; i<5; i++) que.push(i);
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
    cout << "Queue size: " << que.size() << endl;
    
    // 7. priority_queue: 有優先度的queue，使用內建函式實現二叉堆(binary heap)結構
    priority_queue<int> pq;
    cout << "Priority Queue: ";
    for(int i=5; i>=0; i--) pq.push(i);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    cout << "Priority Queue size: " << pq.size() << endl;
    
    // 8. pair: 把兩個變數綁在一起，變成一個變數
    pair<int, string> p(1, "Hello");
    cout << "Pair: " << p.first << ", " << p.second << endl;
    
    // 9. set: 集合類別，元素不重複
    set<int> s = {1, 2, 3, 4, 5};
    cout << "Set: ";
    for(auto it=s.begin(); it!=s.end(); it++) cout << *it << " ";
    cout << endl;
    s.insert(2);
    for(auto it=s.begin(); it!=s.end(); it++) cout << *it << " ";
    cout << endl;
    s.erase(2);
    for(auto it=s.begin(); it!=s.end(); it++) cout << *it << " ";
    cout << endl;
    s.clear();
    cout << "Set size: " << s.size() << endl;
    
    // 10. map: 字典類別，元素不重複，且每個元素都有一個對應的值
    map<string, int> m = {{"Apple", 1}, {"Banana", 2}, {"Cherry", 3}};
    cout << "Map: ";
    for(auto it=m.begin(); it!=m.end(); it++) cout << it->first << ": " << it->second << " ";
    cout << endl;
    m["Apple"] = 4;
    for(auto it=m.begin(); it!=m.end(); it++) cout << it->first << ": " << it->second << " ";
    cout << endl;
    m.erase("Banana");
    for(auto it=m.begin(); it!=m.end(); it++) cout << it->first << ": " << it->second << " ";
    cout << endl;
    m.clear();
    cout << "Map size: " << m.size() << endl;
    
    // 11. bitset: 僅有0或1的一個array
    bitset<10> bs(0b11001010);
    cout << "Bitset: " << bs << endl;
    cout << "Count: " << bs.count() << endl;
    cout << "Set: " << bs.set(2) << endl;
    cout << "Reset: " << bs.reset(2) << endl;
    cout << "To integer: " << bs.to_ulong() << endl;
    
    return 0;


}