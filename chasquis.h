#pragma once
#include <string>
#include <vector>
#include "iostream"
#include "Personaje.h"
using namespace System;
using namespace std;

class Chasquis : public Personaje {
private:
	string nombre, caracteristicas;
	bool estado;
	int x, y, px, py, velocidad;
	int getx();
	int gety();
	void setx(int valor);
	void sety(int valor);
public:
	Chasquis(string nombre, string caracteristicas, bool estado);
	~Chasquis();
	void mostrarInformacion();
	void dibujar_chasqui1();
	void dibujar_chasqui2();
	void dibujar_chasqui3();
	void borrar_chasqui();
	bool  actualizar_estado(bool nuevo_estado);
	void mover(); 
	void ubicar(int nuevoX, int nuevoY) {
		x = nuevoX;
		y = nuevoY;
	}
};

Chasquis::Chasquis(string nombre, string caracteristicas, bool estado): Personaje(3, 0, 0, 1, 1) 
{
	this->nombre = nombre;
	this->caracteristicas = caracteristicas;
	this->estado = estado;
}

Chasquis::~Chasquis() {};

void Chasquis::mostrarInformacion() {
	cout << "Nombre: " << nombre << endl;
	cout << "Caracteristicas: " << caracteristicas << endl;
	cout << "Estado: " << estado << endl;
}

void Chasquis::dibujar_chasqui1(){
	Console::SetCursorPosition(x, y);   cout << " 0" << endl;
	Console::SetCursorPosition(x, y+1); cout << "/|\\" << endl;
	Console::SetCursorPosition(x, y+2); cout << "/ \\" << endl;
}

void Chasquis::dibujar_chasqui2() {
	Console::SetCursorPosition(x, y);   cout << " 0 " << endl;
	Console::SetCursorPosition(x, y+1); cout << "\\|\\" << endl;
	Console::SetCursorPosition(x, y+2); cout << "/ \\" << endl;
}

void Chasquis::dibujar_chasqui3() {
	Console::SetCursorPosition(x, y);   cout << " 0 " << endl;
	Console::SetCursorPosition(x, y+1); cout << "/|\\" << endl;
	Console::SetCursorPosition(x, y+2); cout << "< >" << endl;
}

void Chasquis::borrar_chasqui() {
	Console::SetCursorPosition(x, y); cout << "    " << endl;
	Console::SetCursorPosition(x, y+1); cout << "    " << endl;
	Console::SetCursorPosition(x, y+2); cout << "    " << endl;
}

bool Chasquis::actualizar_estado(bool nuevo_estado) {
	estado = nuevo_estado;
	if (nuevo_estado) {
		return true; // El chasqui está vivo
	}
	else {
		return false; // El chasqui está muerto
	}
}


void Chasquis::mover() {
	if (_kbhit()) {
		int ch = _getch();
		if (ch == 0 || ch == 224) {
			int ch2 = _getch();
			if (ch2 == 72) py--; // up
			if (ch2 == 80) py++; // down
			if (ch2 == 75) px--; // left
			if (ch2 == 77) px++; // right
		}
	}
}

int Chasquis::getx() { return x; }
int Chasquis::gety() { return y; }
void Chasquis::setx(int valor) { x = valor; }
void Chasquis::sety(int valor) { y = valor; }