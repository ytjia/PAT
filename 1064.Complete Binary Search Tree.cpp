/** \PAT 1064
 *
 * \AC!
 * \Yitian
 * \20130923
 *
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct TreeNode
{
    int value;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;

int compare(const int &a, const int &b)
{
    return a < b;
}

void BuildCBST(TreeNode * node, vector<int> &vec, int beg, int end)
{
    int len = end - beg + 1, extra;
    int root;
    int bit = 1;
    while (len >= bit - 1)
    {
        bit <<= 1;
    }
    bit >>= 1;
    extra = len - bit + 1;
    root = beg + ((bit - 1) >> 1) + ((extra > (bit >> 1)) ? (bit >> 1) : extra);
    node->value = vec[root];
    if (root > beg)
    {
        TreeNode * left = new TreeNode();
        node->left = left;
        BuildCBST(left, vec, beg, root - 1);
    }
    else
    {
        node->left = NULL;
    }
    if (root < end)
    {
        TreeNode * right= new TreeNode();
        node->right = right;
        BuildCBST(right, vec, root + 1, end);
    }
    else
    {
        node->right = NULL;
    }
}

void BFS(queue<TreeNode *> &que, int &len, int &count)
{
    while (!que.empty())
    {
        ++count;
        TreeNode * node = que.front();
        que.pop();
        if (node->left != NULL)
            que.push(node->left);
        if (node->right != NULL)
            que.push(node->right);
        cout << node->value;
        if (count != len)
            cout << " ";
        else
            cout << endl;
    }
}

int main()
{
//    ifstream ifile("D:\\Test\\PATTest.in");
//    ofstream ofile("D:\\Test\\PATTest.out");
//    streambuf *cinbackup;
//    streambuf *coutbackup;
//    coutbackup = cout.rdbuf(ofile.rdbuf());
//    cinbackup = cin.rdbuf(ifile.rdbuf());
    int N, i, t;
    vector<int> vec;
    cin >> N;
    for (i = 0; i < N; ++i)
    {
        cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end(), compare);
    int len = vec.size();
    TreeNode * root = new TreeNode();
    BuildCBST(root, vec, 0, len - 1);
    int count = 0;
    queue<TreeNode *> que;
    que.push(root);
    BFS(que, len, count);

    return 0;
}
