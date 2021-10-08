#include<bits/stdc++.h>
using namespace std;

string getString(char x)
{
    string s(1, x);
    return s;
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
    string ress="";
    ifstream f ("datal.txt");
    int i=0;
    while(getline(f, line))
    {

        cout<<line;
        val[i]=line;
        //cout<<"\n"<<val[i];
        i++;
        cout<<"\n";
    }
    for(int i=0; i<8; i++)
    {
        res=0;
        for(int j=0; j<4; j++)
        {
            int x;
            string s = getString(val[j][i]);
            stringstream geek(s);
            geek >> x;
            //cout<<"\n"<<x;
            res=res+x;
        }
        if(n==1)
        {
            if(res%2==0)
            {
                ress.append("0");
            }
            else
            {
                ress.append("1");
            }
        }
        else
        {
            if(res%2==0)
            {
                ress.append("1");
            }
            else
            {
                ress.append("0");
            }
        }
    }
    cout<<"\n"<<ress;
}
