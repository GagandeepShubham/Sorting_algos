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

void merge(vector<int> &v, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);  //temporary array to store the merged array 
    int i = start;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end) //while i is lesser than the limit of left subarray and j is lesser than the limit of the right subarray
    {
        if(v[i] < v[j]) //if left subarray has smaller element
        {
            temp[k] = v[i];
            i++;  //increment to consider next element of left subarray
        }
        else
        {
            temp[k] = v[j];
            j++;  //increment to consider next element of right subarray
        }
        k++;  //always increment to point to next free position in temp array
    }

    //put any remaining elements in the temp array if any in left subarray
    while(i <= mid)
    {
        temp[k] = v[i];
        i++;
        k++;
    }

    //put any remaining elements in the temp array if any in right subarray
    while(j <= end)
    {
        temp[k] = v[j];
        j++;
        k++;
    }

    //copy the content of temp array in the v (original array back).
    for(i = start; i <= end; i++)
    {
        v[i] = temp[i - start];
    }
}

void merge_Sort(vector<int> &v, int start, int end)  //recursively call this mergesort procedure until you get start == end
{
    if(start < end)
    {
        int mid = ((unsigned int)start + (unsigned int)end) >> 1;
        merge_Sort(v, start, mid);
        merge_Sort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}
int main()
{
    //Start coding from here!
    int n, i, data;
    cout << "Enter size for array: ";
    cin >> n;
    cout << "Enter elements in the array: ";
    vector<int> v;
    for(i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    } 

    merge_Sort(v, 0, v.size() - 1);

    cout << "Sorted array: ";
    for(int x: v)cout << x << " ";
    nl;
}

