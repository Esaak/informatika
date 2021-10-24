#include<iostream>

using namespace std;
int main(){
    int a[128][128];
    int b[128][128]={};
    int c[128][128]={};
    int answ [1024] = {};
    int N,M;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
    }
    b[0][0]=a[0][0];
    c[0][0]=1;
    c[M-1][N-1]=1;
    for(int i=1; i<M; i++){
        b[i][0]=a[i][0]+b[i-1][0];
        c[i][0]=1;
    }
    for(int i=1; i<N; i++){
        b[0][i]=a[0][i]+b[0][i-1];
        c[0][i]=2;
    }
    for(int i=1; i<M; i++){
        for(int j=1; j<N; j++){
            if(b[i][j-1]<b[i-1][j]){
                b[i][j]=a[i][j]+b[i][j-1];
                c[i][j]=2;
            }
            else{
                b[i][j]=a[i][j]+b[i-1][j];
                c[i][j]=1;
            }
        }
    }
    int i=M-1;
    int j=N-1;
    int schet = 0;
    while(i>=0 && j>=0){
        if(c[i][j]==2){
                answ[schet]=2;
                j--;
                schet++;
            }
            else{
                answ[schet]=1;
                i--;
                schet++;
            }
    }
    for(int k=schet-2; k>=0; k--){
        if(answ[k]==2)
            cout<<"right ";
        else{
            cout<<"down ";
        }
    }

    return 0;
}
