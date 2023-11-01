/******************************************************************************

          Find the element that appears once in an array where every other element appears twice

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[] = { 1,1,3,5,6,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;
    for(int i= 0 ; i <n;i++)
        res = res ^ arr[i];
        
    cout<<res;

    return 0;
}
