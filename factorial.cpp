#include<iostream>
using namespace std;
int factorial(int num);
int main(){
 int res;
 res=factorial(5);
 cout<<"Resultado: "<<res<<endl;
    return 0;
}

int factorial(int num){
if(num==0){
    return 1;
}else
    return num*factorial(num-1);
}