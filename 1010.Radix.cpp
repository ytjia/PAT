/** \ PAT 1010
 *
 * \ radix can be very big (long long), also stuck at case 1,10
 * \ Yitian
 * \
 *
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long long atoi_radix(string & tar, long long radix)
{
    int i = tar.length() - 1;
    long long Numdec = 0, pow = 1;
    while (i >= 0)
    {
        Numdec += ((tar[i] >= 'a') ? (tar[i] - 'a' + 10) : (tar[i] - '0')) * pow;
        pow *= radix;
        --i;
    }
    return Numdec;
}

int main()
{
//    ifstream ifile("D:\\Test\\PATTest.in");
//    ofstream ofile("D:\\Test\\PATTest.out");
//    streambuf *cinbackup;
//    streambuf *coutbackup;
//    coutbackup = cout.rdbuf(ofile.rdbuf());
//    cinbackup = cin.rdbuf(ifile.rdbuf());

    int tag;
    long long radix;
    string N1, N2;
    cin >> N1 >> N2 >> tag >> radix;

    string tar, des;
    if (tag == 1)
    {
        tar = N1;
        des = N2;
    }
    else if (tag == 2)
    {
        tar = N2;
        des = N1;
    }
    else
        return -1;

    long long Numdec = atoi_radix(tar, radix), Numundefined;
//    cout << Numdec; // debug
    bool flag = false;
    long long boundary = (radix > 1000) ? radix : 1000;
    for (int i = 2; i <= boundary; ++i)
    {
        Numundefined = atoi_radix(des, i);
        if (Numdec == Numundefined)
        {
            flag = true;
            cout << i <<endl;
            break;
        }
        else if (Numdec < Numundefined)
            break;
    }
    if (!flag)
        cout << "Impossible" << endl;
    return 0;
}
