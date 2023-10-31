/******************************************************************************

                              find subarray with given sum

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,8,12,13,9};
    int sum = 5,j=0,curr=0,i=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(i = 0;i<n;i++ )
    {
        //cout<<"start"<<endl;
        //cout<<i<<" "<<arr[i]<<" "<<curr<<" "<<j<<endl;
        if(curr < sum)
        {
            curr = curr+arr[i];
            j++;
            
        }
        else if(curr == sum)
            break;
        else
        {
            //cout<<"else"<<endl;
            while(j>0)
            {
                //cout<<i<<" "<<arr[i-1]<<" "<<curr<<" "<<j<<endl;
                curr = curr-arr[i-1];
                j-=1;
                i-=1;
                
            }
            
        }
    }
    if(curr != sum)
        cout<<"No subarray found";
    else
        cout<<"starting index "<<i-j+1<<" ending index "<<i;
    return 0;
}
