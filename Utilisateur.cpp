#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Utilisateur.hh"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include <ctime>

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
	time_t now = time(0);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	cout << nowLocal.tm_mday << "/" << nowLocal.tm_mon+1 << "/" << nowLocal.tm_year+1900 << " " << nowLocal.tm_hour << ":" << nowLocal.tm_min << endl;
	cout << "History :"<< endl << endl;
	
	int size = this->j[this->user]["history"].size();
	
	if(size == 0) {
		cout << "No history" << endl << endl;
		return;
	}
	
	while(size > 0) {
		size--;
		cout << "Date : " << this->j[this->user]["date"][size] << endl;
		cout << "Rating : " << this->j[this->user]["rating"][size] << endl;
		cout << "History : " << this->j[this->user]["history"][size] << endl;
		cout << endl;
	}
}

void Utilisateur::addRating(int rate) {
	int size = this->j[this->user]["rating"].size();
	this->j[this->user]["rating"][size] = rate;
}

void Utilisateur::addDate() {
	time_t now = time(0);
	struct tm nowLocal;
	nowLocal = *localtime(&now);
	string date;
	date += nowLocal.tm_mday;
	date += "/";
	date += nowLocal.tm_mon+1;
	date += "/";
	date += nowLocal.tm_year+1900;
	date += " ";
	date += nowLocal.tm_hour;
	date += ":";
	date += nowLocal.tm_min;
	int size = this->j[this->user]["date"].size();
	this->j[this->user]["date"][size] = date;
}

void Utilisateur::addHistory() {
	int size = this->j[this->user]["history"].size();
	this->j[this->user]["history"][size] = "noting";
}

void Utilisateur::printJson() {
	std::ofstream o("file.json");
	o << this->j;
}
