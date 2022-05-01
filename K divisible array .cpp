#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
    long long solve(int N, int K, vector<int> &A) {
        // code here
        for(int i=0;i<N;i++)
        {
            long long int temp=A[i]%K;
            A[i]=min(temp,K-temp);
        }
        sort(A.begin(),A.end());
        long long int ans=0;
        for(int i=0;i<K;i++)ans+=A[i];
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        vector<int> A(N);
        Array::input(A, N);

        Solution obj;
        long long res = obj.solve(N, K, A);

        cout << res << endl;
    }
}
  // } Driver Code Ends