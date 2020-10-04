#include<iostream>

using namespace std;

int** input(int r,int c)
{
  int** arr=new int*[r];
    for(int i=0;i<r;i++)
    {
        arr[i]=new int[c];
        for(int j=0;j<c;j++)
       { cout<<"Enter the value for the cell "<<i<<" , "<<j<<endl;
        cin>>arr[i][j];}
    }
return arr;
}

int main()
{

 int** arr;
 int r,c;
 cout<<"Enter the no. of rows and columns";
 cin>>r>>c;

arr= input(r,c) ;

for(int i=0;i<r;i++)
{
    for(int j=i;j<c;j++)
    {
        int temp=arr[i][j];
        arr[i][j]=arr[j][i];
        arr[j][i]=temp;
    
    }
}

for(int i=0;i<r;i++)
{
    for(int j=0;j<=(c/2)-1;j++)
    {
        int temp=arr[i][j];
        arr[i][j]=arr[i][c-j-1];
        arr[i][c-j-1]=temp;
    }
}

for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

}
