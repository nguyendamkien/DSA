#include <iostream>

using namespace std;

void merge_(int a[], int l, int m, int r) // Gộp hai mảng con a[l...m] và a[m+1..r]
{
    int m1 = m-l+1;
    int m2 = r-m;
    int *b = new int [m1];
    int *c = new int [m2];

    for(int i=0; i<m1; i++)
    {
        b[i] = a[l+i];
    }
    for(int i=0; i<m2; i++)
    {
        c[i] = a[m+1+i];
    }
    int t1 = 0;
    int t2 = 0;
    int k = l;
    while(t1<m1 && t2<m2 )
    {
        if(b[t1] < c[t2])
        {
            a[k] = b[t1];
            k++;
            t1++;
        }
        else
        {
            a[k] = c[t2];
            k++;
            t2++;
        }
    }
    while(t1<m1)
    {
        a[k] = b[t1];
        k++;
        t1++;
    }
    while(t2<m2)
    {
        a[k] = c[t2];
        k++;
        t2++;
    }

    delete[] b;
    delete[] c;
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l+(r-l)/2;

        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);

        merge_(a, l, m, r);
    }
}

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;
}
