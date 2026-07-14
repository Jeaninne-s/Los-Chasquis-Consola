#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

class Personaje {
private:
	int vida, posicionX, posicionY, velocidad, fuerza;
public:
	Personaje(int vida, int posicionX, int posicionY, int velocidad, int fuerza);
	~Personaje();
	void mostrarInformacion();
};

Personaje::Personaje( int vida, int posicionX, int posicionY, int velocidad, int fuerza) {
	this->vida = vida;
	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->velocidad = velocidad;
	this->fuerza = fuerza;
}
Personaje::~Personaje() {};

void Personaje::mostrarInformacion() {
	cout << "Vida: " << vida << endl;
	cout << "Posicion X: " << posicionX << endl;
	cout << "Posicion Y: " << posicionY << endl;
	cout << "Velocidad: " << velocidad << endl;
	cout << "Fuerza: " << fuerza << endl;
}

