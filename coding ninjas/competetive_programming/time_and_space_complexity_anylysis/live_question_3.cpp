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

void solve(ll product[],int n,int arr[]){
    ll left_product = 1;
    fo(i,n){
        product[i] = left_product;
        left_product *= arr[i];
    }
    ll right_product = 1;
    go(i,n-1,0){
        product[i] *= right_product;
        right_product *= arr[i];
    }
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    fo(i,n){
        cin>>arr[i];
    }
    ll product[n];
    solve(product,n,arr);
    fo(i,n){
        cout<<product[i]<<endl;
    }
}
