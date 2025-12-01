#ifndef TUTOR_H
#define TUTOR_H

#include "usuario.h"

class Tutor : public Usuario {
public:
    // Constructor
    Tutor(string dni, string emailUCO, string password_hash);
    ~Tutor();

    // CU3: Comunicación (Responder mensaje)
    void responderMensaje(int idSolicitud, string respuesta);
};

#endif // TUTOR_H
