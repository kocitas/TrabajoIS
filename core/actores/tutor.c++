#include "tutor.h"
#include "../servicios/basedatos_uco.h"
#include "../documentos/notificacion.h"

Tutor::Tutor(string dni, string emailUCO, string password_hash)
    : Usuario(dni, emailUCO, password_hash, "Tutor") {
}

Tutor::~Tutor() {
}

// CU3: Comunicación (Responder mensaje)
void Tutor::responderMensaje(int idSolicitud, string respuesta) {
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    
    // Aquí se podría actualizar el estado de la solicitud
    // y crear una notificación para el alumno
    
    // Crear notificación para el alumno
    // (En una implementación real, obtendríamos el DNI del alumno de la solicitud)
    Notificacion noti(0, "", "Respuesta del tutor", respuesta);
    bd->guardarNotificacion(noti);
}
