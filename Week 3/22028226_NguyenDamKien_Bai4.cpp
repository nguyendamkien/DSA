#include <iostream>

using namespace std;

struct Queue{
    int data;
    Queue* next;
};

void enqueue(Queue* &head, int m) {
    Queue* pnew = new Queue;
    pnew->data = m;
    pnew->next = nullptr;
    if(head == nullptr) {
        head = pnew;
    }
    else{
        Queue* p = head;
        while(p->next != nullptr) p = p->next;
        p->next = pnew;
    }

}

void dequeue(Queue* &head){
    Queue* p = head;
    head = p->next;
    delete p;
}

void print(Queue* head){
    Queue* p = head;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n; cin >> n;
    Queue* head = nullptr;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        if(s == "enqueue") {
            int m; cin >> m;
            enqueue(head, m);
        }
        else if(s == "dequeue") {
            dequeue(head);
        }
    }
    print(head);
    return 0;
}
