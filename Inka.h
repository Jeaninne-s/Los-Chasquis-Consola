#pragma once
#include <string>
#include <vector>
#include "iostream"
#include "Personaje.h"
using namespace System;
using namespace std;

class Inka :public Personaje {
private: 	
	int vida, x, y, dx,dy, velocidad, fuerza;
	bool estado;
	int getx();
	int gety();
	void setx(int valor);
	void sety(int valor);
public:
	Inka(int vida, int posicionX, int posicionY, int velocidad, int fuerza, bool estado);
	~Inka();
	void dibujar_inka();
	void borrar_inka();
	void estado_inka();
	void ubicar(int nuevoX, int nuevoY) {
		x = nuevoX;
		y = nuevoY;
	}
};

Inka::Inka(int vida, int posicionX, int posicionY, int velocidad, int fuerza, bool estado) : Personaje(vida, posicionX, posicionY, velocidad, fuerza)
{
	this->x = posicionX;
	this->y = posicionY;
	this->dx = 0;
	this->dy = 0;
	this->estado = estado;
}

Inka::~Inka() {};

void Inka::dibujar_inka() {
	Console::SetCursorPosition(x, y); cout << "-M-" << endl;
	Console::SetCursorPosition(x, y + 1); cout << " 0 " << endl;
	Console::SetCursorPosition(x, y + 2); cout << "/|\\" << endl;
	Console::SetCursorPosition(x, y + 3); cout << "/ \\" << endl;
}

void Inka::borrar_inka() {
	Console::SetCursorPosition(x, y); cout << "    " << endl;
	Console::SetCursorPosition(x, y+1); cout << "    " << endl;
	Console::SetCursorPosition(x, y+2); cout << "    " << endl;
	Console::SetCursorPosition(x, y+3); cout << "    " << endl;
}

void Inka::estado_inka() {
	if (estado) {
		cout << "El Inca esta vivo" << endl;
	}
	else {
		cout << "El Inca esta muerto" << endl;
	}
}

int Inka::getx() { return x; }
int Inka::gety() { return y; }
void Inka::setx(int valor) { x = valor; }
void Inka::sety(int valor) { y = valor; }