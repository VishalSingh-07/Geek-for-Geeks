/*
Find missing in second array

Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second array b.

Example 1:

Input: 
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 10}
b[] = {2, 3, 1, 0, 5}
Output: 
4 10
Explanation: 
4 and 10 are present in first array, but not in second array.

Example 2:

Input: 
n = 5, m = 5
a[] = {4, 3, 5, 9, 11}
b[] = {4, 9, 3, 11, 10}
Output: 
5  
Explanation: 
Second array does not contain element 5.


Your Task:
- You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findMissing() that takes an integer array a, an integer array b, an integer n, and an integer m as input parameters and returns an array that contains the missing elements and the order of the elements should be the same as they are in array a.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(m).

Constraints:
1 ≤ n, m ≤ 105
-109 ≤ A[i], B[i] ≤ 109
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Brute Force Approach
// Time complexity -> O(n*m) and Space -> O(1)
class Solution{
	bool isPresent(int b[], int m, int x){
	    for(int i=0;i<m;i++){
	        if(b[i]==x){
	            return true;
	        }
	    }
	    return false;
	}
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    vector<int> ans;
	    for(int i=0;i<n;i++){
	        if(isPresent(b,m,a[i])==false){
	            ans.push_back(a[i]);
	        }
	    }
	    return ans;
	} 
};

// Above code give Time Limit Exceeded due to high Complexity O(n^2)



// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(m)
class Solution{
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    vector<int> ans;
	    unordered_map<int,int> mpp;
	    for(int i=0;i<m;i++){
	        mpp[b[i]]++;
	    }
	    for(int i=0;i<n;i++){
	        if(mpp.find(a[i])==mpp.end()){
	            ans.push_back(a[i]);
	        }
	    }
	    return ans;
	} 
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends

// Question link -- https://www.geeksforgeeks.org/problems/in-first-but-second5423/1