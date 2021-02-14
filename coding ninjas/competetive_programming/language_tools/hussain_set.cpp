#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
#define go(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

void solve(ll arr[],int n,int m){
    sort(arr,arr+n);
    queue<ll> q;
    int count = 0;
    int end_pointer=n-1;
    while(m--){
        ll current_query;
        cin>>current_query;
        int ans;
        while(count<current_query){
            if(q.empty() || arr[end_pointer]>q.front()){
                ans = arr[end_pointer];
                end_pointer--;
            }
            else{
                ans = q.front();
                q.pop();
            }
            if(ans/2>0){
                q.push(ans/2);
            }
            count++;
        }
        cout<<ans<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    solve(arr,n,m);
}