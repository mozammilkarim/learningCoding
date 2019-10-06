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
int findPivot(int *a,int n){
    /*this function returns the index after which
     the array decreases i.e. pivot index*/
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1])
            return i;
    }
    return 0;
}

bool findSumInRotatedArray(int *a,int n,int sum){
    if(n<=0)//not valid
        return false;
    int pivot=findPivot(a,0,n);
    if(pivot==0)//means not rotated at all
    {
        //apply standard o(n) approach
        int i=0,j=n-1;
        for(;i!=j;i++,j--)
        {
            if(a[i]+a[j]==sum)
                return true;
            else if(a[i]+a[j]>=sum)
                j--;
            else if(a[i]+a[j]<=sum)
                i++;
        }
        return false;
    }

    /*now you should use a different approach i.e. a cyclic approach*/
   // {2,3,0,1}
   int i=pivot,j=pivot+1;
   while(i!=j){
        if(a[i]+a[j]==sum)
            return true;
        else if(a[i]+a[j]<=sum)
            j=(j+1)%n;
        else if(a[i]+a[j]>=sum)
            i=(n+i-1)%n;//to have cyclic effect
   }
   return false;


}
void arrangeAlternatively(int* a,int n){
    /*first arrange all using partition of quick
     sort using 0 as pivot element
    */
    int i=-1,j=0;
    for(;j<n;j++){
        if(a[j]<=0)
        {
            i++;
            //swap a[i+1] with a[j]
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    /*now swap all values alternatively from each partition*/
    int exg=0;j=0;
    while(a[j]<0)
        j++;
    for(int i=0;i<n&&j<n;i++){
        if(exg==0)//no exchange
            exg=1;
        else
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            exg=0;
            j++;
        }

    }

}
int main(){
    int a[]={3,-4,5,-8,-9,-2,0};
    arrangeAlternatively(a,7);
    for(int i=0;i<7;i++)
        cout<<a[i];

    return 0;
}
