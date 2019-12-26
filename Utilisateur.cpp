#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Include.hh"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Utilisateur::Utilisateur():j() {}

Utilisateur::~Utilisateur() {}

bool Utilisateur::connection() {
	std::ifstream i("file.json");
	i >> this->j;
	
	string username;
	string password;
	
	cout << "Enter your username : ";
	cin >> username;
	cout << "Enter your password : ";
	cin >> password;
	
	if(!this->j[username].empty() && this->j[username]["password"] == password) {
		if(this->j[username]["history"] == nullptr) {
			std::ofstream o("file.json");
			this->j[username]["history"] = 5;
			o << this->j;
		}
		return true;
	}
	cout << "Error connection" << endl;
	return false;
}
