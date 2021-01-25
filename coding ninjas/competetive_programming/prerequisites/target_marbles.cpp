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


int main()
{
   ios::sync_with_stdio(0); 
   cin.tie(0);

   int n,target_number;
   cin>>n>>target_number;
   
   int arr[n];
   fo(i,n){
       cin>>arr[i];
   }

   int cum_sum = 0;
   int index = -1;
   unordered_map<int, int> m;
   fo(i,n){
    cum_sum += arr[i];
    if(cum_sum==target_number){
        cout<<"true"<<endl;
        index = i;
        fo(j,i+1){
            cout<<arr[j]<<" ";
        }
        break;
    }

    if(m.find(cum_sum-target_number)!=m.end()){
        for(int k = m[cum_sum-target_number]; k<i+1; k++){
            cout<<arr[k]<<" ";
        }
        break;
    }
       m[cum_sum]=i;
   }
   

   
}