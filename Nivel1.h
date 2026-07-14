#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#include "Mapas.h"
#include "Chasquis.h"
#include "Zorro.h"
#include "Puma.h"

using namespace std;
using namespace System;

class Nivel1 {
private:
	int xChasqui, yChasqui;
	int xPuma, yPuma;
	int vidas, tiempo;

	bool zorroActivo;
	bool zorroPuenteActivo;
	bool zorroPuenteMostrado;
	bool puenteRespondido;

	DWORD tiempoParaZorroPuente;

	Chasquis chasqui;
	Zorro zorro;
	Puma puma;

	static const int ZORRO_X = 10;
	static const int ZORRO_Y = 0;

	static const int ZORRO_TOCA_X = 10;
	static const int ZORRO_TOCA_Y = 0;

	static const int ZORRO_PUENTE_X = 31;
	static const int ZORRO_PUENTE_Y = 13;

	static const int META_X = 64;
	static const int META_Y = 27;

public:
	Nivel1() :
		chasqui("Chasqui", "Mensajero del imperio", true),
		zorro("Zorro", "Guardian del camino", "Atajo o camino normal", true),
		puma("Puma", "Animal peligroso", true)
	{
		xChasqui = 0;
		yChasqui = 0;

		xPuma = 35;
		yPuma = 8;

		vidas = 10;
		tiempo = 120;

		zorroActivo = true;
		zorroPuenteActivo = false;
		zorroPuenteMostrado = false;
		puenteRespondido = false;

		tiempoParaZorroPuente = 0;

		srand(time(NULL));
	}

	void ocultarCursor() {
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

	void pintarCelda(int y, int x, int matriz[FILAS][COLUMNAS]) {
		if (x < 0 || x >= COLUMNAS || y < 0 || y >= FILAS) return;

		Console::SetCursorPosition(x, y);

		switch (matriz[y][x]) {
		case 0: color(VERDE); cout << char(219); break;
		case 1: color(MARRON); cout << char(219); break;
		case 2: color(CELESTE); cout << char(219); break;
		case 3: color(ROJO); cout << char(219); break;
		case 4: color(ROSA); cout << "*"; break;
		case 5: color(ROJO); cout << char(219); break;
		}
	}

	void prepararZonasImportantes() {
		for (int j = 0; j <= ZORRO_TOCA_X + 2; j++) {
			Mapas::mostrarMapaNivel1[1][j] = 1;
		}

		Mapas::mostrarMapaNivel1[ZORRO_PUENTE_Y + 1][ZORRO_PUENTE_X + 1] = 3;
		Mapas::mostrarMapaNivel1[ZORRO_PUENTE_Y][ZORRO_PUENTE_X] = 3;

		Mapas::mostrarMapaNivel1[META_Y][META_X] = 3;
		Mapas::mostrarMapaNivel1_opcion2[META_Y][META_X] = 3;
	}

	void borrarChasqui(int y, int x, int matriz[FILAS][COLUMNAS]) {
		for (int i = y; i <= y + 2; i++) {
			for (int j = x; j <= x + 2; j++) {
				pintarCelda(i, j, matriz);
			}
		}
	}

	void dibujarChasqui() {
		chasqui.ubicar(xChasqui, yChasqui);
		color(BLANCO);
		chasqui.dibujar_chasqui1();
	}

	void dibujarZorroInicial() {
		zorro.ubicar(ZORRO_X, ZORRO_Y);
		color(ROSA);
		zorro.dibujar_zorro();
	}

	void dibujarZorroPuente() {
		zorro.ubicar(ZORRO_PUENTE_X, ZORRO_PUENTE_Y);
		color(ROSA);
		zorro.dibujar_zorro();
	}

	void borrarZorroPuente() {
		zorro.ubicar(ZORRO_PUENTE_X, ZORRO_PUENTE_Y);
		zorro.borrar_zorro();
	}

	void dibujarPuma() {
		puma.ubicar(xPuma, yPuma);
		color(ROJO);
		puma.dibujar_puma();
	}

	void borrarPuma() {
		for (int i = yPuma; i <= yPuma + 2; i++) {
			for (int j = xPuma; j <= xPuma + 10; j++) {
				pintarCelda(i, j, Mapas::mostrarMapaNivel1_opcion2);
			}
		}
	}

	void dibujarMeta() {
		Console::SetCursorPosition(META_X, META_Y);
		color(BLANCO);
		cout << "M";
	}

	void mostrarDatos() {
		Console::SetCursorPosition(0, 31);
		color(BLANCO);
		cout << "Vidas: " << vidas << "   Tiempo: " << tiempo << " segundos       ";
	}

	bool puedeMover(int nuevaX, int nuevaY, int matriz[FILAS][COLUMNAS]) {
		int pechoX = nuevaX + 1;
		int pechoY = nuevaY + 1;

		if (pechoX < 0 || pechoX >= COLUMNAS || pechoY < 0 || pechoY >= FILAS) {
			return false;
		}

		if (matriz[pechoY][pechoX] == 1 || matriz[pechoY][pechoX] == 3) {
			return true;
		}

		return false;
	}

	void moverChasquiNivel1() {
		int nuevaX = xChasqui;
		int nuevaY = yChasqui;

		if (_kbhit()) {
			char tecla = _getch();

			if (tecla == 'w' || tecla == 'W') nuevaY--;
			if (tecla == 's' || tecla == 'S') nuevaY++;
			if (tecla == 'a' || tecla == 'A') nuevaX--;
			if (tecla == 'd' || tecla == 'D') nuevaX++;

			if (puedeMover(nuevaX, nuevaY, Mapas::mostrarMapaNivel1)) {
				borrarChasqui(yChasqui, xChasqui, Mapas::mostrarMapaNivel1);

				xChasqui = nuevaX;
				yChasqui = nuevaY;

				dibujarMeta();
				dibujarChasqui();
			}
		}
	}

	void moverChasquiAtajo() {
		int nuevaX = xChasqui;
		int nuevaY = yChasqui;

		if (_kbhit()) {
			char tecla = _getch();

			if (tecla == 'w' || tecla == 'W') nuevaY--;
			if (tecla == 's' || tecla == 'S') nuevaY++;
			if (tecla == 'a' || tecla == 'A') nuevaX--;
			if (tecla == 'd' || tecla == 'D') nuevaX++;

			if (nuevaX >= 0 && nuevaX < COLUMNAS && nuevaY >= 0 && nuevaY < FILAS) {
				borrarChasqui(yChasqui, xChasqui, Mapas::mostrarMapaNivel1_opcion2);

				xChasqui = nuevaX;
				yChasqui = nuevaY;

				dibujarMeta();
				dibujarChasqui();
			}
		}
	}

	void moverPuma() {
		int nuevaX = xPuma;
		int nuevaY = yPuma;

		int direccion = rand() % 4;

		if (direccion == 0) nuevaY--;
		if (direccion == 1) nuevaY++;
		if (direccion == 2) nuevaX--;
		if (direccion == 3) nuevaX++;

		if (nuevaX >= 0 && nuevaX < COLUMNAS - 10 && nuevaY >= 0 && nuevaY < FILAS - 3) {
			borrarPuma();

			xPuma = nuevaX;
			yPuma = nuevaY;

			dibujarMeta();
			dibujarPuma();
		}
	}

	bool ejecutarAtajo() {
		system("cls");

		xChasqui = 0;
		yChasqui = 0;

		xPuma = 35;
		yPuma = 8;

		Mapas::pintarMapaNivel1_opcion2();

		dibujarMeta();
		dibujarChasqui();
		dibujarPuma();
		mostrarDatos();

		DWORD relojTiempo = GetTickCount();
		DWORD relojPuma = GetTickCount();

		while (true) {
			if (GetTickCount() - relojTiempo >= 1000) {
				tiempo--;
				relojTiempo = GetTickCount();
				mostrarDatos();
			}

			if (GetTickCount() - relojPuma >= 350) {
				moverPuma();
				relojPuma = GetTickCount();
			}

			moverChasquiAtajo();

			if (xChasqui == xPuma && yChasqui == yPuma) {
				vidas -= 2;
				mostrarDatos();

				borrarPuma();
				xPuma = 35;
				yPuma = 8;
				dibujarPuma();
			}

			if (vidas <= 0) {
				system("cls");
				cout << "PERDISTE: el puma te quito todas las vidas." << endl;
				return false;
			}

			if (tiempo <= 0) {
				system("cls");
				cout << "PERDISTE: se acabo el tiempo." << endl;
				return false;
			}

			if (xChasqui == META_X && yChasqui == META_Y) {
				system("cls");
				cout << "GANASTE EL NIVEL 1 POR EL ATAJO." << endl;
				return true;
			}

			Sleep(40);
		}
	}

	bool iniciar() {
		ocultarCursor();
		prepararZonasImportantes();

		system("cls");
		Mapas::pintarMapaNivel1();

		dibujarMeta();
		dibujarChasqui();
		dibujarZorroInicial();
		mostrarDatos();

		DWORD relojTiempo = GetTickCount();

		while (true) {
			if (GetTickCount() - relojTiempo >= 1000) {
				tiempo--;
				relojTiempo = GetTickCount();
				mostrarDatos();
			}

			moverChasquiNivel1();

			if (tiempo <= 0) {
				system("cls");
				cout << "PERDISTE: se acabo el tiempo." << endl;
				return false;
			}

			if (xChasqui == ZORRO_TOCA_X && yChasqui == ZORRO_TOCA_Y && zorroActivo == true) {
				int respuesta = zorro.pregunta_inicial();

				if (respuesta == 1) {
					return ejecutarAtajo();
				}
				else {
					zorroActivo = false;
					zorroPuenteActivo = true;
					tiempoParaZorroPuente = GetTickCount();

					system("cls");
					Mapas::pintarMapaNivel1();

					dibujarMeta();
					dibujarChasqui();
					mostrarDatos();
				}
			}

			if (zorroPuenteActivo == true && zorroPuenteMostrado == false) {
				if (GetTickCount() - tiempoParaZorroPuente >= 5000) {
					dibujarZorroPuente();
					zorroPuenteMostrado = true;
				}
			}

			if (abs(xChasqui - ZORRO_PUENTE_X) <= 1 &&
				abs(yChasqui - ZORRO_PUENTE_Y) <= 1 &&
				puenteRespondido == false &&
				zorroPuenteMostrado == true) {

				puenteRespondido = true;

				borrarZorroPuente();

				bool paso = zorro.mostrar_pregunta(tiempo);

				system("cls");
				Mapas::pintarMapaNivel1();

				dibujarMeta();
				dibujarChasqui();
				mostrarDatos();

				if (tiempo <= 0) {
					system("cls");
					cout << "PERDISTE: te quedaste sin tiempo." << endl;
					return false;
				}

				if (paso == false) {
					system("cls");
					cout << "PERDISTE: no respondiste ninguna pregunta correctamente." << endl;
					return false;
				}
			}

			if (xChasqui == META_X && yChasqui == META_Y) {
				system("cls");
				cout << "GANASTE EL NIVEL 1." << endl;
				return true;
			}

			Sleep(40);
		}
	}
};