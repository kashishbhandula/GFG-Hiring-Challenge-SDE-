//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long solve(int N,int K,int A[])
    {
        // add your code here
        vector<int>odd,even;
        for(int i=0;i<N;i++)
        {
            if(i&1)even.push_back(A[i]);
            else odd.push_back(A[i]);
        }
        long long int ans1=0,ans2=0;
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        // for(auto it:odd)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:even)cout<<it<<" ";
        // cout<<endl;
        K++;
        
        int i=0,j=0;
        int cnt=K;
        while(cnt>0&&i<odd.size())
        {
             ans1+=odd[i];
             i++;
             cnt--;
             if(j>=even.size()||cnt==0)
             {
                 break;
                 
             }
             ans1+=even[j];
             j++;
             cnt--;
        }
        
        i=0,j=0,cnt=K;
         while(cnt>0&&j<even.size())
        {
             ans2+=even[j];
             j++;
             cnt--;
             if(j>=odd.size()||cnt==0)
             {
                 break;
                 
             }
             ans2+=odd[i];
             i++;
             cnt--;
        }
        return max(ans1,ans2);
        
       
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