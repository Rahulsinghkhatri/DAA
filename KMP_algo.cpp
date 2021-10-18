#include<iostream>
#include<cstring>
using namespace std;
 void ComputeLPSArray(string pat,int m,int *lps)
 {
     int len=0;
     lps[0]=0;
     int i=0;

     while(i<m)
     {
         if(pat[i]==pat[len])
         {
             len++;
             lps[i]=len;
             i++;
         }
         else
         {
             if(len!=0)
             {
                 len=lps[len-1];
             }
             else
             {
                  lps[i]=0;
                  i++;
             }
         }
     }
 }

 void KMPsearch(string text,string pat)
 {
     int M=pat.length();
     int N=text.length();
     int lps[M];
     ComputeLPSArray(pat,M,lps);
     int i=0;
     int j=0;

     while(i<N)
     {
         if(pat[j]==text[i])
         {
             j++;
             i++;
         }
         if(j==M)
         {
             cout<<"Found at index "<<i-j<<endl;
             j=lps[j-1];
         }
         else if(i<N && pat[j]!=text[i])
         {
             if(j!=0)
             {
                 j=lps[j-1];
             }
             else
             {
                 i=i+1;
             }
         }
     }
 }

 int main()
 {
     string text,pat;
     cin>>text>>pat;
     KMPsearch(text,pat);
     return 0;
 }