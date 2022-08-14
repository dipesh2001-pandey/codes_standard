class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    //function to count inversion in array 
    //we have used 0 based indexing l,r,m 
    //To calculate inversion we have added n1-i as if ith element forms an inversion than element greter than ith will also form as array is sorted
long long merge(long long arr[],long long l,long long r,long long m)
{
   long long n1= m-l+1,count=0;
   long long n2=r-m;
   long long leftarray[n1];
   long long rightarray[n2];
   for(int i=0;i<n1;i++)
   {
       leftarray[i]=arr[l+i];
   }
   for(int i=0;i<n2;i++)
   {
       rightarray[i]=arr[m+i+1];
   }
   long long i=0,j=0,k=l;
   while(i<n1&&j<n2)
   {
      if(leftarray[i]<=rightarray[j])
      {
        arr[k]=leftarray[i];
        i++;
      }
      else
      {
        arr[k]=rightarray[j];
        count+=n1-i;
        j++;
      }
      k++;
   }
   while(i<n1)
   {
       arr[k++]=leftarray[i++];
   }
   while(j<n2)
   {
       arr[k++]=rightarray[j++];
   }
   return count;
}
long long mergesort(long long array[],long long begin,long long end)
{
    if(begin>=end)return 0;
   long long count=0;
   long long mid = begin+(end-begin)/2;
   count+=mergesort(array,begin,mid);
   count+=mergesort(array,mid+1,end);
   count+=merge(array,begin,end,mid);
   return count;
}

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergesort(arr,0,N-1);
    }

};