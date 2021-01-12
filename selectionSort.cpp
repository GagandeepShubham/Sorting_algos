#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define deb(x) cout << #x << ":" << x << "\n";
#define pb push_back
#define nl cout << "\n";
#define ll long long

void selection_Sort(vector<int> &v)
{
    int min_index;
    for(int i = 0; i < v.size() - 1; i++)
    {
        min_index = i;  //consider the element at index i to be the minimum element
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[j] < v[min_index])min_index = j;  //if any element smaller than the current smaller is found then update the min index
        }
        swap(v[i], v[min_index]); //later swap the ith element with the element at min index
    } 
}

int main()
{
    //Start coding from here!
    int n, i , data;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    cout << "Enter elements in array: ";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    selection_Sort(v);

    cout << "Sorted array: ";
    for(int x: v)cout << x << " ";
    nl;
}

