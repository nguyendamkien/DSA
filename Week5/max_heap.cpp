#include <bits/stdc++.h>

using namespace std;

void heapify(vector <int> &a, int n, int i)
{
    int current = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[current]) current = left;
    if(right < n && a[right] > a[current] ) current = right;
    if(current != i) {
        swap(a[i], a[current]);
        heapify(a, n, current);
    }
}

void builtmaxheap(vector <int> &a)
{
    int n = a.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
}

void print(vector<int> &a){
    int n = a.size();
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

void swim(vector<int> &a, int i)
{
    int current = i;
    int father = (i-1)/2;
    if(father >= 0 && a[father] < a[current]) current = father;
    if(current != i){
        swap(a[i], a[current]);
        swim(a,current);
    }
}

void insert_(vector<int> &a, int k)
{
    a.push_back(k);
    int n = a.size();
    swim(a,n-1);
}

void delete_max(vector<int> &a){
    int n = a.size();
    if(n == 0) return;
    swap(a[0], a[n-1]);
    a.pop_back();
    n = a.size();
    heapify(a,n,0);
}

void delete_(vector<int> &a, int k) {
    int n = a.size();
    for(int i=0; i<n; i++) {
    if(a[i] == k){
        swap(a[i], a[n-1]);
        a.pop_back();
        n = a.size();
        heapify(a,n,i);
    } else continue;
    }
    return;
}

int main()
{
    vector <int> arr = {2, 1, 10, 6, 3, 7, 8, 13, 20};
    builtmaxheap(arr);
    print(arr);
    insert_(arr, 14);
    insert_(arr,0);
    insert_(arr,35);
    print(arr);
    //delete_max(arr);
    //print(arr);
    delete_(arr,6);
    delete_(arr,13);
    delete_(arr,35);
    print(arr);
    return 0;
}
