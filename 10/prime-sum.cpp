#include <iostream>
#include <stdlib.h>

//the number of primes we are calculating
#define PRIME_MAX 2000000

struct LinkList {
  long val;
  struct LinkList * next;
};

int main() {
  long largest = 2;
  long sum = 2;

  //creates pointers to the beginning and end of the prime list
  struct LinkList * prime_list = (LinkList * )malloc(sizeof(struct LinkList));
  struct LinkList * last_prime = prime_list;
  
  prime_list->val = 2;
  prime_list->next=NULL;
  
  //Calculates all the primes up to the max number
  long i=3;

  //loops until all the primes are found
  while(i<PRIME_MAX) {
    LinkList * current_prime = prime_list;
    int is_prime = 1;
    
    //loops through all the current primes to check if the value is divisible
    while(current_prime) {
      if(i%current_prime->val==0) {
        is_prime=0;
        break;
      }
      else
        current_prime = current_prime->next;
    }

    //if it's prime, it's added to the end of the linked list
    if(is_prime) {
      last_prime->next = (LinkList*)malloc(sizeof(LinkList));
      last_prime->next->val = i;
      last_prime->next->next = NULL;
      last_prime = last_prime->next;
      //the count increments if there is a new prime
      largest=i;
      sum+=i;
    }
    i++;
  }
  
  //prints out the number prime
  std::cout<<"Sum of primes less than "<<PRIME_MAX<<": "<<sum<<std::endl;
}
