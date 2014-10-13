void good(int, int);

char *hello(int a, int b, int c, int d, int e, int f, int g)
{
	char *p = "swust";
	
	return "hello_return";
}

void good(int a, int b)
{
	int c, d;
	char f[10] = "cjz";
	
	hello(1, 2, 3, 4, 5, 6, 7);
}


int main(int argc, char **argv)
{
	int a, b;
	good(3, 5);
	
	return 0;
}

