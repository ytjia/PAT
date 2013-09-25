/** \ PAT 1061
 *
 * \ AC!
 * \ Yitian
 * \ 20130925
 *
 */


#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string str1, str2, str3, str4;
    string DAY[] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    while (cin >> str1 >> str2 >> str3 >> str4)
    {
        int len = min(str1.length(), str2.length());
        int i = 0, count = 0;
        int info[3];
        while (i < len)
        {
            if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
            {
                info[count++] = str1[i] - 'A' + 1;
                ++i;
                break;
            }
            ++i;
        }
        while (i < len)
        {
            if (str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9')))
            {
                if (str1[i] >= 'A' && str1[i] <= 'N')
                {
                    info[count++] = str1[i] - 'A' + 10;
                    ++i;
                    break;
                }
                if (str1[i] >= '0' && str1[i] <= '9')
                {
                    info[count++] = str1[i] - '0';
                    ++i;
                    break;
                }
            }
            ++i;
        }
        i = 0;
        len = min(str3.length(), str4.length());
        while (i < len)
        {
            if (str3[i] == str4[i] && ((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')))
            {
                info[count] = i;
                break;
            }
            ++i;
        }

        cout << DAY[info[0]] << " ";
        if (info[1] < 10)
            cout << '0';
        cout << info[1] << ":";
        if (info[2] < 10)
            cout << '0';
        cout << info[2] << endl;
    }

    return 0;
}
