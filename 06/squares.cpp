#include <iostream>

#define MAX 100

int main() {
  long sum=0, sum_squares=0;
  for(int i=1; i<=MAX; i++) {
    sum+=i;
    sum_squares+=i*i;
  }
  std::cout<<"Square difference of first "<<MAX<<" natural numbers: "<<
    (sum*sum)-sum_squares<<std::endl;
  return 0;
}
