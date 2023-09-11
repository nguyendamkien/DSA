#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int key = a[i];
        for(int j = i-1; j>=0; j--)
        {
            if(key < a[j])
            {
                a[j+1] = a[j];
                a[j] = key;

            }
        }
        for(int p=0; p<n; p++) cout << a[p] << " ";
                cout << endl;
    }

    for(int p=0; p<n; p++) cout << a[p] << " ";
    return 0;
}
