#include<iostream>
using namespace std;
/* print pattern
	10020134	->input
	12134000	->output
*/
void PushAllZeroesToEND(int *a , int n){
	// a is an array
	int j=n-1; /* j should store the index of first non zero*/
   	while(a[j]==0)
   		j--;
   	for (int i = 0; i < n && i<j; i++)
   	{
   		if(a[i]==0)
   		{
   			//swap(a[i],a[j]);
   			int temp=a[i];
   			a[i]=a[j];
   			a[j]=temp;
   			/* again find next non zero element from right*/
   			while(a[j]==0)
   				j--;
   		}
   	}
}
int main()
{

	int a[5]={1,0,0,2,3};
	PushAllZeroesToEND(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
