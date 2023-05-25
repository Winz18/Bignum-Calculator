#include <bits/stdc++.h>
using namespace std;

void TienXuLi (string &a, string &b); // format numbers
string Cong (string a, string b); // for a+b
string Tru (string a, string b); // for a-b
string Nhan(string a, string b); // for a*b

int main ()
{
	string a, b;
	cin >> a >> b;
	string Tong = Cong(a, b);
	cout << Tong << endl;
	string Hieu = Tru(a, b);
	cout << Hieu << endl;
	string Tich = Nhan(a, b);
	cout << Tich << endl;
	return 0;
}
void TienXuLi (string &a, string &b)
{
    string copy;
    if (a.length() > b.length())
    {
        int d = a.length() - b.length();
        while (d != 0)
        {
            copy += "0";
            --d;
        }
        copy += b;
        b = copy;
    }
    if (a.length() < b.length())
    {
        TienXuLi(b, a);
    }
}
string Cong (string a, string b)
{
	string t; int tam = 0;
	if (a.length() != b.length())
		TienXuLi(a, b);
	for (int i = b.length()-1; i >= 0; i--)
	{
	    tam += (a[i]-'0')+(b[i]-'0');
	    if (tam >= 10)
    	{
    		if (i == 0)
    	    {
				t += to_string(tam-10);
    	        t += "1";
    	    }
    	    else
    	    {
    	        tam = tam - 10;
        	    t += to_string(tam);
        	    tam = 1;
    	    }
    	}
	    else
	    {
	        t += to_string(tam);
	        tam = 0;
	    }
	}
	reverse(t.begin(), t.end());
	while (t[0] == '0')
    	t.erase(0, 1);
    if (t.length() == 0)
		t = "0";
	return t;
}
string Tru (string a, string b)
{
	if (a.length() < b.length())
		return ("-"+Tru(b, a));
	else if (a == b)
		return "0";
	else if (a.length() == b.length() && a < b)
		return ("-"+Tru(b, a));
	else 
	{
		string t; int tam = 0;
		if (a.length() != b.length())
			TienXuLi(a, b);
		for (int i = b.length()-1; i >= 0; i--)
		{
			if ((a[i]-'0')-((b[i]-'0')+tam) < 0)
			{
				tam = 10+(a[i]-'0')-(b[i]-'0')-tam;
				t += to_string(tam);
				tam = 1;
			}
			else
			{
				tam = (a[i]-'0')-(b[i]-'0')-tam;
				t += to_string(tam);
				tam = 0;
			}
		}
		reverse(t.begin(), t.end());
		while (t[0] == '0')
	    	t.erase(0, 1);
		return t;
	}
}
string Nhan(string a, string b)
{
	string c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.length()+b.length(); i++)
    {
        c += "0";
    }
    for (int iA = 0; iA < a.length(); iA++)
    {
        int nho = 0; int iB;
        for (iB = 0; iB < b.length(); iB++)
        {
            int x = (a[iA]-'0')*(b[iB]-'0') + nho + (c[iA+iB] - '0');
            c[iA+iB] = x%10 + '0';
            nho = x/10;
        }
        while (nho > 0)
        {
            int x = nho + (c[iA+iB] - '0');
            c[iA+iB] = x%10 + '0';
            nho = x/10;
            iB++;
        }
    }
    reverse(c.begin(), c.end());
    while(c[0] == '0' && c.length() > 1)
    	c.erase(0, 1);
    return c;
}
