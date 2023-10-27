/******************************************************************************

                    Search, Insert, and Delete in an sorted Array 
*******************************************************************************/

#include <iostream>

using namespace std;

int BinarySearch(int arr[],int low,int high,int num)
{
    if(high < low)
        return -1;
    int mid = (low + high)/2;
    if(arr[mid] == num)
        return mid;
    if(arr[mid] > num)
        return BinarySearch(arr,low,mid - 1,num);
        
     return BinarySearch(arr,mid +1 ,high,num);
    
}

int InsertEnd(int arr[],int n,int num,int capacity)
{
    if(n > capacity)
    return n;
    
    arr[n] = num;
    return(n+1);
    
}

int Delete(int arr[],int n,int num)
{
    int pos = BinarySearch(arr,0,n,num);
    for(int i = pos; i < n;i++)
    {
        arr[i] = arr[i+1];
            
    }
    return n-1;
    
}

int main()
{
    int arr[7] = {1,2,3,4,5,6};
    int n = 6;
    cout<<BinarySearch(arr,0,n -1,6)<<endl;
    n = InsertEnd(arr,n,8,7);
    
    n = Delete(arr,n,5);
    for(int x :arr)
        cout<<x<<" ";
    return 0;
}
