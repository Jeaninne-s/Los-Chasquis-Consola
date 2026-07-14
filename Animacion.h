#pragma once
#include "Zorro.h"
#include "Puma.h"
#include "Personaje.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

void mover_Puma() {
	Puma puma("Puma", "Rápido y sigiloso", true);
	puma.mostrarInformacion();
	puma.dibujar_puma();
	Sleep(500); // Pausa para mostrar la primera posición
	system("cls"); // Limpia la consola
}
