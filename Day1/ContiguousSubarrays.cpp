/******************************************************************************

                find contiguous sub arrays in iterative and recursive  
*******************************************************************************/

#include <iostream>

using namespace std;
void printsubArrays(int arr[],int n)
{
    for(int i = 0; i<n;i++)
    {
        for(int j = i; j<n;j++)
        {
            for(int k = i; k <= j; k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
void printsubArrays2(int arr[],int start,int end,int n)
{
    if(end == n)
        return;
    else if(start > end)
        printsubArrays2(arr,0,end+1,n);
    else
    {
        for(int i = start; i< end; i++)
            cout<<arr[i]<<" ";
        cout<<arr[end]<<endl;
        printsubArrays2(arr,start+1,end,n);
    }
    
}
int main()
{
    int arr[] = {1,2,3,4};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printsubArrays(arr,n);
    printsubArrays2(arr,0,0,n);
    

    return 0;
}
