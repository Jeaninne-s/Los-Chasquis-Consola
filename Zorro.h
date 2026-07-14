#pragma once
#include <string>
#include <conio.h>
#include "windows.h"
#include "Personaje.h"
#include <iostream>

using namespace System;
using namespace std;

class Zorro : public Personaje {
private:
	int x, y;
	string nombre, caracteristicas, pregunta;
	bool estado;

public:
	Zorro(string nombre, string caracteristicas, string pregunta, bool estado);
	~Zorro();

	void ubicar(int nuevoX, int nuevoY);

	void dibujar_zorro();
	void borrar_zorro();

	bool actualizar_estado(bool nuevo_estado);

	int pregunta_inicial();
	bool mostrar_pregunta(int& tiempo);
};

Zorro::Zorro(string nombre, string caracteristicas, string pregunta, bool estado)
	: Personaje(2, 0, 0, 2, 1)
{
	this->nombre = nombre;
	this->caracteristicas = caracteristicas;
	this->pregunta = pregunta;
	this->estado = estado;

	x = 0;
	y = 0;
}

Zorro::~Zorro() {}

void Zorro::ubicar(int nuevoX, int nuevoY) {
	x = nuevoX;
	y = nuevoY;
}

void Zorro::dibujar_zorro() {
	Console::SetCursorPosition(x, y); cout << " /\\   /\\\\";
	Console::SetCursorPosition(x, y+1); cout << "(  ^_^  )";
	Console::SetCursorPosition(x, y+2); cout << " \\_=_/";
}
void Zorro::borrar_zorro() {
	for (int i = 0; i <= 10; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << "        ";
	}
}

bool Zorro::actualizar_estado(bool nuevo_estado) {
	estado = nuevo_estado;
	return estado;
}

int Zorro::pregunta_inicial() {
	int respuesta;

	system("cls");

	cout << "Hola querido Chasqui, puesto que es urgente la entrega del mensaje que llevas," << endl;
	cout << "te mostrare un camino adicional." << endl;
	cout << "Por este lado hay un camino corto que te permitira llegar con menor tiempo," << endl;
	cout << "sin embargo, al ser un camino poco recorrido, habran mas peligros." << endl;
	cout << endl;

	cout << "1. Atajo" << endl;
	cout << "2. Continuar" << endl;
	cout << "Respuesta: ";
	cin >> respuesta;

	return respuesta;
}

bool Zorro::mostrar_pregunta(int& tiempo) {
	int opcion;
	int op;
	int al;
	int r;
	int res;

	bool respondioBien = false;

	system("cls");

	cout << "Quien dio la orden para iniciar la construccion de Machu Picchu y Sacsayhuaman??" << endl;
	cout << "1. Manco Capac" << endl;
	cout << "2. Sinchi Roca" << endl;
	cout << "3. Pachacutec" << endl;
	cout << "SELECCIONA UNA OPCION: ";
	cin >> opcion;

	if (opcion == 3) {
		cout << "Respuesta correcta!" << endl;
		tiempo += 10;
		respondioBien = true;
	}
	else {
		cout << "La respuesta es incorrecta" << endl;
		tiempo -= 10;

		if (tiempo <= 0) return false;

		cout << "Quieres intentarlo de nuevo? (1. Si, 2. No): ";
		cin >> op;

		if (op == 1) {
			cout << endl;
			cout << "Quien fue el mas grande conquistador militar del Imperio de los Incas?" << endl;
			cout << "1. Tupac Yupanqui" << endl;
			cout << "2. Pachacutec" << endl;
			cout << "3. Sinchi Roca" << endl;
			cout << "SELECCIONA UNA OPCION: ";
			cin >> al;

			if (al == 1) {
				cout << "Respuesta correcta!" << endl;
				tiempo += 10;
				respondioBien = true;
			}
			else {
				cout << "La respuesta es incorrecta" << endl;
				tiempo -= 10;

				if (tiempo <= 0) return false;

				cout << "Quieres intentarlo de nuevo? (1. Si, 2. No): ";
				cin >> r;

				if (r == 1) {
					cout << endl;
					cout << "Cual fue el ultimo emperador inca antes de la conquista espanola?" << endl;
					cout << "1. Atahualpa" << endl;
					cout << "2. Huayna Capac" << endl;
					cout << "3. Manco Capac" << endl;
					cout << "SELECCIONA UNA OPCION: ";
					cin >> res;

					if (res == 1) {
						cout << "Respuesta correcta!" << endl;
						tiempo += 10;
						respondioBien = true;
					}
					else {
						cout << "La respuesta es incorrecta" << endl;
						tiempo -= 10;
					}
				}
				else {
					cout << "Gracias por jugar!" << endl;
				}
			}
		}
		else {
			cout << "Gracias por jugar!" << endl;
		}
	}

	cout << endl;
	cout << "Presiona una tecla para continuar...";
	_getch();

	return respondioBien;
}