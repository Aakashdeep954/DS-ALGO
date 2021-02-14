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

vi solve(int arr[],int n){
    sort(arr,arr+n);
    vi v;
    int j=1;
    int count = 1;
    fo(i,n){
        if(j<n && arr[j]==arr[i]){
            count++;
        }
        else{
            if(count>=2){
                v.pb(arr[i]);
                count = 1;
            }
            
        }
        j++;
    }
    return v;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    int arr[x+y+z];
    fo(i,x+y+z){
        cin>>arr[i];
    }
    vi voters = solve(arr,x+y+z);
    cout<<voters.size()<<endl;
    fo(i,voters.size()){
        cout<<voters[i]<<endl;
    }
}