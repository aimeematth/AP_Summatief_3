#pragma once
#include "stap.hpp"

class Treinrit : public Stap {
private:
    int kosten;
public:
    Treinrit(int kosten);
    int getKosten() override;
};
