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

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *take_input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
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

Node *swap_two_nodes(Node *head, int i, int j)
{
    if (head == NULL)
    {
        return head;
    }
    Node *previous_1 = head;
    Node *current_1 = head;
    Node *next_1 = head;
    Node *previous_2 = head;
    Node *current_2 = head;
    Node *next_2 = head;
    int count_1 = 0;
    int count_2 = 0;
    while (count_1 < i || count_2 < j)
    {
        if (count_1 < i)
        {
            previous_1 = current_1;
            current_1 = current_1->next;
            next_1 = current_1->next;
            count_1++;
        }
        if (count_2 < j)
        {
            previous_2 = current_2;
            current_2 = current_2->next;
            next_2 = current_2->next;
            count_2++;
        }
    }
    if ((i == 0 && j == 1) || (j == 0 && i == 1))
    {
        current_2 = current_2->next;
        current_1->next = current_2->next;
        current_2->next = current_1;
        return current_2;
    }

    else if (i == 0)
    {
        current_2->next = current_1->next;
        previous_2->next = current_1;
        current_1->next = next_2;
        return current_2;
    }
    else if (j == 0)
    {
        current_1->next = current_2->next;
        previous_1->next = current_2;
        current_2->next = next_1;
        return current_1;
    }
    else if (i - j == 1 || j - i == 1)
    {
        if (i < j)
        {
            previous_1->next = current_2;
            current_2->next = current_1;
            current_1->next = next_2;
        }
        else if (j < i)
        {
            previous_2->next = current_1;
            current_1->next = current_2;
            current_2->next = next_1;
        }
    }
    else
    {
        previous_1->next = current_2;
        current_2->next = next_1;
        previous_2->next = current_1;
        current_1->next = next_2;
    }

    return head;
}

void print_ll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void solve()
{
    Node *head = take_input();
    int i, j;
    cin >> i >> j;
    head = swap_two_nodes(head, i, j);
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