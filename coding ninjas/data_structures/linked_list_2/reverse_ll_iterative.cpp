#include <bits/stdc++.h>
using namespace std;
#define fo(i, c) for (int(i) = 0; (i) < (c); (i)++)
#define go(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define gc getchar_unlocked
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626

//---------------------------------------pair----------------------------------------------------//
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, string> pistr;
//---------------------------------------pair----------------------------------------------------//

//--------------------------------------vector---------------------------------------------------//
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

typedef vector<string> vstr;
typedef vector<pistr> vpistr;
typedef vector<vstr> vvstr;
//---------------------------------------vector---------------------------------------------------//

//------------------------------------unordered_map-----------------------------------------------//
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
typedef unordered_map<int, vi> umapivi;

typedef unordered_map<string, int> umapstri;
typedef unordered_map<int, string> umapistr;
//------------------------------------unordered_map-----------------------------------------------//

//----------------------------------------map-----------------------------------------------------//
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
//----------------------------------------map-----------------------------------------------------//

//----------------------------------------set-----------------------------------------------------//
typedef set<int> sei;
typedef set<ll> sel;
//----------------------------------------set-----------------------------------------------------//

//----------------------------------execution time------------------------------------------------//
#define EXT cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
//----------------------------------execution time------------------------------------------------//

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *take_input()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

node *reverse(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *prev_node = NULL;
    node *curr_node = head;
    while (curr_node != NULL)
    {
        node *next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}

void print_ll(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void solve()
{
    node *head = take_input();
    head = reverse(head);
    print_ll(head);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}