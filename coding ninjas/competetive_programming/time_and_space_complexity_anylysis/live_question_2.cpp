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

ll solve(int arr[],int n){
    ll min_end_here = 1;
    ll max_end_here = 1;
    ll max_product_sofar = 0;
    fo(i,n){
        if(arr[i]>0){
            max_end_here = max_end_here*arr[i];
            min_end_here = min(min_end_here,(ll)1);
        }
        else if(arr[i]==0){
            max_end_here = 1;
            min_end_here = 1;
        }
        else{
            ll temp = max_end_here;
            max_end_here = max(min_end_here*arr[i],(ll)1);
            min_end_here = temp*arr[i];
        }
        max_product_sofar = max(max_product_sofar,max_end_here);
    }
    return max_product_sofar;
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
    cout<<solve(arr,n)<<endl;
}
