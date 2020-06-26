#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

string encrypt(string s, int a, int b)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (a * (s[i] - 'A') + b) % 26 + 'A';
		else if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = (a * (s[i] - 'a') + b) % 26 + 'a';
	}

	return s;
}

string decrypt(string s, int a, int b)
{
	int a_inv = 0;

	for (int i = 0; i < 26; i++)
	{
		int flag = (a * i) % 26;

		if (flag == 1)	a_inv = i;
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (a_inv * (s[i] - 'A' + 26 - (b % 26))) % 26 + 'A';
		else if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = (a_inv * (s[i] - 'a' + 26 - b)) % 26 + 'a';
	}

	return s;
}

int main()
{
	cout << "\n";
	cout << "1. Encrypt\n";
	cout << "2. Decrypt\n";
	cout << "Choice: ";
	string ch;	cin >> ch;

	cin.ignore();

	cout << "Enter text: ";
	string s;	getline(cin, s);

	int a, b;
	cout << "Enter key:\n";
	cout << "a = ";	cin >> a;
	cout << "b = "; cin >> b;

	if (gcd(a, 26) != 1)
	{
		cout << "Key not possible\n";
		return 1;
	}

	if (ch == "1")
		cout << "Encrypted text: " << encrypt(s, a, b) << "\n";
	else if (ch == "2")
		cout << "Decrypted text: " << decrypt(s, a, b) << "\n";

	return 0;
}