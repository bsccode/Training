#include <iostream>

int main() {
  int dog_age = 22;
  int early_years = 21; // The first two years of a dogs lige count as 21 human years
  int later_years =  (dog_age - 2) * 4; // each following year is 4 years
  int human_years = early_years + later_years; // add them together 
  std::cout<<"My name is Jeff! Ruff ruff, I am " << human_years << " years old in human years.\n";
}