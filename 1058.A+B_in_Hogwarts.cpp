/** \PAT 1058
 *
 * \ AC!
 * \ Yitian
 * \ 20130924
 *
 */


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long long radix[] = {1, 29 , 29 * 17};
long long CurrencyConvert(string & str)
{
    long long sum = 0;
    long long num = 0, pow = 1;
    int count = 0;
    int i = str.length() - 1;
    while (i >= 0)
    {
        if (str[i] == '.')
        {
            sum += num * radix[count];
            ++count;
            num = 0;
            pow = 1;
        }
        else
        {
            num += (str[i] - '0') * pow;
            pow *= 10;
        }
        --i;
    }
    sum += num * radix[count];
    return sum;
}

int main()
{
    string A, B;

    while (cin >> A >> B)
    {
        long long ans = CurrencyConvert(A) + CurrencyConvert(B);
        cout << (ans / radix[2]) << ".";
        ans %= radix[2];
        cout << (ans / radix[1]) << ".";
        ans %= radix[1];
        cout << ans << endl;
    }
}
