#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int *arr, int size, int index) {
	//base case
	if(index >= size) {
		return ;
	}
	
	//recursive call
	printArray(arr, size, index+1);

	//processing
	cout << arr[index] << " ";
}

bool searchArray(int arr[], int size, int target, int index ) {
	//base cass
	if(index >= size) {
		return false;
	}
	if(arr[index] == target) {
		return true;
	}

	//recursive call
	bool aageKaAns =  searchArray(arr, size, target, index+1);
	return aageKaAns;
}

void findMin(int arr[], int size, int index, int &mini) {
	//base case
	if(index >= size ) {
		return;
	}

	//processing
	mini = min(mini, arr[index]);

	//Recursive call
	findMin(arr, size, index+1 , mini);
	
}

//solve() -> store even numbers in array into vector
void solve(int arr[], int size, int index, vector<int> &ans) {
	//base case
	if(index >= size) {
		return;
	}
	//processing
	if(arr[index]%2 == 0) {
		//even
		ans.push_back(arr[index]);
	}
	//Recursive call
	solve(arr, size, index+1, ans);
}

void printDigits(int num, vector<int>& ans) {
	//base case
	if(num == 0) {
		return;
	}

	//processing
	int digit = num % 10;

	//Recursive call
	printDigits(num/10,ans);

	//processing
	ans.push_back(digit);
}

int main() {

	int num = 4217;
	vector<int> ans;
	printDigits(num,ans);

	for(int num: ans) {
		cout << num << endl;
	}
	
	
	// int arr[] = {11,20,31,40,51};
	// int size = 5;
	// int index = 0;
	// vector<int> ans;
	// solve(arr, size, index, ans);

	// //printing vector
	// for(int num: ans) {
	// 	cout << num << " ";
	// }

	// for(int i=0; i<ans.size(); i++) {
	// 	cout << ans[i] << " ";
	// }

	// int mini = INT_MAX;
	// findMin(arr, size, index, mini);
	// cout << "Minimum number in array: " << mini << endl;

	
	// int target = 50;
	// cout <<"Tagret found or not: "<< searchArray(arr,size,target, index) << endl;
	//printArray(arr,size, index);
	return 0;
}

/*

When recursion unwinds (after the recursive calls have finished), it starts processing in reverse order from how the calls were made.

Let's break this down:

At the deepest level (base case):

The recursion reaches a point where no more recursive calls are made (e.g., when num == 0). It stops further recursion and starts unwinding.
During unwinding:

Each function call that was paused while waiting for the next call's result now resumes. The stored value (digit) from the paused function call is processed.

In your example, after the recursive call printDigits(num/10, ans);, the function doesn't continue until it reaches the base case (which is when num == 0).

Unwinding happens in reverse order: The last recursive call finishes first, then the second-to-last, and so on.

Processing on Unwinding
After the recursive call finishes, processing resumes. For the function printDigits(num, ans);, this is when the digit is pushed into the ans vector.

The last digit (num % 10) is pushed onto the ans vector as the function unwinds.
Example with num = 4217
First call: printDigits(4217) → pauses at printDigits(421)
Second call: printDigits(421) → pauses at printDigits(42)
Third call: printDigits(42) → pauses at printDigits(4)
Fourth call: printDigits(4) → pauses at printDigits(0) → base case, stops recursion.
Unwinding:
4th call (unwinds): num = 4, ans.push_back(4) → ans = [4]
3rd call (unwinds): num = 42, ans.push_back(2) → ans = [4, 2]
2nd call (unwinds): num = 421, ans.push_back(1) → ans = [4, 2, 1]
1st call (unwinds): num = 4217, ans.push_back(7) → ans = [4, 2, 1, 7]

*/