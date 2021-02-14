#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
#define go(i,k,n) for(int i=k;k<n?i<n:i>=n;k<n?i+=1:i-=1)
#define gc getchar_unlocked
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define EXT cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

ll kadanes_algorithm(int arr[],int n){
    ll current_sum = 0;
    ll max_sum = INT_MIN;
    fo(i,n){
        current_sum += arr[i];
        if(max_sum<current_sum){
            max_sum = current_sum;
        }
        if(current_sum<0){
            current_sum = 0;
        }
    }
    return max_sum;
}

ll solve(int arr[],int n,int k){
    ll kadanes_sum = kadanes_algorithm(arr,n);
    if(k==1){
        return kadanes_sum;
    }
    ll prefix_max = INT_MIN;
    ll prefix_sum = 0;
    ll suffix_max = INT_MIN;
    ll suffix_sum = 0;
    fo(i,n){
        prefix_sum += arr[i];
        if(prefix_max<prefix_sum){
            prefix_max = prefix_sum;
        }
    }
    ll total_sum = prefix_sum;
    go(i,n-1,0){
        suffix_sum += arr[i];
        if(suffix_max<suffix_sum){
            suffix_max = suffix_sum;
        }
    }

    ll ans;
    if(total_sum<0){
        ans = max(prefix_max+suffix_max,kadanes_sum);
    }
    else{
        ans = prefix_max+suffix_max+(total_sum)*(k-2);
    }
    return ans;


}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        fo(i,n){
            cin>>arr[i];
        }
        cout<<solve(arr,n,k)<<endl;
    }

}
