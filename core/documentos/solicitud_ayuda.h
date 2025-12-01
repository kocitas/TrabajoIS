#ifndef SOLICITUD_AYUDA_H
#define SOLICITUD_AYUDA_H

#include <string>
using namespace std;

class SolicitudAyuda {
private:
    int idSolicitud;
    string dni_alumno;
    string dni_tutor;
    string descripcion;
    string estado;

public:
    // Constructor
    SolicitudAyuda(int idSolicitud, string dni_alumno, string dni_tutor, 
                   string descripcion, string estado);
    ~SolicitudAyuda();

    // Getters
    int getIdSolicitud() const;
    string getDniAlumno() const;
    string getDniTutor() const;
    string getDescripcion() const;
    string getEstado() const;

    // Setters
    void setIdSolicitud(int id);
    void setDniAlumno(string dni);
    void setDniTutor(string dni);
    void setDescripcion(string desc);
    void setEstado(string estado);
};

#endif // SOLICITUD_AYUDA_H
