#include <iostream>
#include <stdlib.h>

struct LinkList {
  long val;
  struct LinkList * next;
  struct LinkList * prev;
};

int main() {
  long max=0;

  struct LinkList * prime_list = (LinkList * )malloc(sizeof(struct LinkList));
  struct LinkList * last_prime = prime_list;
  
  prime_list->val = 2;
  prime_list->next=NULL;
  prime_list->prev=NULL;

  //gets the number to calculate the prime factor of
  std::cout<<"Enter a number to calculate the largest prime factor of: ";
  std::cin>>max;
  
  //Calculates all the primes up to the max number
  long i=3;

  //loops until the square root of the number
  while(i*i<=max) {
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
      last_prime->next->prev = last_prime;
      last_prime = last_prime->next;
    }
    i++;
  }

  LinkList * largest_prime = last_prime;
  
  //find the largest prime divisible
  while(largest_prime && max%largest_prime->val) largest_prime = largest_prime->prev;

  //if none is found, the number must be prime. 
  if(largest_prime)
    max = largest_prime->val;

  std::cout<<"Largest prime factor: "<<max<<std::endl;
}
