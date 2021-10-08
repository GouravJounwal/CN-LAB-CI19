#include<bits/stdc++.h>
using namespace std;

string getString(char x)
{
    string s(1, x);
    return s;
}

int  calculate_vrs(string val)
{
    int j=0;
    int res =0;
    for(int i=0; i<val.length(); i++)
    {
        int x;
        string s = getString(val[i]);
        stringstream geek(s);
        geek >> x;
        //cout<<"\n"<<x;
        res=res+x;
    }
    //cout<<"\n"<<res;
    return res;
}
int main()
{
    int n;
    cout<<"----WELCOME-----\n";
    cout<<"Enter 0 for ODD\nENTER 1 for EVEN\n";
    cin>>n;

    int res;
    string line;
    string val[4];
    ifstream f ("datav.txt");
    int i=0;
    while(getline(f, line))
    {
        cout<<line;
        val[i]=line;
        //cout<<"\n"<<val[i];
        i++;
        cout<<"\n";
    }
    for(int i=0; i<4; i++)
    {
        res = calculate_vrs(val[i]);
        // cout<<"\n  "<<i<<" : "<<res;
        if(n==1)
        {
            if(res%2==0)
            {
                val[i].append("0");
                cout<<"\n"<<val[i];
            }
            else
            {
                val[i].append("1");
                cout<<"\n"<<val[i];
            }
        }
        else
        {
            if(res%2==0)
            {
                val[i].append("1");
                cout<<"\n"<<val[i];
            }
            else
            {
                val[i].append("0");
                cout<<"\n"<<val[i];
            }
        }
    }



}
