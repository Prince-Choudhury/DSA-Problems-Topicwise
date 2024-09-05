#include <iostream>
using namespace std;

int main() {
    int n = 6;  

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // For the first and last row, print full stars
        if (i == 1 || i == n) {
            // Print stars in the first row or last row
            for (int j = 1; j <= 2 * i - 1; j++) {
                cout << "*";
            }
        } else {
            // For middle rows, print a hollow structure
            cout << "*";  // First star
            for (int j = 1; j <= 2 * i - 3; j++) {
                cout << " ";  // Hollow space
            }
            cout << "*";  // Last star
        }

        cout << endl;  // Move to the next line after each row
    }

    return 0;
}
