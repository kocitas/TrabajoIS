#include "coordinador.h"
#include "../servicios/basedatos_uco.h"
#include "../documentos/notificacion.h"

Coordinador::Coordinador(string dni, string emailUCO, string password_hash)
    : Usuario(dni, emailUCO, password_hash, "Coordinador") {
}

Coordinador::~Coordinador() {
}

// CU6: Asignación automática de tutores
void Coordinador::asignarTutoresAutomaticamente() {
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    
    // Lógica de asignación automática
    // En una implementación real, esto obtendría alumnos sin tutor
    // y los asignaría a tutores con menor carga
    
    // Ejemplo: asignar alumno a tutor
    string dniAlumno = "66666666G";  // Alumno sin asignar
    string dniTutor = "22222222C";   // Tutor con menor carga
    
    if (bd->registrarAsignacion(dniAlumno, dniTutor)) {
        // Crear notificación para el alumno
        Notificacion noti(0, dniAlumno, "Asignación de tutor", 
                         "Has sido asignado a un tutor");
        bd->guardarNotificacion(noti);
    }
}
