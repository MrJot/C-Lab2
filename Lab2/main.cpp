#include <iostream>

using namespace std;

int main()
{
   int b[5];
   int (*p1)[5];
   p1=&b;
   int *p2=&b;
   cout<<p2+3;

}
