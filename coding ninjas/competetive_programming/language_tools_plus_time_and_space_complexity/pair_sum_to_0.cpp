#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
#define go(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
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


void solve(){
    int n;
    cin>>n;
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int start_pointer = 0;
    int end_pointer = n-1;
    int count = 0;
    while(start_pointer<end_pointer){
        if(arr[start_pointer]+arr[end_pointer]<0){
            start_pointer++;
        }
        else if(arr[start_pointer]+arr[end_pointer]>0){
            end_pointer--;
        }
        else{
            int l = start_pointer+1;
            int r = end_pointer-1;
            while(l<=r && arr[l]==arr[start_pointer]){
                l++;
            }
            while(r>=l && arr[r]==arr[end_pointer]){
                r--;
            }
            count+=(end_pointer-r)*(l-start_pointer);
             if(arr[start_pointer]==0){
                start_pointer++;
                end_pointer = r+1;
            }
            else{
                 start_pointer = l;
                end_pointer=r;
                
            }
        }
    }
  
    cout<<count<<endl;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
