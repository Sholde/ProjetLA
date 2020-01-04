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
		this->number = this->j[username]["date"].size();
		return true;
	}
	cout << "Connection error" << endl;
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
	time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
  string str(buffer);
  cout << endl;
  cout << "We are the " << str << endl << endl;
	cout << "History :"<< endl << endl;
	
	int size = this->number;
	
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
	this->j[this->user]["rating"][this->number] = rate;
}

void Utilisateur::addDate() {
	time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
  string str(buffer);
	this->j[this->user]["date"][this->number] = str;
}

void Utilisateur::addHistory() {
	this->j[this->user]["history"][this->number] = "nothing";
}

void Utilisateur::printJson() {
	ofstream o("file.json");
	o << this->j;
}
