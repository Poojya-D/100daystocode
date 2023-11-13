/******************************************************************************

          Problem Statement: Given a matrix if an element in the matrix is 0 then 
        you will have to set its entire column and row to 0 and then return the matrix.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
void zeroRow(std::vector<vector<int>> &res,int i,int m,int n)
{
    for(int j = 0; j <n;j++)
    {
        res[i][j] = 0;
        
    }
}
void zeroColumn(std::vector<vector<int>> &res,int j,int m,int n)
{
    for(int i = 0; i <m;i++)
    {
        res[i][j] = 0;
        
    }
}
int main()
{
    int m = 3, n = 4;
    std::vector<vector<int>> a = {{1,1,1,1},{1,0,1,1},{1,1,1,0}};
    std::vector<vector<int>> res = {{-1,-1,-1,-1},{-1,-1,-1,-1},{-1,-1,-1,-1}};
    
    for(int i = 0 ; i<m;i++)
    {
        for(int j = 0; j<n;j++)
        {
            if(res[i][j] == -1)
                res[i][j] = a[i][j];
            if(a[i][j] == 0)
            {
                zeroRow(res,i,m,n);
                zeroColumn(res,j,m,n);  
                break;
            }
        }
    }
    
    for(int i = 0 ;i <m;i++)
    {
        for(int j = 0; j<n; j++)
        {
            
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
