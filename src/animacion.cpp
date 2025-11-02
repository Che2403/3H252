#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"
#include "Selva.hpp"

using namespace ftxui;

int main() {
    const int WIDTH = 120;
    const int HEIGHT = 40;
    Screen fondo = Screen::Create(Dimension::Fixed(WIDTH), Dimension::Fixed(HEIGHT));

    // ===== FIGURAS =====
    const std::vector<std::u32string> mono = {
        U"   w  c( . . )o",
        U"    \\__( - )",
        U"      /   \\",
        U"    _/____\\_"
    };

    const std::vector<std::u32string> tortuga = {
        U"    _____  ",
        U"  /       \\",
        U" |  (o_o)  |",
        U"  \\_______/",
        U"   /  |  \\ ",
        U"  (_/   \\_)"
    };

    const std::vector<std::u32string> elefante = {
        U"    /\\  ___  /\\",
        U"   // \\/   \\/ \\\\",
        U"  ((    O O    ))",
        U"   \\\\ /     \\ //",
        U"    \\/  | |  \\/",
        U"     |  | |  |",
        U"     |__|_|__|"
    };

    const std::vector<std::u32string> arbol = {
        U"   &&&   ",
        U"  &&&&&  ",
        U"   |||   "
    };

    
    for (int x = 5; x < WIDTH - 10; x += 30) {
        Dibujo(x, 2, arbol, Color::Green).Dibujar(fondo);
        Dibujo(x, HEIGHT - 6, arbol, Color::Green).Dibujar(fondo);
    }
    for (int y = 6; y < HEIGHT - 8; y += 10) {
        Dibujo(3, y, arbol, Color::Green).Dibujar(fondo);
        Dibujo(WIDTH - 12, y, arbol, Color::Green).Dibujar(fondo);
    }

    // ===== CREAR SELVA Y ANIMALES =====
    Selva selva(5, 5, 110, 35, Color::Green);
    selva.AgregarAnimal(Dibujo(15, 20, mono, Color::Yellow));       // Mono
    selva.AgregarAnimal(Dibujo(50, 25, elefante, Color::White));    // Elefante
    selva.AgregarAnimal(Dibujo(85, 30, tortuga, Color::GrayLight)); // Tortuga

    // ===== ANIMACIÓN =====
    for (int frame = 0; frame < 300; ++frame) {
        // Crear una copia del fondo base
        Screen frame_screen = fondo;

        // Movimiento solo en X (horizontal)
        selva.animales[0].x = 15 + (frame % 10);   // Mono
        selva.animales[1].x = 50 + (frame % 6);    // Elefante
        selva.animales[2].x = 85 - (frame % 8);    // Tortuga

        // Dibujar los animales sobre el fondo
        selva.Dibujar(frame_screen);

        // Mostrar frame
        std::cout << frame_screen.ToString()
                  << frame_screen.ResetPosition()
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    return 0;
}











