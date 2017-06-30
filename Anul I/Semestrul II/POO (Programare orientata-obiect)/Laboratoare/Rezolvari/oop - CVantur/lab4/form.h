class Forma {

   public:

      virtual double ComputeArea() = 0;

      virtual const char * GetName() = 0;

};

class Dreptunghi : public Forma {

      int Latime,Lungime;

   public:

      Dreptunghi(int lungime,int latime);

      double ComputeArea();

      const char * GetName();

};

class Cerc : public Forma {

      int Raza;

   public:

      Cerc(int raza);

      double ComputeArea();

      const char * GetName();

};

class Triunghi : public Forma {

      int X1,Y1,X2,Y2,X3,Y3;

   public:

      Triunghi(int x1,int y1,int x2,int y2,int x3,int y3);

      double ComputeArea();

      const char * GetName();

};