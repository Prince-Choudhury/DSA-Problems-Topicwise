class Solution
{
    public:
    
    int solve(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0){
		    return 0;
	    }

	    //Ham -ve length ka rod to kat nahi sakte therefor usse pahle
	    // hi include kar diya taki wo max. me count na ho
	    if(n < 0){
		    return INT_MIN;
	    }
	   
	    if(dp[n]!= INT_MIN){
	        return dp[n];
	    }

	    // maine x len ka 1 segment cut kar liya and baaki recursion dekh lega
	    int option1 = 1 + solve(n-x, x, y, z, dp);

	    // maine y len ka 1 segment cut kar liya and baaki recursion dekh lega
	    int option2 = 1 + solve(n-y, x, y, z, dp);

	    // maine z len ka 1 segment cut kar liya and baaki recursion dekh lega
	    int option3 = 1 + solve(n-z, x, y, z, dp);

	    dp[n] = max(option1, max(option2, option3));
	    return dp[n];
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z){
	    vector<int>dp(n+1, INT_MIN);
	    int ans = solve(n, x, y, z, dp);
	    
	    // If the result is negative, return 0 (since no cuts could be made)
        return max(0, ans);

    }
};