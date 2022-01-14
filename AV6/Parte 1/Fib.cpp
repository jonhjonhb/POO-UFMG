#include<iostream>
using namespace std;


template <class T>
T Fib(T termo)
{
    T t1 = 0, t2 = 1, n = 0;
     
  if(termo==1)
  {
    cout << termo << ":" << t1 << endl;  
    return t1;
  }
  if(termo==2)
  {
    cout << termo << ":" << t2 << endl;      
    return t2;
  }
  for(int i=3; i <= termo; i++)
  {
     n = t1 + t2;
     t1 = t2;
     t2 = n;
  }
    cout << termo << ":" << n << endl;  
    return n;
}

int main()
{
  
    Fib(2);
    Fib(30);

  return 0;
}