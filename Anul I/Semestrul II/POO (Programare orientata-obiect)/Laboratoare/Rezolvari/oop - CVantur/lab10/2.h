#ifndef SEMAFOR_H
#define SEMAFOR_H

#define NMAX 10

class Semafor
{
private:
	static int nrInstante;
	Semafor();
	~Semafor();

public:
	static Semafor* create();
	static void destroy(Semafor *s);
};

#endif