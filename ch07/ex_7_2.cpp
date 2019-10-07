/***ex_7_2***/
#include <iostream>

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

    Sales_data &combine(const Sales_data &rhe)
    {
        units_sold += rhe.units_sold;
        saleprice = (saleprice * units_sold + rhe.saleprice * rhe.units_sold);
        if (sellingprice != 0)
        {
            discount = saleprice / sellingprice;
            return *this;
        }
    }
} 
int main()
{
    return 0;
}
