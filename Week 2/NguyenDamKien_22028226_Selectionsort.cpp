#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int k = 0;
    for(int i=k; i<n; i++)
    {
        int i_min = k;
        for(int j=k; j<n; j++)
        {
            if(a[j] < a[i_min]) i_min = j;
        }
        swap(a[i], a[i_min]);
        for(int p=0; p<n; p++) cout << a[p] << " ";
        cout << endl;
        k++;
    }
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;
}
