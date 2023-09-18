#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void addlast(Node* &head, Node* &tail, int m) {
    Node* pnew = new Node;
    pnew->data = m;
    pnew->next = nullptr;
    pnew->prev = nullptr;
    if(head == nullptr) {
        head = pnew;
        tail = pnew;
    }
    else {
        tail->next = pnew;
        pnew->prev = tail;
        tail = pnew;
    }
}

/*void print(Node* tail)
{
    Node* p = tail;
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->prev;
    }
}*/

int count_triplets(Node* &head, Node* &tail){
    int dem = 0;
    Node* p = head->next;
    while(p->next != nullptr){
        if(p->data + p->next->data + p->prev->data == 0) dem++;
        p = p->next;
    }
    return dem;

}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        addlast(head, tail, m);
    }
    cout << count_triplets(head, tail) << endl;
    return 0;
}
