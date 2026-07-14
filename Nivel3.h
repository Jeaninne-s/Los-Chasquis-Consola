#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace System;

class PersonajeN3 {
protected:
    string nombre;
    int vida;
    int x, y, dx, dy;
    int danio;
    int rangoAtaque;
public:
    PersonajeN3(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque) {
        nombre = pnombre;
        vida = pvida;
        x = px;
        y = py;
        dx = pdx;
        dy = pdy;
        danio = pdanio;
        rangoAtaque = pRangoAtaque;
    }
    virtual ~PersonajeN3() {}
    int getx() { return x; }
    int gety() { return y; }
    void setPosicion(int nuevoX, int nuevoY) { x = nuevoX; y = nuevoY; }
};

class ChasquiN3 : public PersonajeN3 {
public:
    ChasquiN3(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque)
        : PersonajeN3(pnombre, pvida, px, py, pdx, pdy, pdanio, pRangoAtaque) {}

    void borrar() {
        Console::SetCursorPosition(x, y);     cout << "    ";
        Console::SetCursorPosition(x, y + 1); cout << "    ";
        Console::SetCursorPosition(x, y + 2); cout << "    ";
    }

    void mover() {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'w' || tecla == 'W') y--;
            if (tecla == 'a' || tecla == 'A') x--;
            if (tecla == 's' || tecla == 'S') y++;
            if (tecla == 'd' || tecla == 'D') x++;
        }
        if (x < 3) x = 3;
        if (x > 109) x = 109;
        if (y < 3) y = 3;
        if (y > 24) y = 24;
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << " o/ ";
        Console::SetCursorPosition(x, y + 1); cout << " /| ";
        Console::SetCursorPosition(x, y + 2); cout << " / \\";
    }
};

class EspanolN3 : public PersonajeN3 {
public:
    EspanolN3(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque)
        : PersonajeN3(pnombre, pvida, px, py, pdx, pdy, pdanio, pRangoAtaque) {}

    void borrar() {
        Console::SetCursorPosition(x, y);     cout << "    ";
        Console::SetCursorPosition(x, y + 1); cout << "    ";
        Console::SetCursorPosition(x, y + 2); cout << "    ";
    }

    void mover() {
        int direccion = rand() % 4;
        if (direccion == 0) x++;
        if (direccion == 1) x--;
        if (direccion == 2) y++;
        if (direccion == 3) y--;

        if (x < 3) x = 3;
        if (x > 109) x = 109;
        if (y < 3) y = 3;
        if (y > 24) y = 24;
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << "\\O/";
        Console::SetCursorPosition(x, y + 1); cout << " | ";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
};

class CronometroN3 {
private:
    int tiempo;
public:
    CronometroN3(int _tiempo) { tiempo = _tiempo; }
    void disminuirTiempo() { tiempo--; }
    void mostrarTiempo() {
        Console::SetCursorPosition(0, 0);
        Console::ForegroundColor = ConsoleColor::White;
        cout << "Tiempo restante: " << tiempo << "   ";
        Console::ResetColor();
    }
    bool TiempoAcabado() { return tiempo <= 0; }
};

class Nivel3 {
private:
    ChasquiN3* ObjChasqui;
    EspanolN3* emboscada[12];
    CronometroN3* ObjCronometro;
    int plaza[28][115];

    void generarMatrizPlaza() {
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 115; j++) {
                if (i == 2 || i == 27 || j == 2 || j == 112) plaza[i][j] = 1;
                else if (i > 11 && i < 17 && j > 45 && j < 70) plaza[i][j] = 2;
                else if ((i == 5 || i == 24) && (j == 10 || j == 104)) plaza[i][j] = 3;
                else plaza[i][j] = 0;
            }
        }
        for (int j = 52; j < 62; j++) plaza[27][j] = 0;
    }

    void pintarPlaza() {
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 115; j++) {
                Console::SetCursorPosition(j, i);
                if (plaza[i][j] == 1) {
                    Console::ForegroundColor = ConsoleColor::DarkGray;
                    cout << char(219);
                }
                else if (plaza[i][j] == 2) {
                    Console::ForegroundColor = ConsoleColor::DarkRed;
                    cout << char(176);
                }
                else if (plaza[i][j] == 3) {
                    Console::ForegroundColor = ConsoleColor::Yellow;
                    cout << char(207);
                }
                else {
                    Console::ForegroundColor = ConsoleColor::DarkYellow;
                    cout << char(176);
                }
            }
        }
        Console::ResetColor();
    }

    void escribirLento(string texto, int velocidad, ConsoleColor color) {
        Console::ForegroundColor = color;
        for (int i = 0; i < texto.length(); i++) {
            cout << texto[i];
            Sleep(velocidad);
        }
        cout << endl;
        Console::ResetColor();
    }

public:
    Nivel3() {
        generarMatrizPlaza();
        ObjChasqui = new ChasquiN3("Chasqui", 3, 56, 24, 1, 1, 1, 1);
        for (int i = 0; i < 12; i++) {
            emboscada[i] = new EspanolN3("Conquistador", 3, rand() % 90 + 10, rand() % 20 + 4, 1, 1, 1, 1);
        }
        ObjCronometro = new CronometroN3(15);
    }

    ~Nivel3() {
        delete ObjChasqui;
        for (int i = 0; i < 12; i++) delete emboscada[i];
        delete ObjCronometro;
    }

    void introDramatica() {
        system("cls");
        system("mode con cols=120 lines=35");
        Console::SetCursorPosition(20, 10);
        escribirLento("16 de noviembre de 1532...", 70, ConsoleColor::DarkGray);
        Sleep(800);
        Console::SetCursorPosition(20, 12);
        escribirLento("Tus pulmones arden. Has corrido sin descanso desde la costa.", 35, ConsoleColor::White);
        Console::SetCursorPosition(20, 13);
        escribirLento("Finalmente, ves los muros de la gran plaza de Cajamarca.", 35, ConsoleColor::White);
        Sleep(1000);
        Console::SetCursorPosition(20, 15);
        escribirLento("Pero algo esta mal. No hay cantos, no hay celebracion.", 40, ConsoleColor::Gray);
        Sleep(900);
        Console::SetCursorPosition(20, 17);
        escribirLento("ES UNA EMBOSCADA. RESISTE HASTA ENCONTRAR UNA SALIDA.", 45, ConsoleColor::Red);
        Sleep(1800);
        system("cls");
    }

    void finalTragico() {
        system("cls");
        Sleep(700);
        Console::SetCursorPosition(15, 8);
        escribirLento("Los hombres de metal retroceden, pero no porque los hayas vencido...", 45, ConsoleColor::Gray);
        Sleep(1000);
        Console::SetCursorPosition(15, 10);
        escribirLento("Miras hacia el centro de la plaza. El gran usnu esta vacio.", 50, ConsoleColor::White);
        Sleep(1000);
        Console::SetCursorPosition(15, 12);
        escribirLento("A lo lejos, comprendes que el destino del Sapa Inca ya fue decidido.", 50, ConsoleColor::DarkYellow);
        Sleep(1200);
        Console::SetCursorPosition(15, 15);
        escribirLento("El mensaje que llevas en tus manos, el quipu que protegiste con valentia...", 45, ConsoleColor::White);
        Console::SetCursorPosition(15, 16);
        escribirLento("Ha llegado tarde.", 80, ConsoleColor::DarkRed);
        Sleep(1500);
        Console::SetCursorPosition(15, 19);
        escribirLento("Pese a tu esfuerzo cruzando la sierra y la costa,", 50, ConsoleColor::Gray);
        Console::SetCursorPosition(15, 20);
        escribirLento("la historia no siempre tiene un final feliz.", 60, ConsoleColor::Gray);
        Sleep(1500);
        Console::SetCursorPosition(35, 24);
        escribirLento("EL TAHUANTINSUYO HA CAIDO.", 100, ConsoleColor::Red);
        Sleep(2500);
        Console::ResetColor();
    }

    bool iniciar() {
        introDramatica();
        pintarPlaza();
        int contadorFrames = 0;

        while (true) {
            int prevX = ObjChasqui->getx();
            int prevY = ObjChasqui->gety();

            ObjChasqui->borrar();
            ObjChasqui->mover();

            if (plaza[ObjChasqui->gety()][ObjChasqui->getx()] == 1 ||
                plaza[ObjChasqui->gety()][ObjChasqui->getx()] == 2) {
                ObjChasqui->setPosicion(prevX, prevY);
            }

            for (int i = 0; i < 12; i++) {
                int ePrevX = emboscada[i]->getx();
                int ePrevY = emboscada[i]->gety();
                emboscada[i]->borrar();
                emboscada[i]->mover();

                if (plaza[emboscada[i]->gety()][emboscada[i]->getx()] == 1 ||
                    plaza[emboscada[i]->gety()][emboscada[i]->getx()] == 2) {
                    emboscada[i]->setPosicion(ePrevX, ePrevY);
                }

                emboscada[i]->dibujar();

                if (abs(ObjChasqui->getx() - emboscada[i]->getx()) <= 2 &&
                    abs(ObjChasqui->gety() - emboscada[i]->gety()) <= 2) {
                    system("cls");
                    Console::SetCursorPosition(30, 15);
                    escribirLento("TE ATRAPARON LOS CONQUISTADORES.", 45, ConsoleColor::Red);
                    Sleep(1800);
                    return false;
                }
            }

            ObjChasqui->dibujar();

            contadorFrames++;
            if (contadorFrames == 10) {
                ObjCronometro->disminuirTiempo();
                contadorFrames = 0;
            }

            ObjCronometro->mostrarTiempo();

            if (ObjCronometro->TiempoAcabado()) {
                finalTragico();
                return true;
            }

            Sleep(80);
        }
    }
};
