#include <iostream>

using namespace std;

struct Stack{
    int data;
    Stack* next;
    Stack* prev;
};

void push(Stack* &head, Stack* &tail, int m) {
    Stack* pnew = new Stack;
    pnew->data = m;
    pnew->next = nullptr;
    pnew->prev = nullptr;
    if(head == nullptr){
        head = pnew;
        tail = pnew;
    }
    else {
        tail->next = pnew;
        pnew->prev = tail;
        tail = pnew;
        tail->next = nullptr;
    }
}

void pop(Stack* &head, Stack* &tail) {
    Stack* p = tail;
    tail = p->prev;
    tail->next = nullptr;
    delete p;
}

void print(Stack* head){
    Stack* p = head;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}


int main()
{
    int n; cin >> n;
    Stack* head = nullptr;
    Stack* tail = nullptr;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        if(s == "push") {
            int m; cin >> m;
            push(head, tail, m);

        }
        else if(s == "pop") {
            pop(head, tail);
        }
    }
    print(head);
    return 0;
}
