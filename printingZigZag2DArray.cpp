#include<iostream>
using namespace std;
/* print 2D array in zig zag manner
	1 2 3 4
	4 5 6 5
	9 0 0 8 	->input
	1 2 3 4 5 6 5 4 9 0 0 8	->output
*/
void PrintZigZag2D(int **a , int m, int n){
	// a is a 2D array
	int i=0;
	/* printing two rows at a time*/
	for(int k=1;k<=(m*n)/2;k++)
	{
	    int j=0;
	    while(j<n)
        {
            cout<<a[i][j]<<" ";
            j++;
        }
        j--;i++;
        while(j>=0&&i<m){
            cout<<a[i][j]<<" ";
            j--;
        }
        i++;

	}

}
int main()
{

	int m , n;
	cout<<"enter the size of array"<<endl;
	cin>>m>>n;
	int **a;
	a=new int*[m];  /*for creating dynamic arrays*/
	for(int i=0;i<m;i++)
		a[i]=new int [n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		cin>>a[i][j];
	}
	cout<<endl;
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    PrintZigZag2D(a,m,n);
    for(int i=0;i<m;i++)
        delete a[i];
    delete a;
	return 0;
}
