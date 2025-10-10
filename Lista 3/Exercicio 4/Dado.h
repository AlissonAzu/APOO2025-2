#pragma once

class Dado {
private:
    int numeroDeFaces;

public:
    Dado();
    Dado(int faces);

    void setFaces(int faces);
    int getFaces() const;

    int Rolar();
};