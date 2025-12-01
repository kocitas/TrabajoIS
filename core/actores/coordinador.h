#ifndef COORDINADOR_H
#define COORDINADOR_H

#include "usuario.h"

class Coordinador : public Usuario {
public:
    // Constructor
    Coordinador(string dni, string emailUCO, string password_hash);
    ~Coordinador();

    // CU6: Asignación automática de tutores
    void asignarTutoresAutomaticamente();
};

#endif // COORDINADOR_H
