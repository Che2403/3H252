#pragma once
#include <vector>
#include "Dibujo.hpp"

class Selva {
public:
    int x, y, ancho, alto;
    ftxui::Color color;
    std::vector<Dibujo> animales;

    Selva(int x, int y, int ancho, int alto, ftxui::Color color)
        : x(x), y(y), ancho(ancho), alto(alto), color(color) {}

    void AgregarAnimal(const Dibujo& animal) {
        animales.push_back(animal);
    }

    void Dibujar(ftxui::Screen& screen) const {
        // Dibuja cada animal libremente
        for (const auto& a : animales)
            a.Dibujar(screen);
    }
};

