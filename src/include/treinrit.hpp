#pragma once
#include "Stap.hpp"

class Treinrit : public Stap {
private:
    int kosten;

public:
    Treinrit(int kosten);
    int getKosten();
};
