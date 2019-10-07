#include <iostream>
#include<string>

using namespace std;

class Sales_data
{
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;

public:
	string isbn() const
	{
		return bookNo;
	}

	Sales_data& combine(const Sales_data& rhe)
	{
		units_sold += rhe.units_sold;
		saleprice = (saleprice * units_sold + rhe.saleprice * rhe.units_sold);
		if (sellingprice != 0)
		{
			discount = saleprice / sellingprice;
			return *this;
		}
	}

	double avg_price() const
	{
		return sellingprice / units_sold;
	}
    
	istream& read(istream& is, Sales_data& item)
	{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> item.saleprice;
		item.sellingprice = item.units_sold * item.saleprice;
		return is;
	}

	ostream& print(ostream& os, const Sales_data& item)
	{
		os << item.isbn() << " " << item.units_sold << " "
			<< item.sellingprice << " " << item.avg_price();
		return os;
	}
};

int main()
{
	return 0;
}
