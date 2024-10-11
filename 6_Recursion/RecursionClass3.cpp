// 1. Check Array is sorted or not 

#include <iostream>
#include<vector>
using namespace std;

bool checkSorted(int arr[], int size, int index) {
	//base case
	if(index >= size) {
		return true;
	}

	//processing
	if(arr[index] > arr[index-1]) {      //index starts from 1
		//aage check krna padega ab
		//ab recursion sambhalega
		bool aageKaAns = checkSorted(arr, size, index+1);
		return aageKaAns;
	}
	else {
		//sorted nahi h 
		return false;
	}
}


// OR
bool checkSorted(int *arr, int size) {  //int *arr or int arr[]
	//base case
	if(size == 0 || size == 1) {
		return true;
	}

	if(arr[0]>arr[1]){
		return false;
	}

	else{
		checkSorted(arr + 1, size-1);
	}

}



// 2. Subsequence

void findSubsequences(string str, string output, int index, vector<string>& ans) {
	//base case
	if(index >= str.length()) {
		//ans jo h , vo output string me build ho chuka h 
		//print krdo
		//cout <<"->" << output << endl;
		ans.push_back(output);
		return;
	}

	char ch = str[index];

	//include
	output.push_back(ch);
	findSubsequences(str, output, index+1, ans);

	//exclude
	output.pop_back();
	findSubsequences(str, output, index+1, ans);
	


	//exclude

	// //exclude
	// findSubsequences(str, output, index+1);
	// //include
	// //output string me ch character ko include krdo
	// output.push_back(ch);
	// findSubsequences(str, output, index+1);
}




// 3. Binary Search using Recursion

int binSearch(int arr[], int s, int e, int target) {
	//base case
	if(s > e ){
		//element not  found
		return -1;
	}

	//processing -> 1 case khud solve kro
	int mid = s + (e-s)/2;
	if(arr[mid] == target) {
		return mid;
	}
	//baacki recursion sambhal lega
	if(arr[mid] < target) {
		//right me jao 
		return binSearch(arr,mid+1,e, target);
	}
	else {
		//left me japo
		return binSearch(arr,s,mid-1, target);
	}
	
}

int main() {

	string str = "abc";
	string output = "";
	int index = 0;
	vector<string> ans;
	findSubsequences(str, output, index, ans);


	cout << "printing the subsequences in vector: " << endl;
	for(string s: ans) {
		cout << "-> " << s << endl;
	}
	// int arr[] = {10,20,30,40,50,60,70,80};
	// int size = 8;
	// int start = 0;
	// int end = size - 1;

	// int target = 60;

	// int foundIndex = binSearch(arr, start, end, target);

	// if(foundIndex != -1) {
	// 	cout << "target found at: " << foundIndex << endl;
	// }
	// else {
	// 	cout << "target not found"<< endl;
	// }

	// int arr[] = {};
	// int size = 0;
	// int index = 1;

	// bool isSorted = checkSorted(arr,size, index);

	// if(isSorted) {
	// 	cout << "Array is sorted" << endl;
	// }
	// else{
	// 	cout << "Array is not sorted" << endl;
	// }
	return 0;
}



// 4. Maximize the cut Segments(GFG) - Pattern : Explore all possible ways

int maximizeTheCuts(int n, int x, int y, int z){
	if(n == 0){
		return 0;
	}

	//Ham -ve length ka rod to kat nahi sakte therefor usse pahle
	// hi include kar diya taki wo max. me count na ho
	if(n < 0){
		return INT_MIN;
	}

	// maine x len ka 1 segment cut kar liya and baaki recursion dekh lega
	int option1 = 1 + maximizeTheCuts(n-x, x, y, z);

	// maine y len ka 1 segment cut kar liya and baaki recursion dekh lega
	int option2 = 1 + maximizeTheCuts(n-y, x, y, z);

	// maine z len ka 1 segment cut kar liya and baaki recursion dekh lega
	int option3 = 1 + maximizeTheCuts(n-z, x, y, z);

	int finalAns = max(option1, max(option2, option2));
	return finalAns;

}



// 5. Coin Change(Leetcode) - Pattern : Explore all possible ways

//coin change
class Solution {
public:

    int solve(vector<int>& coins, int amount) {
        //base case
        if(amount == 0 ) {
            return 0;
        }

        if(amount < 0 )
            return INT_MAX;

        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++) {
            int coin = coins[i];

            //current coin ko sir tabhi use krenge 
            //jab uski value <= amount hogi 
            if(coin <= amount) {
                int recAns = solve(coins, amount - coin);
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }    
            }
            
        }
        return mini;
    }


    int coinChange(vector<int>& coins, int amount) {
       int ans = solve(coins, amount);

       if(ans == INT_MAX)
        return -1;
        else
        return ans;
        
    }
};



// 6. House Robber(Leetcode) - Pattern : Include/Exclude

class Solution {
public:
    int solve(vector<int>& nums, int size, int index) {
        //base case
        if(index >= size ) {
            return 0;
        }

        //chori karlo -> ith index pr
        int option1 = nums[index] + solve(nums, size, index+2);

        //chori mat karo  -> ith index pr
        int option2 = 0 + solve(nums, size, index+1);

        int finalAns = max(option1, option2);
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;

    }
};


// 7. max sum of non-adjacent elements - Pattern : Include/Exclude

void solve(vector<int> &arr, int i, int sum, int &maxi){
	//Base case
	if(i>=arr.size()){
		return;
	}

	// Include
	solve(arr, i+2, sum + arr[i], maxi);

	//Exclude
	solve(arr, i+1, sum, maxi);
}


int main(){
	vector<int> arr{1,2,3,1,3,5,8,1,9};
	int sum = 0;
	int maxi = INT_MIN;
	int i = 0;
	solve(arr, i, sum, maxi);
	cout<<maxi<<endl;

	return 0;
}
