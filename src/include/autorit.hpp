#pragma once
#include "Stap.hpp"

class Auto : public Stap {
private:
    int kosten;

public:
    Auto(int kosten);
    int getKosten();
};
