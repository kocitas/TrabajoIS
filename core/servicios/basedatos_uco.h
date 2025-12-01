#ifndef BASEDATOS_UCO_H
#define BASEDATOS_UCO_H

#include <string>
#include <sqlite3.h>
#include "../documentos/solicitud_ayuda.h"
#include "../documentos/notificacion.h"

using namespace std;

class BaseDatosUCO {
private:
    static BaseDatosUCO* instance;
    sqlite3* db;
    string dbPath;

    // Constructor privado (Singleton)
    BaseDatosUCO();

public:
    // Singleton
    static BaseDatosUCO* getInstance();
    ~BaseDatosUCO();

    // Métodos de conexión
    bool conectar();
    void desconectar();

    // CU1: Validar credenciales
    bool validarCredenciales(string email, string password);

    // CU6: Registrar asignación
    bool registrarAsignacion(string dniAlumno, string dniTutor);

    // CU8: Guardar solicitud de ayuda
    bool guardarSolicitud(SolicitudAyuda solicitud);

    // H8: Guardar notificación
    bool guardarNotificacion(Notificacion noti);
};

#endif // BASEDATOS_UCO_H
