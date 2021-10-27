#include <bits/stdc++.h>
using namespace std;
string ConvertToRoman(int n)
{
    string str = "";
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (n > 0)
    {
        int div = n / num[i];
        n = n % num[i];
        while (div--)
        {
            str += sym[i];
        }
        i--;
    }
    return str;
}
int main()
{
    int n;
    cin >> n;
    cout << ConvertToRoman(n);
}