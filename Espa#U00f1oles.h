#pragma once
#include <string>
#include <vector>
#include "iostream"
#include "Personaje.h"
using namespace System;
using namespace std;

class Espanoles : public Personaje {
private:
	int x, y;
		std::string nombre, caracteristicas;
		bool estado;
		int getx();
		int gety();
		void setx(int valor);
		void sety(int valor);
public:
	Espanoles(std::string nombre, std::string caracteristicas, bool estado);
	~Espanoles();
	bool actualizar_estado(bool nuevo_estado);
	void dibujar_espanol();
	void borrar_español();
	void ubicar(int nuevoX, int nuevoY) {
		x = nuevoX;
		y = nuevoY;
	}
};

Espanoles::Espanoles(std::string nombre, std::string caracteristicas, bool estado) : Personaje(3, 0, 0, 1, 1)
{
	this->nombre = nombre;
	this->caracteristicas = caracteristicas;
	this->estado = estado;
}

Espanoles::~Espanoles() {};

bool Espanoles::actualizar_estado(bool nuevo_estado) {
	estado = nuevo_estado;
	return estado;
}

void Espanoles::dibujar_espanol() {
	Console::SetCursorPosition(x, y); cout << "[0]" << std::endl;
	Console::SetCursorPosition(x, y+1); cout << "/|\\+" << std::endl;
	Console::SetCursorPosition(x, y+2); cout << "/ \\" << std::endl;
}

void Espanoles::borrar_español() {
	Console::SetCursorPosition(x, y); cout << "     " << std::endl;
	Console::SetCursorPosition(x, y+1); cout << "     " << std::endl;
	Console::SetCursorPosition(x, y+2); cout << "     " << std::endl;
}

int Espanoles::getx() { return x; }
int Espanoles::gety() { return y; }
void Espanoles::setx(int valor) { x = valor; }
void Espanoles::sety(int valor) { y = valor; }