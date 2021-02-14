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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<char,vector<int>> mapof_indexes;
        int count=0;
        fo(i,s.length()){
            mapof_indexes[s[i]].pb(i+1);
        }
        tr(it,mapof_indexes){
            if(it->second.size()%2!=0){
                count++;
            }
        }
        if(count>1){
            cout<<"-1"<<endl;
            
        }
        else{
            int arr[s.length()];
            int star_pointer = 0;
            int end_pointer = s.length()-1;
            tr(it,mapof_indexes){
                int k=0;
                fo(j,it->second.size()/2){
                    arr[star_pointer] = it->second[k];
                    arr[end_pointer] = it->second[k+1];
                    star_pointer++;
                    end_pointer--;
                    k+=2;
                    
                }
                if(it->second.size()%2!=0){
                    arr[s.length()/2] = it->second[it->second.size()-1];
                }
            }
            fo(i,s.length()){
            cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
       
    }
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    solve();
}