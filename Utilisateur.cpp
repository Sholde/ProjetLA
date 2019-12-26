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
	
	if(this->j["username"] == username && this->j["password"] == password) {
		return true;
	}
	cout << "Error" << endl;
	return false;
}
