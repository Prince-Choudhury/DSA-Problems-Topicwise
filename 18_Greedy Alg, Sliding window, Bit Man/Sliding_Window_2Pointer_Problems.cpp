#include <iostream>
#include<set>
#include<string.h>
using namespace std;

// 1423. Maximum Points You Can Obtain from Cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int maxSum = 0;

        for(int i = 0; i<=k-1; i++){
            lsum = lsum + cardPoints[i];
        }
        maxSum = lsum;

        int rindex = cardPoints.size() - 1;
        for(int i = k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rindex];

            maxSum = max(maxSum, (lsum+rsum));
            rindex--;
        }

        return maxSum;
        
    }
};



// 3. Longest Substring Without Repeating Characters

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0;
        int maxlen = 0;
        
        for(int i = 0; i<n;i++){
            int hash[256] = {0};
            for(int j = i; j<n; j++){
                if(hash[s[j]] == 1){
                    break;
                }

                len = j-i+1;
                maxlen = max(len, maxlen);
                hash[s[j]] = 1;
            }
        }

        return maxlen;
    }
};
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s){
        vector<int>hash(256, -1);
        int n = s.size();
        int len = 0;
        int maxLen = 0;

        int l = 0, r = 0;
        while(r<n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >=l){
                    l = hash[s[r]] + 1;
                }
            }

            len = r-l+1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};



// 1004. Max Consecutive Ones III

//Longest subarray with at most k zeros (<=k) -- Pattern

/*
//TC = O(n^2)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int len = 0;
        int maxlen = 0;
        for(int i = 0; i<n; i++){
            int zeros = 0;
            for(int j = i; j<n; j++){
                if(nums[j] == 0){
                    zeros++;
                }

                if(zeros<=k){
                    len = j-i+1;
                    maxlen = max(len, maxlen);
                }
                else{
                    break;
                }
            }
        }

        return maxlen;
    }
};
*/


/*
//TC = O(2n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int len = 0;
        int maxlen = 0;
        int zeros = 0;
        int l = 0, r = 0;
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }

            if(zeros<=k){
                len = r-l+1;
                maxlen = max(len, maxlen);
            }
            r++;
        }

        return maxlen;
    }
};
*/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int len = 0;
        int maxlen = 0;
        int zeros = 0;
        int l = 0, r = 0;
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }

            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }

            if(zeros<=k){
                len = r-l+1;
                maxlen = max(len, maxlen);
            }
            r++;
        }

        return maxlen;
    }
};




// GFG - Fruit Into Baskets

/*
// Brute Froce 
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlen = 0;
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            set<int>st;
            for(int j = i; j<n; j++){
                st.insert(arr[j]);
                if(st.size()<=2){
                    maxlen = max(maxlen, j-i+1);
                }
                else break;
            }
        }
        
        return maxlen;
    }
};
*/

//Optimized approach

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<int, int>mpp;
        
        while(r<n){
            mpp[arr[r]]++;
            
            //while(mpp.size()>2){
            if(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                
                l++;
            }
            
            if(mpp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        
        return maxlen;
    }

};



// 340. Longest Substring with At Most K Distinct Characters 

// Given a string s and an integer k, return the length of the 
// longest substring of s that contains at most k distinct characters.
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: The substring is "ece" with length 3.




// Brute Froce 
class Solution {
  public:
    int LongestSubstr(string str) {
        int maxlen = 0;
        int n = str.length();
        
        for(int i = 0; i<n; i++){
            set<int>st;
            for(int j = i; j<n; j++){
                st.insert(str[j]);
                if(st.size()<=2){
                    maxlen = max(maxlen, j-i+1);
                }
                else break;
            }
        }
        
        return maxlen;
    }
};


//Optimized approach

class Solution {
  public:
    int LongestSubstr(string str) {
        int n = str.length();
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<int, int>mpp;
        
        while(r<n){
            mpp[str[r]]++;
            
            //while(mpp.size()>2){
            if(mpp.size()>2){
                mpp[str[l]]--;
                if(mpp[str[l]] == 0){
                    mpp.erase(str[l]);
                }
                
                l++;
            }
            
            if(mpp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        
        return maxlen;
    }

};

