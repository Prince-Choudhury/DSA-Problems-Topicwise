#include <iostream>
using namespace std;

int main() {
    int n = 5;  

    for (int i = 1; i <= n; i++) {
        // Print leading spaces to center the pyramid
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print increasing numbers starting from i
        for (int j = 0; j < i; j++) {
            cout << i + j;
        }

        // Print decreasing numbers starting from the second-last number of the row
        for (int j = i - 2; j >= 0; j--) {
            cout << i + j;
        }

        cout << endl;  
    }

    return 0;
}
