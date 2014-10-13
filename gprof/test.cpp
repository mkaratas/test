#include<iostream>  
using namespace std;  
  
int add(int a, int b)  
{  
        return a+b;  
}  
  
int sub(int a, int b)  
{  
        return a-b;  
}  
  
int call ()  
{  
        std::cout << add(1,2) << std::endl;  
        std::cout << sub(2,4) << std::endl;  
}  
  
int main()  
{  
        int a=1, b=2;  
        cout << add(a,b) << endl;  
        for (int i=0; i<10000; i++)  
                call();  
        return 0;  
}  
