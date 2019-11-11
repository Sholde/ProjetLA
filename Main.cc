#include "Include.h"
#include <list>
#include <iostream>
#include <string.h>

int main() {
	Pompe p11, p12, p21, p22, p31, p32;
	Reservoir 	tank1(p11, p12),
				tank2(p21, p22),
				tank3(p31, p32);
	Vanne V12, V13, V23, VT12, VT23;
	list<Module> a;
	Moteur m1("m1", a), m2("m2", a), m3("m3", a);
	cout << m1;
	return 0;
}
