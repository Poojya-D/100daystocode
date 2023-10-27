/******************************************************************************

                              Reverese an array
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int end = sizeof(arr) / sizeof(arr[0]) - 1; 
    int start = 0;
    
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
    for(int x:arr)
        cout<<x<<" ";
    return 0;
}
