#include<iostream>
using namespace std;
//to search an element in a rotated and sorted array
void binarySearch(int *a,int s, int e,int target){
    if(s>e)
        return;
    if(s==e&&a[s]==target)
    {
       cout<<"target is present at "<<s<<endl;
       return;
    }
     if(s==e&&a[s]!=target){
        cout<<"target is not present at all"<<endl;
        return;
    }
    int mid=(s+e)/2;
    if(a[mid]==target)
       cout<<"target is present at "<<mid<<endl;
    else if(a[mid]>target)
        binarySearch(a,s,mid-1,target);
    else
        binarySearch(a,mid+1,e,target);
}
int findPivot(int *a,int s, int e){
    /*this function returns the index after which
     the array decreases i.e. pivot index*/
    if(s>e) //means list exhausted
        return -1;
    if(s==e)
        return s;
    int mid=(s+e)/2;
    if(mid<e&&a[mid]>a[mid+1])
        return mid;
    if(s<mid&&a[mid]<a[mid-1])
        return mid-1;
    if(a[s]>a[mid])
        return findPivot(a,s,mid-1);
    return findPivot(a,mid+1,e);
}
void searchInRotatedArray(int *a,int n,int target){
    if(n<=0)
        return;
    int pivot=findPivot(a,0,n-1);
    if(pivot==-1)//not rotated at all because pivot element not found
       {
        binarySearch(a,0,n-1,target);
        return;
       }
    if(a[pivot]==target)
        cout<<"target found at "<<pivot<<endl;
    else if(a[pivot]>target&&a[0]<target){
        binarySearch(a,0,pivot,target);
        return;
    }
    else
    binarySearch(a,pivot+1,n-1,target);

}
int main(){
    int a[]={3,4,5,8,1,2};
    searchInRotatedArray(a,6,1);

    return 0;
}
