#include<iostream>
#include<string>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(string const &b,double p):bookNo(b),price(p){}

	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }

	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

double print_total(ostream& os, Quote const& item, size_t n)
{
	double ret = item.net_price(n);
	os<<"ISBN:"<<item.isbn()<<"# sold: " << n << " total due: " << ret << endl;
	return ret;
}
int main()
{


	return 0;
}


