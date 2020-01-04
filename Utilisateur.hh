#ifndef _Utilisateur_hh
#define _Utilisateur_hh

#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <string>
using namespace std;

class Utilisateur {
	
	json j;
	string user;
	int number;
	bool history;
	bool play;
	
	public:
		Utilisateur();
		~Utilisateur();
		
		bool connection();
		void choose();
		bool getPlay();
		bool getHistory();
		void printHistory();
		void checkRating();
		
		void zero();
		void addRating(int rate);
		void addDate();
		void addHistory(string str);
		void printJson();
};

#endif
