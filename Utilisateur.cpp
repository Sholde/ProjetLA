#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Utilisateur.hh"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Utilisateur::Utilisateur():j(), user() {
	this->play = false;
	this->history = false;
}

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
		this->user = username;
		return true;
	}
	cout << "Error connection" << endl;
	return false;
}

void Utilisateur::choose() {
	char letter;
	cout << "Press P for play or H to watch the history : ";
	cin >> letter;
	if(letter == 'p') {
		this->play = true;
	}
	else if(letter == 'h') {
		this->history = true;
	}
}

bool Utilisateur::getHistory() {
	return this->history;
}

bool Utilisateur::getPlay() {
	return this->play;
}

void Utilisateur::printHistory() {
	cout << "History :"<< endl << endl;
	
	int i = 0;
	int size = this->j[this->user]["history"].size();
	
	if(size == 0) {
		cout << "No history" << endl << endl;
		return;
	}
	
	while(i < size) {
		cout << "Note : " << this->j[this->user]["note"][i] << endl;
		cout << "History : " << this->j[this->user]["history"][i] << endl;
		i++;
	}
	cout << endl;
}
