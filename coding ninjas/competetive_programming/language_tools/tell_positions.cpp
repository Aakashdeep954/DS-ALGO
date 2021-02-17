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

class student{
    public:
    string name;
    int roll_no;
    int total_marks;
};

bool compare(student a, student b){
    if(a.total_marks!=b.total_marks){
        return a.total_marks>b.total_marks;
    }
    return a.roll_no<b.roll_no;
}

void solve(){
    int n;
    cin>>n;
    student* students = new student[n];
    fo(i,n){
        cin>>students[i].name;
        students[i].roll_no = i+1;
        int m1,m2,m3;
        cin>>m1>>m2>>m3;
        int sum = m1+m2+m3;
        students[i].total_marks = sum;
    }
    sort(students,students+n,compare);
    fo(i,n){
        cout<<i+1<<" "<<students[i].name<<endl;
    }
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