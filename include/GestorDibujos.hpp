#pragma once
#include <vector>
#include "Dibujo.hpp"

class GestorDibujos {
public:
    std::vector<Dibujo> dibujos;

    void Agregar(const Dibujo& d) {
        dibujos.push_back(d);
    }

    void DibujarTodos(ftxui::Screen& screen) const {
        for (const auto& d : dibujos) {
            d.Dibujar(screen);
        }
    }
};

