#include "usuario.h"
#include "../servicios/basedatos_uco.h"

Usuario::Usuario(string dni, string emailUCO, string password_hash, string rol) {
    this->dni = dni;
    this->emailUCO = emailUCO;
    this->password_hash = password_hash;
    this->rol = rol;
}

Usuario::~Usuario() {
}

// CU1: Autenticación
bool Usuario::iniciarSesion(string email, string password) {
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    return bd->validarCredenciales(email, password);
}

// Getters
string Usuario::getDNI() const { return dni; }
string Usuario::getEmailUCO() const { return emailUCO; }
string Usuario::getRol() const { return rol; }

// Setters
void Usuario::setDNI(string dni) { this->dni = dni; }
void Usuario::setEmailUCO(string emailUCO) { this->emailUCO = emailUCO; }
void Usuario::setPasswordHash(string password_hash) { this->password_hash = password_hash; }
void Usuario::setRol(string rol) { this->rol = rol; }
