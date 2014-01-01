#include <iostream>

//global variables to ease the stack. 
int cols,rows;
long total=0;

//I should try to turn this into a loop so that there
//aren't (literally) a million stack pointers, but this will
//recursively check every possible path there is, and increments
//total when one is found.
void count_path(int x, int y) {
  
  if(x<rows)
    count_path(x+1,y);
  
  if(y<cols)
    count_path(x,y+1);
  
  if(x==rows && y==cols)
    total++;
}

int main() {
  //get the dimensions of the grid
  std::cout<<"Enter the grid dimensions (rows cols): ";
  std::cin>>rows>>cols;

  //count the paths
  count_path(0,0);

  //print the total
  std::cout<<"There are "<<total<<" paths!"<<std::endl;
}
