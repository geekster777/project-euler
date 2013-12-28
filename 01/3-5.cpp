#include <iostream>
int main() {
  int total=0, max=0;
  
  //gets the max value to calculate up to
  std::cout<<"Enter a number to sum the multiples of 3 and 5 up to: ";
  std::cin>>max;
  
  //sums up the numbers that are divisible by 3 or 5
  for(int i=1; i<max; i++) {
    if(i%3==0 || i%5==0)
      total+=i;
  }
  
  std::cout<<"Total: "<<total<<std::endl;
}
