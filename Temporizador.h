#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class Cronometro {
private:
	int tiempo = 0;
public:
	Cronometro(int _tiempo);
	~Cronometro();

	void iniciar();
	int DisminuirTiempo();
	bool TiempoAcabado();
};

Cronometro::Cronometro(int _tiempo) {
	tiempo = _tiempo;
}

void Cronometro::iniciar() {
	while (1) {
		tiempo--;
		_sleep(1000);
		cout << "Tiempo restante: " << tiempo << "   \r";
	}
}

bool Cronometro::TiempoAcabado() {
	if (tiempo <= 0) {
		return true;
	}
	else {
		return false;
	}
}