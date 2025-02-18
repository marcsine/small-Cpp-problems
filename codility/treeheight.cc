// you can use includes, for example:
// #include <algorithm>
using namespace std;

struct tree
{
    int x;
    tree *l;
    tree *r;
};

void search_leafs(tree *curr_root, int height, int &max_lenght)
{
    if (curr_root == nullptr)
        return;

    if (height > max_lenght)
        max_lenght = height;
    height++;
    search_leafs(curr_root->l, height, max_lenght);
    search_leafs(curr_root->r, height, max_lenght);
}

int solution(tree *T)
{
    int result = 0;
    search_leafs(T, 0, result);
    return result;
}
