#include <iostream>
#include <cstdlib>
 
int main() {
  srand(time(NULL));
  int answer = std::rand() % 10;
  std::cout << "MAGIC 8-Ball: \n\n";
  if (answer == 0) {
    std::cout << "it is certain";
  } else if(answer == 1){
    std::cout << "1";
  } else if(answer == 2){
    std::cout << "2";
  } else if(answer == 3){
    std::cout << "3";
  } else if(answer == 4){
    std::cout << "4";
  } else if(answer == 5){
    std::cout << "5";
  } else if(answer == 6){
    std::cout << "6";
  } else if(answer == 7){
    std::cout << "7";
  } else if(answer == 8){
    std::cout << "8";
  } else if(answer == 9){
    std::cout << "9";
  } else {
    std::cout << "very doubtful";
  };
}

