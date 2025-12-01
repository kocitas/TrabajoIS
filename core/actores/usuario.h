#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string dni;
    string emailUCO;
    string password_hash;
    string rol;

public:
    // Constructor
    Usuario(string dni, string emailUCO, string password_hash, string rol);
    virtual ~Usuario();

    // CU1: Autenticación
    bool iniciarSesion(string email, string password);

    // Getters
    string getDNI() const;
    string getEmailUCO() const;
    string getRol() const;

    // Setters
    void setDNI(string dni);
    void setEmailUCO(string emailUCO);
    void setPasswordHash(string password_hash);
    void setRol(string rol);
};

#endif // USUARIO_H
