#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

    using namespace std;

int getOctets(string ip, vector<int> &octets);
vector<int> maskAddress(vector<int> &ip, vector<int> &mask);
string toBinary(vector<int>);
string toDecimal(vector<int>);


int main()
{/////input
    string ip_address = "192.168.0.1";
    string subnetmask = "255.255.255.0";

    vector<int> octetsIp;
    vector<int> octetsMask;
    vector<int> octetsResult;

    getOctets(ip_address, octetsIp);
    getOctets(subnetmask, octetsMask);
    octetsResult = maskAddress(octetsIp, octetsMask);

    cout << "ip_address: " << toBinary(octetsIp) << endl;
    cout << "subnetmask: " << toBinary(octetsMask) << endl;
    cout << "result:     " << toBinary(octetsResult) << endl;

    cout << "\n---------------------------\n\n";

    cout << "ip_address: " << toDecimal(octetsIp) << endl;
    cout << "subnetmask: " << toDecimal(octetsMask) << endl;
    cout << "result:     " << toDecimal(octetsResult) << endl;

    return 0;
}

// convert String to integer vector
int getOctets(string ip, vector<int> &octets)
{
    stringstream ss(ip);
    string temp;

    while (getline(ss,temp,'.'))
        octets.push_back(atoi(temp.c_str()));

    return 0;
}

// combine ip with mask
vector<int> maskAddress(vector<int> &ip, vector<int> &mask)
{
    vector<int> output;

    for (unsigned i=0; i<ip.size(); i++)
        output.push_back(ip[i] & mask[i]);

    return output;
}

// Convert to binary string "bbbbbbbb.bbbbbbbb.bbbbbbbb.bbbbbbbb"
string toBinary(vector<int> octets)
{
    string result;

    for (unsigned j=0; j < octets.size(); j++)
    {
        if (j>0)
            result += '.';

        int mask = 256;
        while (mask>>=1)
            result += '0' + ((octets[j] & mask ) != 0);
    }

    return result;
}

// Convert to decimal string "nnn.nnn.nnn.nnn"
string toDecimal(vector<int> octets)
{
    ostringstream outs;

    for (unsigned j=0; j < octets.size(); j++)
    {
        if (j>0)
            outs << '.';

        outs << octets[j];
    }

    return outs.str();
}
