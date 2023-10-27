/******************************************************************************

                              find an element in array

*******************************************************************************/

#include <iostream>

using namespace std;

string search(int arr[], int N,int num)
{
    for(int x = 0; x < N; x++)
       { if(arr[x] == num)
        return "found";
       }
       return "not found";
}
int main()
{
    int arr[] = {3,8,1,7,10,5};
    
    cout<<search(arr,6,0);

    return 0;
}
