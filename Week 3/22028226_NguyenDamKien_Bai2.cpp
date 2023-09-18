#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

};

/*struct Queue{
    Node* head;
};*/

Node* insert_(Node* &head, int m, int x)
{
    Node* pnew = new Node ;
    pnew->value = x;
    pnew->next = nullptr;
    if(m == 0) {
        if(head == nullptr)
        {
            head = pnew;
            return head;
        }
        else {

            pnew -> next = head;
            head = pnew;
            return head;
        }
    }
    else {
        Node* p = head;
        for(int i=0; i<m-1; i++) {
            p = p->next;
        }
        Node* p1 = p->next;
        p->next = pnew;
        pnew->next = p1;
    }
    return head;
}

Node* delete_(Node* &head, int m) {
    Node* p = head;
    for(int i=0; i<m-1; i++) {
        p == p->next;
    }
    Node* p1 = p->next->next;
    Node* p2 = p->next;
    p->next = p1;
    delete p2;
    return head;
}

void print(Node* head) {
    Node* p = head;
    while(p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
}

int main(){
    int n; cin >> n;
    Node* head = nullptr;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        if( s == "insert") {
            int m, x;
            cin >> m >> x;
            insert_(head,m,x);
        }
        else if(s == "delete") {
            int m;
            cin >> m;
            delete_(head, m);
        }
    }
    print(head);
    return 0;
}
