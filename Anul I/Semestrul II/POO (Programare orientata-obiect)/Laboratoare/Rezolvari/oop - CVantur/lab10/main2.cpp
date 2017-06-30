#include "2.h"
using namespace std;

int main()
{
	Semafor *s1 = Semafor::create();
	Semafor *s2 = Semafor::create();
	Semafor *s3 = Semafor::create();

	Semafor::destroy(s1);
	Semafor::destroy(s2);
	Semafor::destroy(s3);

	return 0;
}