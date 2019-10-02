#include<iostream>
using namespace std;
int pow(int n)
{   //simply gives 10^n
    if(n==0)
        return 1;
    return pow(n-1)*10;

}
void DecToBinary(int n){
    int bin=0,i=0;/*i gives the iteration no. starting from 0*/
    while(n>0)
    {
        bin=bin+(n%2)*pow(i);
        n=n/2;
        i++;
    }
    cout<<bin<<endl;
}

int main(){

    DecToBinary(15);
    return 0;
}
