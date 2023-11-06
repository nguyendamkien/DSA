#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    char a[m], b[n];
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int s[m+1][n+1]; // luu do dai day con chung dai nhat cua i ki tu dau cua a, j ki tu dau cua b
    for (int i = 0; i <= m; i++)
        for (int j = 0; j<= n; j++)
            s[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[j-1] == b[i-1]) {
                s[i][j] = s[i-1][j-1] + 1;
            } else {
                s[i][j] = max(s[i-1][j], s[i][j-1]);
            }
        }
    cout << s[n][m]; // do dai day con chung dai nhat
    return 0;
}
