#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>
using namespace std;

class Notificacion {
private:
    int idNoti;
    string dni_destinatario;
    string titulo;
    string mensaje;

public:
    // Constructor
    Notificacion(int idNoti, string dni_destinatario, string titulo, string mensaje);
    ~Notificacion();

    // H8: Enviar notificación
    void enviar();

    // Getters
    int getIdNoti() const;
    string getDniDestinatario() const;
    string getTitulo() const;
    string getMensaje() const;

    // Setters
    void setIdNoti(int id);
    void setDniDestinatario(string dni);
    void setTitulo(string titulo);
    void setMensaje(string mensaje);
};

#endif // NOTIFICACION_H
