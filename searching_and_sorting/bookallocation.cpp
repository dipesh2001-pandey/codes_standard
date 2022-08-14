#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool issafe(int mid, int arr[], int m,int n)
    {
        int pageSum=0;
       int studentCount=1;
       
       for(int i=0;i<n;i++)
       {
           if(pageSum + arr[i] <= mid)
             pageSum=pageSum+arr[i];
             
            else
            {
                studentCount++;
                if(studentCount>m  || arr[i] >mid)
                  return 0;
               
               pageSum=arr[i];
               
            }
       }
       
       
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low = A[0],high=0,mid;
        int res=-1;
        if(N<M) return -1;
        for(int i =0;i<N;i++)
        {
            high+=A[i];
            low=max(low,A[i]);
        }
        while(high-low>1)
        {
            mid=low+(high-low)/2;
            if(issafe(mid,A,M,N))
            {
                high= mid;
            }
            else
            low=mid+1;
        }
        if(issafe(low,A,M,N))
        res=low;
        else if(issafe(mid,A,M,N))
        res=mid;
        else if(issafe(high,A,M,N))
        res=high;
        return res;
    }
};