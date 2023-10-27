/******************************************************************************

                              Rotate an array

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n],d = 3,j = 0;
    for(int i = d; i < n; i++ )
        temp[j++] = arr[i];
    
    for(int i = 0; i < d; i++ )
        temp[j++] = arr[i];
        
    for(int x:temp)
        cout<<x<<" ";

    return 0;
}
