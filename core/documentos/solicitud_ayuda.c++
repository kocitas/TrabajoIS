#include "solicitud_ayuda.h"

SolicitudAyuda::SolicitudAyuda(int idSolicitud, string dni_alumno, string dni_tutor, 
                               string descripcion, string estado) {
    this->idSolicitud = idSolicitud;
    this->dni_alumno = dni_alumno;
    this->dni_tutor = dni_tutor;
    this->descripcion = descripcion;
    this->estado = estado;
}

SolicitudAyuda::~SolicitudAyuda() {
}

// Getters
int SolicitudAyuda::getIdSolicitud() const { return idSolicitud; }
string SolicitudAyuda::getDniAlumno() const { return dni_alumno; }
string SolicitudAyuda::getDniTutor() const { return dni_tutor; }
string SolicitudAyuda::getDescripcion() const { return descripcion; }
string SolicitudAyuda::getEstado() const { return estado; }

// Setters
void SolicitudAyuda::setIdSolicitud(int id) { this->idSolicitud = id; }
void SolicitudAyuda::setDniAlumno(string dni) { this->dni_alumno = dni; }
void SolicitudAyuda::setDniTutor(string dni) { this->dni_tutor = dni; }
void SolicitudAyuda::setDescripcion(string desc) { this->descripcion = desc; }
void SolicitudAyuda::setEstado(string estado) { this->estado = estado; }
