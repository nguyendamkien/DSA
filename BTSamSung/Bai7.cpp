#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void floodfill(vector<vector<int>>& image, int row, int col, int target_color, int new_color) {
    int rows = image.size();
    int cols = image[0].size();

    stack<pair<int, int>> stk;
    stk.push({row, col});

    while (!stk.empty()) {
        pair<int, int> curr = stk.top();
        stk.pop();

        int r = curr.first;
        int c = curr.second;

        if (image[r][c] == target_color) {
            image[r][c] = new_color;
            if (r > 0) {
                stk.push({r - 1, c});
            }
            if (r < rows - 1) {
                stk.push({r + 1, c});
            }
            if (c > 0) {
                stk.push({r, c - 1});
            }
            if (c < cols - 1) {
                stk.push({r, c + 1});
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> image(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> image[i][j];
        }
    }
    int row, col;
    cin >> row >> col;
    int target_color, new_color;
    cin >> target_color;
    cin >> new_color;
    floodfill(image, row, col, target_color, new_color);
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
