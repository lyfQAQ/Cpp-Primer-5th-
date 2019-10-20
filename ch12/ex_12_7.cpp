#include <iostream>
#include <memory>
#include <vector>
using namespace std;
using Ptr = shared_ptr<vector<int>>;

Ptr getMemory()
{
    return make_shared<vector<int>>();
}

auto read(Ptr vec)
{
    int k;
    while (cin >> k)
    {
        vec->push_back(k);
    }
    return vec;
}

auto print(const Ptr vec) -> ostream &
{
    for (auto &i : *vec)
        cout << i << " ";
    return cout;
}
int main()
{
    auto vec = read(getMemory());
    print(vec) << endl;

    return 0;
}
