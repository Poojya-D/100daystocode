/******************************************************************************

                    Search, Insert, and Delete in an Unsorted Array 
*******************************************************************************/

#include <iostream>

using namespace std;

int findElement(int arr[],int n,int num)
{
    for(int i = 0;i < n;i++)
    {
        if(arr[i] == num)
            return i;
    }
    return -1;
    
}
int InsertEnd(int arr[],int n,int num,int capacity)
{
    if(n > capacity)
    return n;
    
    arr[n] = num;
    return(n+1);
    
}
int InsertPos(int arr[],int n,int num,int pos)
{
    for(int i = n-1; i>=pos;i--)
        arr[i+1] = arr[i];
    arr[pos] = num;
    return n+1;
}
int Delete(int arr[],int n,int num)
{
    int pos = findElement(arr,n,num);
    for(int i = pos; i < n;i++)
    {
        arr[i] = arr[i+1];
            
    }
    return n-1;
    
}

int main()
{
    int arr[7] = {3,1,9,5,6};
    int n = 5;
    cout<<findElement(arr,n,5)<<endl;
    n = InsertEnd(arr,n,8,7);
    
    n = InsertPos(arr,n,2,4);
    
    n = Delete(arr,n,5);
    for(int x :arr)
        cout<<x<<" ";
    return 0;
}
