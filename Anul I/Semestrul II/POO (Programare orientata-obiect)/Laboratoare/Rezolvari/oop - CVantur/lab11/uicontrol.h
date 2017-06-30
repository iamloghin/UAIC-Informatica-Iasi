#include "print.h"

class UIControl
{

   protected:

      int X,Y,Width,Height; // coordonatele controlului

      UIControl *Parent; // Parintele controlului (NULL inseamna ca nu are parinte)

   public:

      virtual void Paint() = 0; // functie care deseneaza controlul
      int getX();
      int getY();

};