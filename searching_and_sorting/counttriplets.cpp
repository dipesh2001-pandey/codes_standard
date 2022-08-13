#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long res =0;
	    sort(arr,arr+n);
	    for(int i =0;i<n-2;i++)
	    {
	        long long val = sum-arr[i];
	        int start =i+1,end = n-1;
	        while(start<end)
	        {
	            
	           if(val-(arr[start]+arr[end])>0)
	            {
	               // if(end-start==1)
	               // {
	               //     int sup = start*(start+1)/2;
	               //     res+=sup;
	               //     break;
	               // }
	                res+=end-start;;
	                start++;
	            }
	            else
	            {
	                end--;
	            }
	        }
	    }
	    return res;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
