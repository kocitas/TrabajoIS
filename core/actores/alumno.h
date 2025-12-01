#ifndef ALUMNO_H
#define ALUMNO_H

#include "usuario.h"
#include "../documentos/solicitud_ayuda.h"

class Alumno : public Usuario {
public:
    // Constructor
    Alumno(string dni, string emailUCO, string password_hash);
    ~Alumno();

    // CU8: Solicitud de Ayuda
    void solicitarTutoria(string descripcion);
};

#endif // ALUMNO_H
