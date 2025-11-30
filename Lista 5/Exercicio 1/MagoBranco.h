#ifndef MAGOBRANCO_H
#define MAGOBRANCO_H

#include "Mago.h"

using namespace std;

class MagoBranco : public Mago {
public:
    MagoBranco(string n, int p, int i, string e);
    void lancarCura() const;
};

#endif