#include<bits/stdc++.h>
using namespace std;

void lcs(string X,string Y,int m,int n){
  int L[m+1][n+1];
  int i,j;
  for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
      if(i==0 || j==0)
        L[i][j]=0;
      else if(X[i-1]==Y[j-1])
        L[i][j]=L[i-1][j-1]+1;
      else
        {
          if(L[i-1][j]>=L[i][j-1])
            L[i][j]=L[i-1][j];
          else
            L[i][j]=L[i][j-1];
        }
    }
  }
  cout<<"The lenth of common subsequence is:";
  cout<<L[m][n]<<"\n";
  int index= L[m][n];
  char last[index+1];
  last[index]='\0';
     i=m,j=n;

    while(i>0&&j>0){
      if(X[i-1]==Y[j-1]){
        last[index-1]=X[i-1];
        i--;j--;index--;
      }

      else if(L[i-1][j]>L[i][j-1])
        i--;
      else
        j--;
    }
    cout<<"common subsequence is:";
    cout<<last<<"\n";
}

int main(){
  cout<<"enter two string\n";
  string s1,s2;
  cin>>s1>>s2;
  lcs(s1,s2,s1.length(),s2.length());



  return 0;
}
