#pragma once

class Stap {
public:
    virtual int getKosten() = 0;
};

class MijnStap : public Stap {
public:
    int getKosten() override {
        // Voeg hier je eigen implementatie toe
        return 42; // Bijvoorbeeld: retourneer een vaste waarde
    }
};
