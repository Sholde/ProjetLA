#ifndef _Utilisateur_hh
#define _Utilisateur_hh

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Include.hh"

class Utilisateur {
	
	json j;
	
	public:
		Utilisateur();
		~Utilisateur();
		
		bool connection();
};

#endif
