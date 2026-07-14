#pragma once
#include <string>
#include "Personaje.h"

class Puma : public Personaje {
	private:
	int vida, x,y, dx,dy, velocidad, fuerza;
	string nombre, caracteristicas;
	bool estado;
	int getx();
	int gety();
	void setx(int valor);
	void sety(int valor);
public:
	Puma(string nombre, string caracteristicas, bool estado);
	~Puma();
	void dibujar_puma();
	void mover_puma();
	void borrar_puma();
	bool actualizar_estado(bool nuevo_estado);
	int atacar();
	void ubicar(int nuevoX, int nuevoY) {
		x = nuevoX;
		y = nuevoY;
	}
};

Puma::Puma(string nombre, string caracteristicas, bool estado) : Personaje(4, 0, 0, 3, 2)
{
	this->nombre = nombre;
	this->caracteristicas = caracteristicas;
	this->estado = estado;
}

Puma::~Puma() {};

void Puma::dibujar_puma() {
	Console::SetCursorPosition(x, y); cout << " /\\_____/\\\\";
	Console::SetCursorPosition(x, y + 1); cout << "(  > <  )";
	Console::SetCursorPosition(x, y + 2); cout << " \\__^__/";
}

void Puma::borrar_puma() {
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << "              ";
	}
}

bool Puma::actualizar_estado(bool nuevo_estado) {
	estado = nuevo_estado;
	return estado;
}

int Puma::atacar() {
	int danio = fuerza * 2;
	return danio;
}

void Puma::mover_puma() {
	if (x < 1 || x>60) dx *= -1;
	if (y < 1 || y>19) dy *= -1;
	x += dx;
	y += dy;
}

int Puma::getx() { return x; }
int Puma::gety() { return y; }
void Puma::setx(int valor) { x = valor; }
void Puma ::sety(int valor) { y = valor; }