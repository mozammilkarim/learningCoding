#include<iostream>
using namespace std;
int pow(int n)
{   //simply gives 10^n
    if(n==0)
        return 1;
    return pow(n-1)*10;

}
void findMissingNo(int *a,int n){
    /*this method can lead to overflow if n is quite large*/
    int sum=(n*(n+1))/2;/* to calculate the exact sum of no*/
    /*since the no. are in range with no duplicates*/
    for(int i=0;i<n-1;i++)
        sum-=a[i];
    cout<<"missing is "<<sum<<endl;
}
void findMissingNo2(int *a,int n){
    /*here n is the given range*/
    int total=1;
    for(int i=2;i<=n;i++){
        total+=i;/*doing sum of n numbers*/
        total=total-a[i-2];/*this is done because there are n-1 elemnets in array
        which means we can go upto n-2 index*/
    }
    cout<<"missing is"<<total<<endl;
}
void findMissingNoUsingXOR(int *a,int n){
    /*here n is no. range of elements*/
    int x1=a[0];//to store xor of array
     //elements
    for(int i=1;i<n-1;i++)
        x1=x1^a[i];
    int x2=1;/*xoring original range to get
    same result as that of array elements
    */
    for(int i=2;i<=n;i++){
        x2=x2^i;
    }
    /*x2 should be greater than x1 since it has one more
     element than x1*/
    /*if we do xor of x1 and x2, we get one missing element*/
    x1=x1^x2;
    cout<<"missing"<<x1<<endl;
}
int main(){

    int a[]={1,2,3,5,7,6};/* so range or n is 7*/
    findMissingNo(a,7);
    findMissingNo2(a,7);
    findMissingNoUsingXOR(a,7);
    return 0;
}
