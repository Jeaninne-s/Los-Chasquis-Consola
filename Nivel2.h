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

class PersonajeN2 {
protected:
    string nombre;
    int vida;
    int x, y, dx, dy;
    int danio;
    int rangoAtaque;
public:
    PersonajeN2(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque) {
        nombre = pnombre;
        vida = pvida;
        x = px;
        y = py;
        dx = pdx;
        dy = pdy;
        danio = pdanio;
        rangoAtaque = pRangoAtaque;
    }
    virtual ~PersonajeN2() {}
    void setPosicion(int px, int py) { x = px; y = py; }
    int getx() { return x; }
    int gety() { return y; }
};

class ChasquiN2 : public PersonajeN2 {
public:
    ChasquiN2(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque)
        : PersonajeN2(pnombre, pvida, px, py, pdx, pdy, pdanio, pRangoAtaque) {}

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

        if (x < 1) x = 1;
        if (x > 114) x = 114;
        if (y < 2) y = 2;
        if (y > 25) y = 25;
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << " o/ ";
        Console::SetCursorPosition(x, y + 1); cout << " /| ";
        Console::SetCursorPosition(x, y + 2); cout << " / \\";
    }
};

class EspanolN2 : public PersonajeN2 {
public:
    EspanolN2(string pnombre, int pvida, int px, int py, int pdx, int pdy, int pdanio, int pRangoAtaque)
        : PersonajeN2(pnombre, pvida, px, py, pdx, pdy, pdanio, pRangoAtaque) {}

    void borrar() {
        Console::SetCursorPosition(x, y);     cout << "    ";
        Console::SetCursorPosition(x, y + 1); cout << "    ";
        Console::SetCursorPosition(x, y + 2); cout << "    ";
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << "\\O/";
        Console::SetCursorPosition(x, y + 1); cout << " | ";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }

    void mover() {
        int direccion = rand() % 4;
        if (direccion == 0) x++;
        if (direccion == 1) x--;
        if (direccion == 2) y++;
        if (direccion == 3) y--;

        if (x < 1) x = 1;
        if (x > 114) x = 114;
        if (y < 2) y = 2;
        if (y > 25) y = 25;
    }
};

class PescadoN2 {
private:
    int x, y;
    bool activo;
public:
    PescadoN2() {
        x = rand() % 100 + 5;
        y = rand() % 20 + 5;
        activo = true;
    }
    void dibujar() {
        if (activo) {
            Console::SetCursorPosition(x, y);
            cout << "<><";
        }
    }
    void borrar() {
        Console::SetCursorPosition(x, y);
        cout << "   ";
    }
    bool estaActivo() { return activo; }
    void recoger() { activo = false; borrar(); }
    int getx() { return x; }
    int gety() { return y; }
};

class CronometroN2 {
private:
    int tiempo;
public:
    CronometroN2(int _tiempo) { tiempo = _tiempo; }
    void disminuirTiempo() { tiempo--; }
    void mostrarTiempo() {
        Console::SetCursorPosition(0, 0);
        cout << "Tiempo restante: " << tiempo << "   ";
    }
    bool TiempoAcabado() { return tiempo <= 0; }
};

class CaminoN2 {
private:
    int x;
    int y;
public:
    CaminoN2() { x = 5; y = 2; }
    CaminoN2(int px, int py) { x = px; y = py; }

    void cielo() {
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::ForegroundColor = ConsoleColor::Blue;
        for (int i = 0; i < 16; i++) {
            Console::SetCursorPosition(0, i);
            for (int j = 0; j < 118; j++) cout << " ";
        }
        Console::ResetColor();
    }

    void montanas() {
        Console::ForegroundColor = ConsoleColor::DarkYellow;
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(x, y - 1); cout << "             /\\";
        Console::SetCursorPosition(x, y);     cout << "           // \\\\";
        Console::SetCursorPosition(x, y + 1); cout << "          ///  \\\\";
        Console::SetCursorPosition(x, y + 2); cout << "         ///    \\\\";
        Console::SetCursorPosition(x, y + 3); cout << "        ///      \\\\";
        Console::SetCursorPosition(x, y + 4); cout << "       ///        \\\\";
        Console::SetCursorPosition(x, y + 5); cout << "      ///          \\\\";
        Console::SetCursorPosition(x, y + 6); cout << "     ///            \\\\";
        Console::SetCursorPosition(x, y + 7); cout << "    ///              \\\\";
        Console::SetCursorPosition(x, y + 8); cout << "   ///                \\\\";
        Console::SetCursorPosition(x, y + 9); cout << "  ///                  \\\\";
        Console::ResetColor();
    }

    void rios() {
        char bloque = 219;
        for (int i = -3; i < 10; i++) {
            Console::SetCursorPosition(x, y + i);
            for (int j = 0; j < 118; j++) {
                Console::ForegroundColor = ConsoleColor::Cyan;
                cout << bloque;
            }
        }
        Console::ResetColor();
    }

    void cam_seguro() {
        char bloque = 219;
        Console::ForegroundColor = ConsoleColor::Gray;
        for (int i = 1; i <= 2; i++) {
            Console::SetCursorPosition(x, y + i);
            for (int j = 0; j < 118; j++) cout << bloque;
        }
        Console::ResetColor();
    }

    void generarRuta1() {
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::ForegroundColor = ConsoleColor::Gray;
        for (int i = 8; i <= 10; i++) {
            Console::SetCursorPosition(0, i);
            for (int j = 0; j < 118; j++) cout << char(219);
        }
        Console::ResetColor();
    }

    void generarRuta2() {
        Console::BackgroundColor = ConsoleColor::DarkYellow;
        Console::ForegroundColor = ConsoleColor::Gray;
        for (int i = 8; i <= 10; i++) {
            Console::SetCursorPosition(0, i);
            for (int j = 0; j < 118; j++) cout << char(219);
        }
        Console::ResetColor();
    }

    void tambo() {
        Console::ForegroundColor = ConsoleColor::DarkRed;
        Console::SetCursorPosition(x, y);     cout << " /\\ ";
        Console::SetCursorPosition(x, y + 1); cout << "/__\\";
        Console::SetCursorPosition(x, y + 2); cout << "|__|";
        Console::ResetColor();
    }
};

class AyudanteN2 {
private:
    int x;
    int y;
public:
    AyudanteN2() { x = 20; y = 13; }
    int getx() { return x; }
    int gety() { return y; }

    void dibujar() {
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(x, y);     cout << " o  ";
        Console::SetCursorPosition(x, y + 1); cout << "/|\\~";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
        Console::ResetColor();
    }

    int OfrecerAyuda() {
        int op;
        Console::BackgroundColor = ConsoleColor::Blue;
        Console::ForegroundColor = ConsoleColor::Black;
        dibujar();
        Console::SetCursorPosition(0, 0);
        cout << "Rumi te pide ayuda para conseguir pescado. Aceptas?" << endl;
        Console::SetCursorPosition(0, 1); cout << "1. Aceptar" << endl;
        Console::SetCursorPosition(0, 2); cout << "2. Rechazar" << endl;
        Console::SetCursorPosition(0, 3); cout << "Elegir una opcion: ";
        cin >> op;
        return op;
    }
};

class Nivel2 {
private:
    ChasquiN2* ObjChasqui;
    PescadoN2* peces[4];
    int pecesRecogidos;
    bool misionPesca;
    AyudanteN2* ObjAyudante;
    CaminoN2* ObjCamino;
    CaminoN2* ObjCamino2;
    CaminoN2* ObjCamino3;
    CaminoN2* ObjMontana2;
    CaminoN2* ObjMontana3;
    EspanolN2* enemigos[3];
    bool misionEspanoles;
    CaminoN2* ObjTambo;
    CronometroN2* ObjCronometro;

public:
    Nivel2() {
        ObjChasqui = new ChasquiN2("Pablito", 3, 5, 13, 1, 1, 1, 1);
        ObjAyudante = new AyudanteN2();
        ObjCamino = new CaminoN2();
        ObjCamino2 = new CaminoN2(1, 20);
        ObjCamino3 = new CaminoN2(1, 14);
        ObjMontana2 = new CaminoN2(31, 2);
        ObjMontana3 = new CaminoN2(61, 2);
        ObjTambo = new CaminoN2(111, 15);
        pecesRecogidos = 0;
        misionPesca = false;
        misionEspanoles = false;
        for (int i = 0; i < 4; i++) peces[i] = nullptr;
        for (int i = 0; i < 3; i++) enemigos[i] = nullptr;
        ObjCronometro = new CronometroN2(60);
        srand(time(NULL));
    }

    ~Nivel2() {
        delete ObjChasqui;
        delete ObjAyudante;
        delete ObjCamino;
        delete ObjCamino2;
        delete ObjCamino3;
        delete ObjMontana2;
        delete ObjMontana3;
        delete ObjTambo;
        delete ObjCronometro;
        for (int i = 0; i < 4; i++) if (peces[i] != nullptr) delete peces[i];
        for (int i = 0; i < 3; i++) if (enemigos[i] != nullptr) delete enemigos[i];
    }

    bool iniciar() {
        system("cls");
        system("mode con cols=120 lines=32");
        Console::CursorVisible = false;

        bool Ofrecer_ayuda = false;
        bool ayudanteActivo = true;
        bool Cam_puente = true;
        bool ruta1Activa = false;
        bool ruta2Activa = false;
        bool chasqui_inicio = true;
        bool Tambo = false;
        int contadorFrames = 0;
        int prevX, prevY;

        ObjCamino3->cam_seguro();
        ObjCamino->cielo();
        ObjCamino->montanas();
        ObjMontana2->montanas();
        ObjMontana3->montanas();
        ObjCamino2->rios();

        while (true) {
            prevX = ObjChasqui->getx();
            prevY = ObjChasqui->gety();

            ObjChasqui->borrar();
            ObjChasqui->mover();

            if (misionEspanoles) {
                for (int i = 0; i < 3; i++) {
                    if (enemigos[i] != nullptr) {
                        enemigos[i]->borrar();
                        enemigos[i]->mover();
                    }
                }
            }

            if (ruta1Activa) ObjCamino->generarRuta1();
            if (ruta2Activa) ObjCamino->generarRuta2();
            if (ayudanteActivo) ObjAyudante->dibujar();

            if (Cam_puente) {
                if (ObjChasqui->getx() < 2 || ObjChasqui->gety() != 13) {
                    ObjChasqui->setPosicion(prevX, prevY);
                }
            }

            if (misionEspanoles) {
                for (int i = 0; i < 3; i++) {
                    if (enemigos[i] != nullptr) enemigos[i]->dibujar();
                }
            }

            if (chasqui_inicio) {
                Console::BackgroundColor = ConsoleColor::Blue;
                Console::ForegroundColor = ConsoleColor::Black;
            }

            ObjChasqui->dibujar();

            if (misionPesca) {
                for (int i = 0; i < 4; i++) {
                    if (peces[i] != nullptr && peces[i]->estaActivo()) peces[i]->dibujar();
                }
            }

            if (misionPesca) {
                for (int i = 0; i < 4; i++) {
                    if (peces[i] != nullptr && peces[i]->estaActivo()) {
                        if (abs(ObjChasqui->getx() - peces[i]->getx()) <= 2 &&
                            abs(ObjChasqui->gety() - peces[i]->gety()) <= 2) {
                            peces[i]->recoger();
                            pecesRecogidos++;
                        }
                    }
                }
            }

            if (misionPesca && pecesRecogidos == 4) {
                system("cls");
                Console::SetCursorPosition(38, 10); cout << "RECOGISTE TODOS LOS PECES";
                Console::SetCursorPosition(35, 12); cout << "PASAS AL SIGUIENTE NIVEL";
                Sleep(3000);
                return true;
            }

            if (Tambo) ObjTambo->tambo();

            if (misionEspanoles) {
                if (ObjChasqui->getx() >= 111 && ObjChasqui->getx() <= 116 &&
                    ObjChasqui->gety() >= 15 && ObjChasqui->gety() <= 17) {
                    system("cls");
                    Console::SetCursorPosition(40, 10); cout << "SOBREVIVISTE";
                    Console::SetCursorPosition(32, 12); cout << "PASAS AL SIGUIENTE NIVEL";
                    Sleep(3000);
                    return true;
                }
            }

            if (!Ofrecer_ayuda && ObjChasqui->getx() == ObjAyudante->getx() && ObjChasqui->gety() == ObjAyudante->gety()) {
                system("cls");
                ObjCamino3->cam_seguro();
                Ofrecer_ayuda = true;
                ayudanteActivo = false;
                ObjCamino2->rios();
                int op = ObjAyudante->OfrecerAyuda();

                if (op == 1) {
                    system("cls");
                    Cam_puente = false;
                    chasqui_inicio = false;
                    ruta1Activa = true;
                    misionPesca = true;
                    for (int i = 0; i < 4; i++) peces[i] = new PescadoN2();
                    Console::BackgroundColor = ConsoleColor::Blue;
                    Console::ForegroundColor = ConsoleColor::Black;
                    ObjChasqui->setPosicion(5, 5);
                }
                else {
                    system("cls");
                    Cam_puente = false;
                    ruta2Activa = true;
                    chasqui_inicio = false;
                    Tambo = true;
                    misionEspanoles = true;
                    ObjTambo->tambo();
                    for (int i = 0; i < 3; i++) {
                        enemigos[i] = new EspanolN2("Espanol", 3, rand() % 100 + 5, rand() % 20 + 5, 1, 1, 1, 1);
                    }
                    Console::BackgroundColor = ConsoleColor::DarkYellow;
                    Console::ForegroundColor = ConsoleColor::Black;
                    ObjChasqui->setPosicion(5, 5);
                }
            }

            Sleep(100);
            contadorFrames++;

            if (contadorFrames == 10) {
                ObjCronometro->disminuirTiempo();
                contadorFrames = 0;
            }

            ObjCronometro->mostrarTiempo();

            if (ObjCronometro->TiempoAcabado()) {
                system("cls");
                cout << "SE ACABO EL TIEMPO";
                Sleep(2000);
                return false;
            }
        }
    }
};
