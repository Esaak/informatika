#include<iostream>
#include <cstdio>
const int MAXX=128;
using namespace std;
struct vivod{
int i;
int j;
};
int printLCS(char *a, vivod *answ,int i, int j){
    if(i==0 || j==0){
        return 0;
    }
    if(answ[i][j].i==i-1 && answ[i][j].j==j-1){
        printLCS(a,answ,i-1, j-1);
        cout<<a[i];
    }
    else if(answ[i][j].i==i-1){
        printLCS(a,answ,i-1,j);
    }
        else{
            printLCS(a, answ, i,j-1);
        }


}
int main(){
int i=0;
char a[MAXX]={}, p='a';
char b[MAXX]={};
int lcs[MAXX][MAXX]={};
vivod answ [MAXX][MAXX]={};
for(int i=0; i<MAXX; i++){
    lcs[MAXX][0]=0;
    lcs[0][MAXX]=0;
    }
while (p!='\n'){
    cin.get(p);
    a[i]=p;
    i++;
}
i--;
a[i]='\0';
int j=0;
p='a';
while (p!='\n'){
    cin.get(p);
    b[j]=p;
    j++;
}
j--;
b[j]='\0';
for(int i1=0; i1<i+1; i1++){
    for(int j1=0; j1<j+1; j1++){
    if (b[i]==a[j]){
        lsc[i1][j1]=lsc[i1-1][j1-1]+1;
        answ[i1][j1].i=i1-1;
        answ[i1][j1].j=j1-1;
    }
    else {
        if(lsc[i1][j1-1]>lsc[i1-1][j1])
            lsc[i1][j1]=lsc[i1][j1-1];
            answ[i1][j1].i=i1;
            answ[i1][j1].j=j1-1;
        else{
            lsc[i1][j1]=lsc[i1-1][j1];
            answ[i1][j1].i=i1-1;
            answ[i1][j1].j=j1;
            }
        }
    }
}
printLCS(a,answ, i,j);


return 0;
}
