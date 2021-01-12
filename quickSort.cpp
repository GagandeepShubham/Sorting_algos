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

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high]; //selecting last element as pivot
    int i = low - 1;  //index of smaller element (assume)
    int j;
    for(j = low; j <= high - 1; j++)
    {
        if(v[j] <= pivot) //if any elment is smaller than pivot
        {
            i++;  //increment the index of the smaller element (because we thought that i pointed to the smaller element than pivot but we got v[j] instead 
                  //which is smaller than pivot.
            swap(v[i], v[j]); //swap that element with the current element
        }
        //the above if block will not be executed incase the element is greater than pivot
        //so the smaller element index stays at correct position and when the above if block
        //gets executed we first increment i, then we swap that max element now pointed by the i, with the smaller element
        //pointed by j.
    }
    
    swap(v[i + 1], v[high]); //later put the pivot at the correct position
    return (i + 1); //return the index of the pivot element
}

void quick_Sort(vector<int> &v, int low, int high)
{
    if(low < high)
    {
        int q = partition(v, low, high);
        quick_Sort(v, low, q - 1);
        quick_Sort(v, q + 1, high);
    } 
}

int main()
{
    //Start coding from here!
    int i, n, data;
    cout << "Enter size for array: ";
    cin >> n;
    cout << "Enter elements in the array: ";
    vector<int> v;
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    } 

    quick_Sort(v, 0, v.size() - 1);

    cout << "Sorted array: ";
    for(int x: v)cout << x << " ";
    nl;
}

