/** \ PAT
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

using namespace std;

int N, L, H;
typedef struct
{
    int ID;
    int virtue;
    int talent;
    int total;
    int priority;
}Person;

int func_priority(const Person & x)
{
    int v = x.virtue;
    int t = x.talent;
    if (v >= H && t >= H)
        return 0;
    if (v >= H && t < H)
        return 1;
    if (v >= t)
        return 2;
    return 3;
}

bool func_compare(const Person & a, const Person & b)
{
    if (a.total != b.total)
        return (a.total > b.total);
    else
    {
        if (a.virtue != b.virtue)
            return (a.virtue > b.virtue);
        else
            return (a.ID < b.ID);
    }
}

int main()
{
    while ((scanf("%d %d %d", &N, &L, &H)) != EOF)
    {
        vector<Person> group[4];
        int i;
        string a;
        for (i = 0; i < N; ++i)
        {
            Person p;
            scanf("%d %d %d", &p.ID, &p.virtue, &p.talent);
            if (p.virtue >= L && p.talent >= L)
            {
                p.total = p.virtue + p.talent;
                p.priority = func_priority(p);
                group[p.priority].push_back(p);
            }
        }
        int count = 0;
        for (i = 0; i < 4; ++i)
            count += group[i].size();
        printf("%d\n", count);
        for (i = 0; i < 4; ++i)
        {
            sort(group[i].begin(), group[i].end(), func_compare);
            vector<Person>::iterator iter = group[i].begin();
            for (; iter != group[i].end(); ++iter)
                printf("%8d %d %d\n", (*iter).ID, (*iter).virtue, (*iter).talent);
        }
    }

    return 0;
}
// Timeout! cin cout cost much more time...
