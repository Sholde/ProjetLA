#include "Include.hh"
#include <iostream>
using namespace std;

VanneNormal::VanneNormal(const char* name):Vanne(name) {
	
}

VanneNormal::~VanneNormal() {}

void VanneNormal::initLeft(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->left.push_back(r);
	this->left.push_back(v);
	this->left.push_back(m);
}

void VanneNormal::initRight(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->right.push_back(r);
	this->right.push_back(v);
	this->right.push_back(m);
}

void VanneNormal::render() {
	cout << this->getName() << " : " << endl << "\t";
	for(Module* m : left) {
		cout << m->getName() << " ";
	}
	cout << endl << "\t";
	for(Module* m : right) {
		cout << m->getName() << " ";
	}
	cout << endl;
}
