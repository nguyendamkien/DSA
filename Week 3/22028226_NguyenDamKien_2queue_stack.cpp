#include <bits/stdc++.h>

using namespace std;

struct Stack{
    queue<int> q1, q2;
    void push_(int n){
        q1.push(n);
    }
    void pop_(){
        while(q1.size() > 1){
            q2.push(q1.front()); // lay dau
            q1.pop();
        }
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void print(){
        while(!q1.empty()){
            cout << q1.front() << " ";
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
};



int main(){
    Stack s1;
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        if(s == "push") {
            int m; cin >> m;
            s1.push_(m);
        }
        else if(s == "pop") {
            s1.pop_();
        }
    }

    s1.print();
    return 0;
}
