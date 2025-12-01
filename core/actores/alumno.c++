#include "alumno.h"
#include "../servicios/basedatos_uco.h"

Alumno::Alumno(string dni, string emailUCO, string password_hash)
    : Usuario(dni, emailUCO, password_hash, "Alumno") {
}

Alumno::~Alumno() {
}

// CU8: Solicitud de Ayuda
void Alumno::solicitarTutoria(string descripcion) {
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    
    // Crear solicitud de ayuda
    SolicitudAyuda solicitud(0, this->dni, "", descripcion, "Pendiente");
    
    // Guardar en base de datos
    bd->guardarSolicitud(solicitud);
}
