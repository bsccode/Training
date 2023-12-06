#include <iostream>
#include <cmath>

int main() {
  
  double a;
  double b;
  double c;

  std::cout<<"Enter a: \n";
  std::cin>>a;
  std::cout<<"Enter b: \n";
  std::cin>>b;
  std::cout<<"Enter c: \n";
  std::cin>>c;

  double root1 = (-b + std::sqrt(b*b-4*a*c))/(2*a);
  double root2 = (-b - std::sqrt(b*b-4*a*c))/(2*a);


  std::cout<<root1<<"\n";
  std::cout<<root2<<"\n";

}