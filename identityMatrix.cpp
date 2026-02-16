#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[n][n];
    bool isIdentity = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];

            if (i == j && matrix[i][j] != 1) {
                isIdentity = false;
            } 
            else if (i != j && matrix[i][j] != 0) {
                isIdentity = false;
            }
        }
    }

    if (isIdentity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}
