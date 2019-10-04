#include<iostream>
using namespace std;
void revers(int *a,int s,int e){
    for(;s<=e;s++,e--)
    {
        int temp=a[s];
        a[s]=a[e];
        a[e]=temp;
    }

}
void leftRotateArrayAlgo(int *a,int n, int d){
    /*
    rotate(arr[], d, n)
  reverse(arr[], 1, d) ;
  reverse(arr[], d + 1, n);
  reverse(arr[], 1, n);
  this is for left shift
    */
    revers(a,0,d-1);
    revers(a,d,n-1);
    revers(a,0,n-1);

}
void rightRotate(int *a, int n, int d){
    revers(a,n-d,n-1);//reverse n-d of right
    revers(a,0,n-d-1);//reverse rest of left
    revers(a,0,n-1);
}
int main(){
    int a[]={1,2,3,4,5,8};
    rightRotate(a,6,3);
    for(int i=0;i<6;i++)
        cout<<a[i];
    return 0;
}
