#include <array>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib> //qsort,bsearch,NULL

using namespace std;

long get_a_target_long()
{
    long target = 0;
    cout << "target (0——" << RAND_MAX << "):";
    cin >> target;
    return target;
}

string get_a_target_string()
{
    long target = 0;
    char buf[10];
    cout << "target (0——" << RAND_MAX << "):";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void *a, const void *b)
{
    return (*(long *)a - *(long *)b);
}

int compareStrings(const void *a, const void *b)
{
    if (*(string *)a > *(string *)b)
        return 1;
    else if ((*(string *)a < *(string *)b))
        return -1;
    else
        return 0;
}
namespace vlyf1
{
void test_array()
{
    enum
    {
        ASIZE = 100000
    }; //enum hack
    array<long, ASIZE> c;

    cout << "\ntest_array()..........\n";

    clock_t timeStart = clock();
    for (auto &i : c)
        i = rand();

    cout << "milli-seconds:" << (clock() - timeStart) << endl;
    cout << "array.size()=" << c.size() << endl;
    cout << "array.front()=" << c.front() << endl;
    cout << "array.back()=" << c.back() << endl;
    cout << "array.data()=" << c.data() << endl;

    long target = get_a_target_long();
    timeStart = clock();
    qsort(c.data(), ASIZE, sizeof(long), compareLongs);

    long *pItem = (long *)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
    cout << "qsort()+bsearch(),milli-seconds:" << (clock() - timeStart) << endl;
    if (pItem != nullptr)
        cout << "found," << *pItem << endl;
    else
        cout << "not found!" << endl;
}

} // namespace vlyf1
int main()
{
    vlyf1::test_array();
}
