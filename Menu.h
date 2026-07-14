#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// --- CONFIGURACIÓN DE COLORES Y MATRIZ ---
#define CL_CIELO 0
#define CL_PIEDRA 1
#define CL_PASTO 2
#define CL_CAMINO 3
#define CL_ENEMIGO 4
#define CL_PUERTA 5
#define CL_AGUA 6

// Matriz de 30x80 
int mapaIntro[30][80] = {
    {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,0,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,5,0,0,0,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,5,5,3,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {6,6,6,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
    {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}
};

//// --- UTILITARIOS ---
//void gotoxy(int x, int y) {
//    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD dwPos = { (SHORT)x, (SHORT)y };
//    SetConsoleCursorPosition(hcon, dwPos);
//}
//
//
//    // ESTA ES LA FUNCIÓN QUE PINTA TU MATRIZ
//    void pintarPresentacion() {
//        system("mode con cols=80 lines=32"); // Ajusta la consola
//        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//        for (int i = 0; i < 30; i++) {
//            for (int j = 0; j < 80; j++) {
//                int id = mapaIntro[i][j];
//
//                // colores
//                switch (id) {
//                case CL_CIELO:   SetConsoleTextAttribute(hConsole, 0); break;
//                case CL_PIEDRA:  SetConsoleTextAttribute(hConsole, 7); break;
//                case CL_PASTO:   SetConsoleTextAttribute(hConsole, 2); break;
//                case CL_CAMINO:  SetConsoleTextAttribute(hConsole, 8); break;
//                case CL_ENEMIGO: SetConsoleTextAttribute(hConsole, 12); break;
//                case CL_PUERTA:  SetConsoleTextAttribute(hConsole, 14); break;
//                case CL_AGUA:    SetConsoleTextAttribute(hConsole, 9); break;
//                }
//
//                if (id == CL_CIELO) cout << " ";
//                else cout << (char)219;
//            }
//            cout << "\n";
//        }
//        SetConsoleTextAttribute(hConsole, 7);
//        cout << "\n\tEn los ultimos dias del Tahuantinsuyo, cuando el eco de los pasos aun recorria el Qhapaq Nan, una sombra";
//        cout << "\n\tdesconocida cruzo los Andes. Hombres venidos del otro lado del mar trajeron consigo no solo acero y";
//        cout << "\n\tambicion, sino el inicio de un cambio irreversible.";
//        cout << "\n\tEl Inca Atahualpa ha sido capturado.";
//        cout << "\n\tEl tiempo ya no fluye como antes. Los mensajes que antes viajaban con precision ahora cargan el peso del";
//        cout << "\n\tdestino de todo un imperio.";
//        cout << "\n\tEn medio del caos, un chasqui se alza.";
//        cout << "\n\tNo es el mas fuerte, ni el mas rapido… pero es el unico que puede llegar a tiempo.";
//        cout << "\n\tTu eres ese chasqui.";
//        cout << "\n\tRecorreras montanas, desafiaras caminos inciertos y tomaras decisiones que marcaran el rumbo de la";
//        cout << "\n\thistoria. Cada paso cuenta. Cada segundo importa.";
//        cout << "\n\tPorque esta vez, no solo llevas un mensaje . . .";
//        cout << "\n\tLlevas la ultima esperanza del Tahuantinsuyo.";
//        cout << "\n\t[ PRESIONE UNA TECLA PARA EMPEZAR LA AVENTURA ]";
//        int dummy = _getch();
//        (void)dummy;
//    }
//
//    void mostrarMenu() {
//        int opcion;
//        cout << "==============================" << endl;
//        cout << "      BIENVENIDO AL JUEGO     " << endl;
//        cout << "==============================" << endl;
//        cout << "1. Iniciar Juego" << endl;
//        cout << "2. Instrucciones" << endl;
//        cout << "3. Salir" << endl;
//        cout << "Seleccione una opción: "; cin >> opcion;
//
//        if (opcion == 1) {
//            cout << "Iniciando el juego..." << endl;
//            // Aquí puedes llamar a la función para iniciar el juego
//        }
//        else if (opcion == 2) {
//            cout << "Instrucciones del juego:" << endl;
//            cout << "1. Usa las flechas para moverte." << endl;
//            cout << "2. Evita a los enemigos." << endl;
//            cout << "Protege el quipu y responde las preguntas para avanzar." << endl;
//            cout << "3. Completa los niveles para ganar." << endl;
//        }
//        else if (opcion == 3) {
//            cout << "Saliendo del juego. ¡Hasta luego!" << endl;
//            exit(0);
//        }
//        else {
//            cout << "Opción no válida. Por favor, seleccione una opción del menú." << endl;
//        }
//    }

// =======================
// MENU.h - PARTE FUNCIONAL
// Pegar debajo de tu matriz mapaIntro[30][80]
// =======================

#include "Chasquis.h"
#include "Zorro.h"
#include "Puma.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"

void gotoxyMenu(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void colorMenu(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void limpiarMenu() {
	system("cls");
}

void pausaMenu() {
	colorMenu(7);
	cout << "\n\nPresione una tecla para continuar...";
	_getch();
}

void narrar(string texto, int velocidad = 18) {
	for (int i = 0; i < texto.length(); i++) {
		cout << texto[i];
		Sleep(velocidad);
	}
	cout << endl;
}

void pintarPresentacion() {
	system("mode con cols=120 lines=42");
	limpiarMenu();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 80; j++) {
			int id = mapaIntro[i][j];

			switch (id) {
			case CL_CIELO:   SetConsoleTextAttribute(hConsole, 0); break;
			case CL_PIEDRA:  SetConsoleTextAttribute(hConsole, 7); break;
			case CL_PASTO:   SetConsoleTextAttribute(hConsole, 2); break;
			case CL_CAMINO:  SetConsoleTextAttribute(hConsole, 8); break;
			case CL_ENEMIGO: SetConsoleTextAttribute(hConsole, 12); break;
			case CL_PUERTA:  SetConsoleTextAttribute(hConsole, 14); break;
			case CL_AGUA:    SetConsoleTextAttribute(hConsole, 9); break;
			}

			if (id == CL_CIELO) cout << " ";
			else cout << char(219);
		}
		cout << endl;
	}

	SetConsoleTextAttribute(hConsole, 7);

	cout << "\n\tEn los ultimos dias del Tahuantinsuyo, cuando el eco de los pasos aun recorria el Qhapaq Nan, una sombra";
	cout << "\n\tdesconocida cruzo los Andes. Hombres venidos del otro lado del mar trajeron consigo no solo acero y";
	cout << "\n\tambicion, sino el inicio de un cambio irreversible.";
	cout << "\n\tEl Inca Atahualpa ha sido capturado.";
	cout << "\n\tEl tiempo ya no fluye como antes. Los mensajes que antes viajaban con precision ahora cargan el peso del";
	cout << "\n\tdestino de todo un imperio.";
	cout << "\n\tEn medio del caos, un chasqui se alza.";
	cout << "\n\tNo es el mas fuerte, ni el mas rapido... pero es el unico que puede llegar a tiempo.";
	cout << "\n\tTu eres ese chasqui.";
	cout << "\n\tRecorreras montanas, desafiaras caminos inciertos y tomaras decisiones que marcaran el rumbo de la";
	cout << "\n\thistoria. Cada paso cuenta. Cada segundo importa.";
	cout << "\n\tPorque esta vez, no solo llevas un mensaje . . .";
	cout << "\n\tLlevas la ultima esperanza del Tahuantinsuyo.";
	cout << "\n\t[ PRESIONE UNA TECLA PARA EMPEZAR LA AVENTURA ]";

	_getch();
}

bool aceptarMision() {
	int opcion;

	limpiarMenu();

	colorMenu(14);
	cout << "==========================================" << endl;
	cout << "          MISION DEL TAHUANTINSUYO        " << endl;
	cout << "==========================================" << endl;

	colorMenu(7);
	narrar("\nUn amauta se acerca lentamente con un quipu sagrado.");
	narrar("El mensaje debe cruzar los caminos antes de que el tiempo se agote.");
	narrar("\nEstas dispuesto a aceptar la mision?");

	cout << "\n1. Si, acepto la mision";
	cout << "\n2. No, aun no estoy listo";
	cout << "\n\nRespuesta: ";
	cin >> opcion;

	if (opcion == 1) return true;
	return false;
}

void historiaContextual() {
	limpiarMenu();
	system("mode con cols=125 lines=42");

	colorMenu(7);

	narrar("El destino ha cambiado.");
	narrar("El Inca ha sido capturado y el equilibrio del Tahuantinsuyo pende de un hilo. Los caminos que antes llevaban");
	narrar("vida, ahora llevan urgencia.");
	narrar("Has sido elegido.");
	narrar("No por casualidad... sino porque eres uno de los pocos capaces de resistir la altura, el cansancio y el peso");
	narrar("de lo que esta por venir. Eres un chasqui. Y hoy, tu mision es mas importante que nunca.");
	narrar("");
	narrar("Antes de que todo cambiara, el imperio florecia.");
	narrar("Te encuentras en Antisuyo, la region oriental del Tahuantinsuyo, donde las montanas se funden con la selva");
	narrar("y la vida brota con fuerza. Cerca de las altas cumbres y caminos que conectan con lo que hoy conocemos");
	narrar("como Machu Picchu, esta tierra era rica en alimentos, saberes y energia.");
	narrar("Aqui, los chasquis corrian libres.");
	narrar("Aqui, los mensajes llegaban a tiempo.");
	narrar("Aqui, el imperio era uno solo.");
	narrar("");
	narrar("Pero ahora . . . todo es distinto.");
	narrar("Hombres desconocidos han llegado desde tierras lejanas. No respetan nuestras costumbres. No entienden");
	narrar("nuestros caminos.");
	narrar("Han capturado al Inca.");
	narrar("Y exigen un rescate imposible.");
	narrar("Oro. Plata. Riquezas de todos los suyos.");
	narrar("");
	narrar("Se necesita ayuda.");
	narrar("Y sabes exactamente a donde ir.");
	narrar("Si logras llevar el mensaje al lider del siguiente suyo, quizas aun haya esperanza. Quizas aun podamos reunir");
	narrar("lo necesario... quizas aun podamos salvar algo de lo que fuimos.");
	narrar("Pero el camino no sera facil.");
	narrar("Montanas traicioneras, rutas inciertas y decisiones que pondran a prueba tu juicio.");
	narrar("");
	narrar("Este no es solo un viaje.");
	narrar("Es una promesa.");
	narrar("Una ultima oportunidad.");
	narrar("[PRESIONE UNA TECLA PARA CONTINUAR]", 12);

	_getch();
}

void mostrarObjetivoComandosPersonajes() {
	limpiarMenu();
	system("mode con cols=120 lines=38");

	Chasquis chasqui("Chasqui", "Mensajero del imperio", true);
	Zorro zorro("Zorro", "Aliado sabio", "Preguntas", true);
	Puma puma("Puma", "Enemigo peligroso", true);

	colorMenu(11);
	gotoxyMenu(0, 0);
	cout << "================ OBJETIVO ================";

	colorMenu(7);
	gotoxyMenu(0, 2); cout << "Debes llevar el mensaje antes de que el tiempo llegue a cero.";
	gotoxyMenu(0, 3); cout << "El destino del Inca depende de tu velocidad y tus decisiones.";
	gotoxyMenu(0, 4); cout << "Si respondes correctamente, podras avanzar.";
	gotoxyMenu(0, 5); cout << "Si tomas el atajo, deberas evitar al puma.";

	colorMenu(10);
	gotoxyMenu(0, 8);
	cout << "================ COMANDOS ================";

	colorMenu(7);
	gotoxyMenu(0, 10); cout << "W = Subir";
	gotoxyMenu(0, 11); cout << "S = Bajar";
	gotoxyMenu(0, 12); cout << "A = Izquierda";
	gotoxyMenu(0, 13); cout << "D = Derecha";

	colorMenu(14);
	gotoxyMenu(0, 17);
	cout << "=========== CHASQUI ===========";
	colorMenu(7);
	gotoxyMenu(0, 18);
	cout << "Tu personaje principal.";
	chasqui.ubicar(5, 20);
	chasqui.dibujar_chasqui1();

	colorMenu(13);
	gotoxyMenu(35, 17);
	cout << "=========== ZORRO ===========";
	colorMenu(7);
	gotoxyMenu(35, 18);
	cout << "Aliado sabio del camino.";
	zorro.ubicar(35, 20);
	zorro.dibujar_zorro();

	colorMenu(12);
	gotoxyMenu(75, 17);
	cout << "=========== PUMA ===========";
	colorMenu(7);
	gotoxyMenu(75, 18);
	cout << "Enemigo del atajo.";
	puma.ubicar(75, 20);
	puma.dibujar_puma();

	gotoxyMenu(0, 33);
	pausaMenu();
}

int seleccionarChasqui() {
	int opcion;

	limpiarMenu();
	system("mode con cols=100 lines=25");

	Chasquis chasqui1("Inti", "Equilibrado", true);
	Chasquis chasqui2("Rumi", "Valiente", true);
	Chasquis chasqui3("Killa", "Agil", true);

	colorMenu(14);
	gotoxyMenu(0, 0);
	cout << "=========== SELECCIONA TU CHASQUI ===========";

	colorMenu(7);

	gotoxyMenu(5, 3);
	cout << "1. Chasqui Inti";
	chasqui1.ubicar(10, 6);
	chasqui1.dibujar_chasqui1();

	gotoxyMenu(35, 3);
	cout << "2. Chasqui Rumi";
	chasqui2.ubicar(40, 6);
	chasqui2.dibujar_chasqui2();

	gotoxyMenu(65, 3);
	cout << "3. Chasqui Killa";
	chasqui3.ubicar(70, 6);
	chasqui3.dibujar_chasqui3();

	gotoxyMenu(0, 13);
	cout << "Seleccione una opcion: ";
	cin >> opcion;

	if (opcion < 1 || opcion > 3) opcion = 1;

	return opcion;
}

void dialogoAntesNivel(int chasquiElegido) {
	limpiarMenu();
	system("mode con cols=110 lines=32");

	colorMenu(12);
	gotoxyMenu(0, 0);
	cout << "ESPANOL";
	gotoxyMenu(0, 2); cout << "  [#]  ";
	gotoxyMenu(0, 3); cout << " /|_|\\ ";
	gotoxyMenu(0, 4); cout << " /   \\ ";

	colorMenu(7);
	gotoxyMenu(12, 2); narrar("Espanol: Escucha, mensajero.");
	gotoxyMenu(12, 3); narrar("Espanol: Tu Inca no tiene mucho tiempo.");
	gotoxyMenu(12, 4); narrar("Espanol: Si no llevas ese mensaje en el tiempo establecido...");
	gotoxyMenu(12, 5); narrar("Espanol: Atahualpa sera ejecutado.");

	pausaMenu();

	limpiarMenu();

	colorMenu(14);
	gotoxyMenu(0, 0);
	cout << "INCA ATAHUALPA";
	gotoxyMenu(0, 2); cout << " \\|||/ ";
	gotoxyMenu(0, 3); cout << " (o_o) ";
	gotoxyMenu(0, 4); cout << " /|_|\\ ";

	colorMenu(7);
	gotoxyMenu(15, 2); narrar("Atahualpa: Chasqui, no llevas solo un mensaje.");
	gotoxyMenu(15, 3); narrar("Atahualpa: Llevas la esperanza de nuestro pueblo.");
	gotoxyMenu(15, 4); narrar("Atahualpa: Corre por el Qhapaq Nan y no mires atras.");

	pausaMenu();

	limpiarMenu();

	Chasquis chasqui("Chasqui elegido", "Mensajero", true);

	colorMenu(10);
	gotoxyMenu(0, 0);
	cout << "CHASQUI ELEGIDO";

	chasqui.ubicar(3, 3);
	chasqui.dibujar_chasqui1();

	gotoxyMenu(0, 8);
	colorMenu(7);

	if (chasquiElegido == 1) {
		narrar("Chasqui Inti: No fallare. Mi camino sera firme.");
	}
	else if (chasquiElegido == 2) {
		narrar("Chasqui Rumi: Aunque el peligro me espere, seguire adelante.");
	}
	else {
		narrar("Chasqui Killa: Llegare antes de que el sol caiga.");
	}

	narrar("\nLa mision comienza ahora...");
	pausaMenu();
}

void menuPrincipal() {
	int opcion;
	bool salir = false;

	while (salir == false) {
		limpiarMenu();
		system("mode con cols=100 lines=30");

		colorMenu(14);
		cout << "==========================================" << endl;
		cout << "        EL ULTIMO CHASQUI DEL INCA        " << endl;
		cout << "==========================================" << endl;

		colorMenu(7);
		cout << "\n1. Iniciar mision";
		cout << "\n2. Ver objetivo, comandos y personajes";
		cout << "\n3. Salir";
		cout << "\n\nSeleccione una opcion: ";
		cin >> opcion;

		if (opcion == 1) {
			int chasquiElegido = seleccionarChasqui();
			dialogoAntesNivel(chasquiElegido);

			Nivel1 nivel1;
			bool ganoNivel1 = nivel1.iniciar();

			if (ganoNivel1 == true) {
				limpiarMenu();
				colorMenu(10);
				narrar("Has superado el primer tramo del Qhapaq Nan.");
				narrar("Ahora la mision continua: un nuevo camino espera al chasqui.");
				pausaMenu();

				Nivel2 nivel2;
				bool ganoNivel2 = nivel2.iniciar();

				if (ganoNivel2 == true) {
					limpiarMenu();
					colorMenu(10);
					narrar("Has superado el segundo tramo del viaje.");
					narrar("La ruta final te conduce hacia la plaza de Cajamarca.");
					pausaMenu();

					Nivel3 nivel3;
					nivel3.iniciar();
				}
			}

			pausaMenu();
		}
		else if (opcion == 2) {
			mostrarObjetivoComandosPersonajes();
		}
		else if (opcion == 3) {
			salir = true;
		}
		else {
			cout << "\nOpcion no valida.";
			pausaMenu();
		}
	}
}

void iniciarMenu() {
	pintarPresentacion();

	if (aceptarMision() == true) {
		historiaContextual();
		mostrarObjetivoComandosPersonajes();
		menuPrincipal();
	}
	else {
		limpiarMenu();
		narrar("El chasqui aun no esta listo para partir...");
		pausaMenu();
	}
}