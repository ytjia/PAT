/** \ PAT 1063
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

using namespace std;

int main()
{
//    ifstream ifile("D:\\Test\\PATTest.in");
//    ofstream ofile("D:\\Test\\PATTest.out");
//    streambuf *cinbackup;
//    streambuf *coutbackup;
//    coutbackup = cout.rdbuf(ofile.rdbuf());
//    cinbackup = cin.rdbuf(ifile.rdbuf());
    int N, M, K;
    int Numin;

    while (cin >> N)
    {
        int i, j;
        vector< set<int> > sets;
        for (i = 0; i < N; ++i)
        {
            cin >> M;
            set<int> seta;
            for (j = 0; j < M; ++j)
            {
                cin >> Numin;
                seta.insert(Numin);
            }
            sets.push_back(seta);
        }

        cin >> K;
        int a, b, counta, countb, countunion;
        double result;
        for (i = 0; i < K; ++i)
        {
            cin >> a >> b;
            --a;
            --b;
            counta = sets.at(a).size();
            countb = sets.at(b).size();
            countunion = counta + countb;
//            set<int> setunion = sets.at(a - 1);
//            setunion.insert(sets.at(b - 1).begin(), sets.at(b - 1).end()); // timeout
//            countunion = setunion.size();
            set<int>::iterator itr = sets.at(a).begin();
            for (; itr != sets.at(a).end(); ++itr)
            {
                if (sets.at(b).count(*itr) == 1)
                    --countunion;
            }
            result = (((double) counta + (double) countb - (double) countunion) / (double) countunion) * 100.0;
            printf("%.1lf%%\n", result);
        }
    }

//    getchar();
    return 0;
}
