#pragma once
#include "stap.hpp"

class Vlucht : public Stap {
private:
    int kosten;
public:
    Vlucht(int kosten);
    int getKosten() override;
};
