/* Prog. inter a integer n and do the following calculation:
         if n is odd n <- 3n-1
		 else n <- n/2                                      */		 
#include<iostream>
using namespace std;

int main(void)
{
   int n;

   cout << "Please enter the n value ( n>=1 ): ";
   cin  >> n;
   cout << n;

   while(n != 1){
      if( (n%2) != 0 )
         n = n*3 + 1;	
      else   
         n = n/2;
      cout << " " << n; 
   }
  	
   return 0;	
}

