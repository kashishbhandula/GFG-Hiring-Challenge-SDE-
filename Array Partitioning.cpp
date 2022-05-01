//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  long long int check(int N,int K,int A[],long long int mid)
  {
      
      long long int ans=0;
      long long int sum=0;
      long long int val=0;
      for(int i=0;i<N;i++)
      {
          if(sum+A[i]>mid)
          {
              if(sum==0)
              {
                  ans++;
                  val=max(A[i]*1LL,val);
                  continue;
              }
              else
              {
                   val=max(val,sum);
                   sum=0;
                  ans++;
              }
              
          }
          sum+=A[i];
          
      }
      if(sum!=0)
      {
          ans++;
          val=max(val,sum);
      }
      if(ans<=K)return val;
      else return 1e14;
  }
    long long solve(int N,int K,int A[])
    {
        // add your code here
        long long int low=1;
        long long int high=1e14;
        long long int ans =1e14;
        while(low<=high)
        {
            long long int mid=(high-low)/2+low;
            long long int val=check(N,K,A,mid);
            if(ans>=val)
            {
                ans=min(ans,val);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
       
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N,k;
        cin >> N>>k;
        int A[N];

        for (int i = 0; i < N; i++) cin >> A[i];
       

        Solution ob;
        cout << ob.solve(N,k,A) << "\n";
    }
    return 0;
}  // } Driver Code Ends