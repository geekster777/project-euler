#include <iostream>

//The amount of digits each number being multiplied has
#define DIGITS 3

/**
 * Checks if the provided number is a palindrome
 * @param: val - int - the value being checked if it is a palindrome
 * @return: bool - true (1) if it is a palindrome, false (0) otherwise
 */
bool is_palindrome(long val) {
  int store_digits[DIGITS*2];
  long store_val = val;
  int total_digits = 0;

  //separates the number into digits
  for(int i=0; i<DIGITS*2; i++) {
    //counts how many digits there are
    if(store_val>0)
      total_digits++;
    store_digits[i]=store_val%10;
    store_val/=10;
  }

  //checks the opposite digits to see if they are the same
  for(int i=0; i<total_digits/2; i++)
    if(store_digits[i]!=store_digits[total_digits-i-1])
      return false;

  //if it made it this far, it must be a palindrome
  return true;
}

int main() {
  
  //initializes max to the largest 3 digit number possible
  int max = 1;
  for(int i=0; i<DIGITS; i++) max*=10;
  max-=1;

  //that weird crap with the max is just an ugly way of saying 999-99, but 
  //being able to work for any number of digits that max has, so 4 digits 
  //would be 9999-999. It's multiplied by 2 because we'll be working down
  //from 2 3-digit numbers being multiplied together, so there are 900 values
  //for one digit, and 900 for the other.
  for(int i=0; i<2*(max-(max%((max+1)/10))); i++) {
    //Starts from the largest value that can be found by multiplying the two
    //numbers, checks if it is a palindrome, then works its way down.
    for(int j=i/2; j>=0; j--) {
      if(is_palendrome((max-j)*(max-i+j))) {
        std::cout<<max-j<<"x"<<max-i+j<<"="<<(max-j)*(max-i+j)<<std::endl;
        return 0;
      }
    }
  }

  return 0;
}
