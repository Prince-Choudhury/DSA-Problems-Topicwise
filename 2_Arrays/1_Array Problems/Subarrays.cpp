//Brute-force Approach

#include <iostream>
using namespace std;

void printAllSubarrays(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
           cout<<arr[j];
        }
        cout<<endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllSubarrays(arr, n);
    return 0;
}


/*
//Optimized Approach (Sliding Window)

#include <iostream>
#include <vector>
using namespace std;

void slidingWindowPrintSubarrays(int arr[], int n) {
    // Sliding window doesn't exactly apply here for printing, but we can directly use a two-loop approach
    for (int i = 0; i < n; i++) {
        vector<int> window;
        for (int j = i; j < n; j++) {
            window.push_back(arr[j]); // Push each element into window (subarray)
            
            // Printing the subarray:
            for (int k = 0; k < window.size(); k++) {
                cout << window[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    slidingWindowPrintSubarrays(arr, n);
    return 0;
}
*/