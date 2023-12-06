#include <iostream>

int main() {
  
  double pesos;
  double reais;
  double soles;
  double dollars;


  std::cout<<"Enter number of Columbian Pesos: \n";
  std::cin>>pesos;
  std::cout<<"Enter number of Brazillian Reais: \n";
  std::cin>>reais;
  std::cout<<"Enter number of Peruvian Soles: \n";
  std::cin>>soles;

  dollars = (pesos*0.8) + (reais * 1.2) + (soles*.5);

  std::cout<<"US Dollars = $ " << dollars << "!\n";
}