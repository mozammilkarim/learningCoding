#include<iostream>
using namespace std;
void waveSort(int* a, int n){
    /*follow increasing and decreasing order alternatively*/
    for(int i=0;i<n;i++){
        if(i%2==0&&a[i]>a[i+1])//even index
        {
            //swap both because
            //from starting increasing order has to be followed
            int temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
        if(i%2!=0&&a[i]<a[i+1]){
            //here order must be decreasing for odd index elements
            int temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
}
int main(){
    int a[]={-1,0,10,-3,1};
    waveSort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
