#pragma once
#include "Stap.hpp"

class Vlucht : public Stap {
private:
    int kosten;

public:
    Vlucht(int kosten);
    int getKosten();
};
