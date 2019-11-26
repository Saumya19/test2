#include<bits/stdc++.h>
using namespace std;

void find_number_of_coins(int a,int n,int d[]){
  int c[a+1],s[a+1],min;
  s[0]=0;c[0]=0;
  for(int p=1;p<a+1;p++){
    min=999;
    for(int i=0;i<n;i++){
      if(d[i]<=p){
        if(1+c[p-d[i]]<min)
        {
          min=1+c[p-d[i]];
          s[p]=i;
          c[p]=min;
        }

        //s[p]=i;
      }
    }
  }
  cout<<"coins used\n";
  int q=a;
  while (q>0) {
    cout<<d[s[q]]<<" ";
    q=q-d[s[q]];
  }

}


int main(){
  cout<<"enter total amount\n";
  int a,n;
  cin>>a;
  cout<<"enter number of denominations\n";
  cin>>n;
  int d[n];
  cout<<"enter denoinations\n";
  for(int i=0;i<n;i++)
    cin>>d[i];
  find_number_of_coins(a,n,d);
  return 0;
}
