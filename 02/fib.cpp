#include <iostream>
int main() {
  int total=0, last=1,num=1, max=0;
  
  //gets the max value to calculate up to
  std::cout<<"Enter the max fibonacci number to sum the evens up to: ";
  std::cin>>max;
  
  //sums up the fibonacci numbers if it is divisible by 2
  while(num<max) {
    if(num%2==0)
      total+=num;
    num = last + num;
    last = num - last;
  }
  
  std::cout<<"Total: "<<total<<std::endl;
}
