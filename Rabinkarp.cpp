#include<iostream>
using namespace std;

void rabinkarp(string text,string pat)
{
    int m=text.length(),n=pat.length();
    int p=0,t=0,d=101,q=11,h=1;

    for(int i=0;i<n-1;++i)
    {
        h=(h*d)%q;
    }
    
    for(int i=0;i<n;++i)
    {
        p=(p*d + pat[i])%q;
        t=(t*d + text[i])%q;
    }
 
    for(int i=0;i<m-n;++i)
    {
        if(p==t)
        {
            int j;
            for(j=0;j<n;++j)
            {
                if(pat[j]!=text[i+j])
                    break;
            }

            if(j==n)
            {
                cout<<"Pattern found at "<<i<<endl;
            }
        }

        if(i<m-n)
        {
            t=d*(t-(text[i]*n)%q + text[i+n]%q)%q;
            if(t<0)
              t=t+q;
        }
    }
}

int main()
{
    string text,pat;
    cin>>text>>pat;
    rabinkarp(text,pat);
    return 0;
}