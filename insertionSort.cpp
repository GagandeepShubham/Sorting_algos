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

void insertion_Sort(vector<int> &v)
{
    int j, curr, pos;
    for(j = 1; j < v.size(); j++)   //starts from 1 because 1st element is always sorted
    {
       pos = j - 1;  //pointer to the previous element than current
       curr = v[j]; 
       if(v[j - 1] < curr)continue;  //if the current element is greater than the previos than it is in correct position already
       else //otherwise previous element is greater than current
       {
           while(v[pos] > curr) //while you are finding greater elements than current 
           {
               v[pos + 1] = v[pos]; //keep on moving all those elements one step forward
               pos--;  //decrement position for considering previous elements
           }
           v[++pos] = curr;  //later while loop will stop where it will find an element smaller than current
           //but we want to insert the current element after that so first increment the pos then insert.
       }
    }
}

int main()
{
    //Start coding from here!
    vector<int> v;
    int n, i, data;
    cout << "Enter size of the array: ";
    cin >> n;
    cout << "Enter element in the array: ";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    } 

    insertion_Sort(v);

    cout << "Sorted array: ";
    for(int x: v)cout << x << " ";
    nl;
}
