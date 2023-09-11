#include <iostream>
using namespace std;
int main(){
    int n ; cin >> n;
int a[n];
for(int i=0; i<n; i++) cin >> a[i];
int temp; // biến tạm temp
    for (int i = 0; i < n-1; i++){
	for (int j = 0; j < n-1-i; j++){
		if (a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    for(int k=0; k<n; k++) cout << a[k] << " ";
                    cout << endl;
;			}
		}
	}
	return 0;
}
