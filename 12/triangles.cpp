#include <iostream>

#define FACTORS 500

int main(void) {
  
  int current=1;
  int index=1;
  while(true) {
    int factor_count=0;
    int i=1;
    int max=current;

    //Counts all the factors
    while(i<max) {

      //increments the count by 2 for every factor as i is a factor, and so is
      //current/i. We never get to current/i, because we cut the loop short.
      if(current%i==0) {
        factor_count+=2;
        max=current/i;
      }
      i++;
    }

    //account for square roots
    if(current/max==max)
      factor_count--;

    //Checks if this number has the specified amount of square roots
    if(factor_count>FACTORS)
      break;

    index++;
    current+=index;
  }
  std::cout<<"First triangle number with 28 factors: "<<current<<std::endl;
}
