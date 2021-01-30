#include <bits/stdc++.h>
using namespace std;
#define fo(i,c) for(int(i) = 0; (i) < (c); (i)++)
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

int firstIndex(int arr[],int size,int x){
    if(size==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    
     int output = firstIndex(arr+1,size-1,x);
     if(output==-1){
         return -1;
     }
     else{
         return output+1;
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
    int x;
    cin>>x;
    cout<<firstIndex(arr,n,x);
}