#include <iostream>
#include <memory>

using namespace std;

struct destination;
struct connection;
connection connect(destination *);
void disconnect(connection);

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [&c]() { disconnect(c); });
}

int main()
{
    return 0;
}
