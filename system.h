#ifnedf _System_h
#define _System_h

class System {
	private:
		Reservoir tank1, tank2, tank3;
		Vanne V12, V13, V23, VT12, VT23;
		Pompe p11, p12, p21, p22, p31, p32;
		Moteur m1, m2, m3;
	public;
		System();
		~System();
};

#endif
