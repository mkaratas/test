#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <iostream>
//#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sale_price);
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
	virtual ~Quote();

private:
	std::string bookNo;
protected:
	double price;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(std::string &book, double sale_price, double dis);
	double net_price(std::size_t n) const;
	virtual ~Bulk_quote();

private:
	double discount;
};

#endif /*_QUOTE_H_*/
