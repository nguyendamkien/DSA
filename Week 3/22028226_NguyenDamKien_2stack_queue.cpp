#include <bits/stdc++.h>

using namespace std;

struct Queue{
    stack<int> s1, s2;

    void enqueue(int m){
        s1.push(m);
    }

    void dequeue(){
        while(s1.size() > 1){
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void print(){
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
            cout << s1.top() << " ";
            while(!s2.empty()){
                cout << s2.top() << " ";
                s1.push(s2.top());
                s2.pop();
            }
    }
};

int main(){
    Queue q;
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        if(s == "enqueue") {
            int m; cin >> m;
            q.enqueue(m);

        }
        else if(s == "dequeue") {
            q.dequeue();
        }
    }

    q.print();
    return 0;
}
