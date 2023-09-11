#include <iostream>
#include <algorithm>

using namespace std;

static int x = 0;

int partition_(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while(true)
    {
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if(left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);

    for (int i = low; i <= high; i++) cout << a[i] << " ";
    cout << "\n\n";
    return left;
}

void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int p = partition_(a,low,high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;


    return 0;
}
