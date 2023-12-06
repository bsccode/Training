#include <iostream>

int main() {
  int gryffindor = 0;
  int hufflepuff = 0;
  int ravenclaw = 0;
  int slytherin = 0;
  int answer1;
  int answer2;
  int answer3;
  int answer4;

  std::cout<< "The Sorting Hat Quiz!\n";

  std::cout<< "Q1) When I'm dead, I want people to remember me as:\n\n";
  std::cout<< "1) The Good\n";
  std::cout<< "2) The Great\n";
  std::cout<< "3) The Wise\n";
  std::cout<< "4) The Bold\n\n";

  std::cout<< "Please enter a number between 1 and 4: ";
  std::cin>>answer1;
  std::cout<< "You chose: "<<answer1<<"\n";

  if (answer1 == 1){ 
    hufflepuff ++;
  } else if (answer1 == 2){ 
    slytherin ++;
  }else if (answer1 == 3){ 
    ravenclaw ++;
  }else if (answer1 == 4){ 
    gryffindor ++;
  }else { 
    std::cout<<"Invalid Input";
  }

 std::cout<< "Q2) Dawn or Dusk?\n\n";
  std::cout<< "1) Dawn\n";
  std::cout<< "2) Dusk\n";

  std::cout<< "Please enter a number between 1 and 2: ";
  std::cin>>answer2;
  std::cout<< "You chose: "<<answer2<<"\n";

  if (answer2 == 1){ 
    hufflepuff ++;
    gryffindor ++;
  } else if (answer2 == 2){ 
    slytherin ++;
    ravenclaw++;
  }else{ 
    std::cout<<"Invalid Input";
  }

   std::cout<< "Q3) What kind of instrument most pleases your ear?\n\n";
  std::cout<< "1) The Violin\n";
  std::cout<< "2) The Trumpet\n";
  std::cout<< "3) The Piano\n";
  std::cout<< "4) The Drum\n\n";

  std::cout<< "Please enter a number between 1 and 4: ";
  std::cin>>answer3;
  std::cout<< "You chose: "<<answer3<<"\n";

  if (answer3 == 2){ 
    hufflepuff ++;
  } else if (answer3 == 1){ 
    slytherin ++;
  }else if (answer3 == 3){ 
    ravenclaw ++;
  }else if (answer3 == 4){ 
    gryffindor ++;
  }else { 
    std::cout<<"Invalid Input";
  }

   std::cout<< "Q1)Which road tempts you the most?\n\n";
  std::cout<< "1) The wide, sunny grassy lane\n";
  std::cout<< "2) The narrow, dark, lantern-lit alley\n";
  std::cout<< "3) The twisting, leaf-strewn path through the woods\n";
  std::cout<< "4) The cobbled street lined (ancient buildings)\n\n";

  std::cout<< "Please enter a number between 1 and 4: ";
  std::cin>>answer4;
  std::cout<< "You chose: "<<answer4<<"\n";

  if (answer4 == 1){ 
    hufflepuff ++;
  } else if (answer4 == 2){ 
    slytherin ++;
  }else if (answer4 == 4){ 
    ravenclaw ++;
  }else if (answer4 == 3){ 
    gryffindor ++;
  }else { 
    std::cout<<"Invalid Input";
  }

    int max = 0;
    std::string house;

    if (gryffindor > max) {
  
    max = gryffindor;
    house = "Gryffindor";
  
  }

  if (hufflepuff > max) {

    max = hufflepuff;
    house = "Hufflepuff";
  
  }

  if (ravenclaw > max) {
  
    max = ravenclaw;
    house = "Ravenclaw";
  
  }

  if (slytherin > max) {
  
    max = slytherin;
    house = "Slytherin";
  
  }

  std::cout << house << "!\n";
}