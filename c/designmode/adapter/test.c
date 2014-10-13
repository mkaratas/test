#include <stdio.h>

struct target {
	void (*open)(struct target *this);
};

struct adaptee {
	void (*myopen)(struct adaptee *this);
};

struct adapter {
	struct target tar;
	struct adaptee ee;
};

void adaptee_open(struct adaptee *this)
{
	printf("adaptee_open\n");
}

void adapter_open(struct target *tar)
{
	struct adapter *this = (struct adapter*)tar;
	printf("adapter_open\n");
	this->ee.myopen(&this->ee);
}

int main(int argc, char **argv)
{
	struct adaptee ee = {
		.myopen = adaptee_open,
	};

	struct adapter er = {
		.tar = {
			adapter_open,					
		},
		.ee = {
			adaptee_open,
		},
	};

	struct target *pt= (struct target*)&er;
	pt->open(pt);
	return 0;
}
