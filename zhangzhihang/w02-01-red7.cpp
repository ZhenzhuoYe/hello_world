#include <iostream>
#include <string>

/**
 * Topics:
 * 
 * 1. Revision/New:
 *  - 1D Array
 *  - 2d Array
 *  - std::string
 *  - Function
 * 2. Classes:
 *  - Declaration (all one file for now)
 *  - Definition (all one file for now)
 *  - Constructor
 *  - Calling methods
 *  - Copy??
 * 3. Pointers & Memory
 *  - Computer Memory Layout
 *  - Variables
 *  - Memory address
 *  - Pointer
 *   - Referencing
 *   - De-referencing
 *   - nullptr
 *  - Pass-by-reference
 *  - References
 * 4. Classes:
 *  - Pass-by-reference with pointer
 *  - De-reference notation (->)
 *  - "this" keyword
 */

#define RED    0
#define ORANGE 1
#define YELLOW 2
#define GREEN  3
#define BLUE   4
#define INDIGO 5
#define VIOLET 6

#define NUM_COLOURS     7

#define NUM_READ  5
#define NUM_PROPS 2

#define PROP_COLOUR  0
#define PROP_NUMBER  1

// Card class
class Card {
public:
   Card(int colour, int number);

   int getColour();
   int getNumber();

private:
   int colour;
   int number;
};

void printCards(int cards[NUM_READ][NUM_PROPS]);
void printCard(Card* card);
void printRule(int colour);

bool readCard(int* colour, int* number);


int main(void) {

   // Goal: Implement Red 7!
   // Starting point: Represent Cards
   // int number = 1;
   // int colour = 0;
   // int cardsPerColour = 7;
   // int totalColours = 7;
   // int totalCards = cardsPerColour * totalColours;

   // std::cout << "Card Colour: " << colour << "\n";
   // std::cout << "Card Number: " << number << std::endl;
   // std::cout << "Total cards: " << totalCards << std::endl;

   // Read Colours from User (with defines)
   // int cards[NUM_READ][NUM_PROPS] = {};
   for (int i = 0;  i < NUM_READ; ++i) {
      int colour = 0;
      int number = 0;
      
      bool read = readCard(&colour, &number);

      if (read) {
         Card card(colour, number);
         printCard(&card);

         // cards[i][PROP_COLOUR] = colour;
         // cards[i][PROP_NUMBER] = number;
      }
   }

   // printCards(cards);

   return EXIT_SUCCESS;
}

bool readCard(int* colour, int* number) { 
   bool success = false;
   std::cin >> *colour;
   
   if (std::cin.good()) {
      std::cin >> *number;
      if (std::cin.good()) {
         success = true;
      }
   }

   return success;
}

void printCards(int cards[NUM_READ][NUM_PROPS]) {
   for (int i = 0; i != NUM_READ; ++i) {
      // Comment out when we change this for a card
      // printCard(cards[i][PROP_COLOUR], cards[i][PROP_NUMBER]);
   }
}



void printCard(Card* card) {
   // Show Variable Scope
   std::string red = "Red";
   std::string orange = "Orange";
   std::string yellow = "Yellow";
   std::string green = "Green";
   std::string blue = "Blue";
   std::string indigo = "Ingido";
   std::string violet = "Violet";
   std::string unknown = "UNKNOWN";

   // Setting colour here:
   // colour = 100

   int colour = card->getColour();
   int number = card->getNumber();
   
   std::cout << "Card: ";
   if (colour == RED) {
      std::cout << red;
   } else if (colour == ORANGE) {
      std::cout << orange;
   } else if (colour == YELLOW) {
      std::cout << yellow;
   } else if (colour == GREEN) {
      std::cout << green;
   } else if (colour == BLUE) {
      std::cout << blue;
   } else if (colour == INDIGO) {
      std::cout << indigo;
   } else if (colour == VIOLET) {
      std::cout << violet;
   } else {
      std::cout << unknown;
   }
   std::cout << " " << number << std::endl;
}

void printRule(int colour) {
   if (colour == RED) {
      std::cout << "Highest Card";
   } else if (colour == ORANGE) {
      std::cout << "Most of one Number";
   } else if (colour == YELLOW) {
      std::cout << "Most of one Colour";
   } else if (colour == GREEN) {
      std::cout << "Most Even Cards";
   } else if (colour == BLUE) {
      std::cout << "Most different Colours";
   } else if (colour == INDIGO) {
      std::cout << "Most Cards in a Row";
   } else if (colour == VIOLET) {
      std::cout << "Most Cards below 4";
   } else {
      std::cout << "???";
   }
   std::cout << std::endl;

   return;
}


Card::Card(int colour, int number)
   // colour(colour),
   // number(number)
 {
   this->colour = colour;
   this->number = number;
}

int Card::getColour() {
   return colour;
}


int Card::getNumber() {
   return number;
}

