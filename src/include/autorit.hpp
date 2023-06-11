#pragma once
#include "stap.hpp"

class Auto : public Stap {
private:
    int kosten;

public:
    Auto(int kosten);
    int getKosten() override;
};