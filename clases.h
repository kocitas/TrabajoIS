#ifndef CLASES_BASICAS_H
#define CLASES_BASICAS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>


class clases
{
protected:
    // Atributos protegidos (# en UML)
    std::string DNI;     
    std::string name;  
    std::string emailUCO; 
    
private:
    // Atributos privados (- en UML)
    std::string password; 
    std::string rol;
public:

    // Constructor básico para inicializar atributos esenciales
    Usuario(const std::string& dni, const std::string& nom, const std::string& mail, const std::string& r)
        : DNI(dni), name(nom), emailUCO(mail), rol(r) {
        // La contraseña se manejaría en un módulo de seguridad aparte.
    }
    
};





#endif // CU10_CLASES_BASICAS_H