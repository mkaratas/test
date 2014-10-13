#ifndef __PRODUCT_H_
#define __PRODUCT_H_

class Product {
public:
	virtual ~Product() = 0;

protected:
	Product();

private:

};

class ConcreteProduct : public Product {
public:
	~ConcreteProduct();
	ConcreteProduct();

protected:

private:

};

#endif /*__PRODUCT_H_*/
