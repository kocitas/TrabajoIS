#include "notificacion.h"
#include <iostream>

Notificacion::Notificacion(int idNoti, string dni_destinatario, 
                           string titulo, string mensaje) {
    this->idNoti = idNoti;
    this->dni_destinatario = dni_destinatario;
    this->titulo = titulo;
    this->mensaje = mensaje;
}

Notificacion::~Notificacion() {
}

// H8: Enviar notificación
void Notificacion::enviar() {
    // En una implementación real, esto enviaría un email o notificación push
    cout << "Enviando notificación a " << dni_destinatario << endl;
    cout << "Título: " << titulo << endl;
    cout << "Mensaje: " << mensaje << endl;
}

// Getters
int Notificacion::getIdNoti() const { return idNoti; }
string Notificacion::getDniDestinatario() const { return dni_destinatario; }
string Notificacion::getTitulo() const { return titulo; }
string Notificacion::getMensaje() const { return mensaje; }

// Setters
void Notificacion::setIdNoti(int id) { this->idNoti = id; }
void Notificacion::setDniDestinatario(string dni) { this->dni_destinatario = dni; }
void Notificacion::setTitulo(string titulo) { this->titulo = titulo; }
void Notificacion::setMensaje(string mensaje) { this->mensaje = mensaje; }
