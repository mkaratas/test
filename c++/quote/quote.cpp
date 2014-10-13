#include "quote.h"

Quote::Quote(const std::string &book, double sale_price):bookNo(book), price(sale_price)
{
	std::cout << "Quote constructor" << std::endl;
}

std::string Quote::isbn() const
{
	return bookNo;
}

double Quote::net_price(std::size_t n) const
{
	return n * price;
}

Quote::~Quote()
{
	std::cout << "Quote deconstructor" << std::endl;
}

Bulk_quote::Bulk_quote(std::string &book, double sale_price, double dis):Quote(book, sale_price), discount(dis)
{
	std::cout << "Bulk_quote construct" << std::endl;
}

double Bulk_quote::net_price(std::size_t n) const
{
	return n * price * discount;
}

Bulk_quote::~Bulk_quote()
{
	std::cout << "Bulk_quote deconstructor" << std::endl;
}

int main(int argc, char **argv)
{
	std::string s = "cjz";
	Quote *p = new Bulk_quote(s, 100.0, 0.8);
	delete p;

	return 0;
}
