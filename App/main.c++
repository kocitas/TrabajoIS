#include <iostream>
#include "../core/actores/usuario.h"
#include "../core/actores/alumno.h"
#include "../core/actores/tutor.h"
#include "../core/actores/coordinador.h"
#include "../core/servicios/basedatos_uco.h"
#include "../core/documentos/solicitud_ayuda.h"
#include "../core/documentos/notificacion.h"

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "   SISTEMA DE TUTORIAS - UCO" << endl;
    cout << "========================================" << endl;
    cout << "1. Autenticacion (CU1)" << endl;
    cout << "2. Solicitar Tutoria (CU8)" << endl;
    cout << "3. Responder Mensaje (CU3)" << endl;
    cout << "4. Asignar Tutores Automaticamente (CU6)" << endl;
    cout << "5. Enviar Notificacion (H8)" << endl;
    cout << "0. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void demoCU1_Autenticacion() {
    cout << "\n--- CU1: AUTENTICACION ---" << endl;
    
    string email, password;
    cout << "Email UCO: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;
    
    Usuario usuario("", email, "", "");
    
    if (usuario.iniciarSesion(email, password)) {
        cout << "✓ Autenticacion exitosa!" << endl;
    } else {
        cout << "✗ Credenciales invalidas" << endl;
    }
}

void demoCU8_SolicitarTutoria() {
    cout << "\n--- CU8: SOLICITAR TUTORIA ---" << endl;
    
    // Crear alumno (datos de ejemplo)
    Alumno alumno("33333333D", "alumno1@uco.es", "hash_alumno1");
    
    string descripcion;
    cout << "Descripcion de la solicitud: ";
    cin.ignore();
    getline(cin, descripcion);
    
    alumno.solicitarTutoria(descripcion);
    cout << "✓ Solicitud de tutoria enviada correctamente" << endl;
}

void demoCU3_ResponderMensaje() {
    cout << "\n--- CU3: RESPONDER MENSAJE ---" << endl;
    
    // Crear tutor (datos de ejemplo)
    Tutor tutor("11111111B", "tutor1@uco.es", "hash_tutor1");
    
    int idSolicitud;
    string respuesta;
    
    cout << "ID de solicitud: ";
    cin >> idSolicitud;
    cout << "Respuesta: ";
    cin.ignore();
    getline(cin, respuesta);
    
    tutor.responderMensaje(idSolicitud, respuesta);
    cout << "✓ Respuesta enviada y notificacion creada" << endl;
}

void demoCU6_AsignarTutores() {
    cout << "\n--- CU6: ASIGNAR TUTORES AUTOMATICAMENTE ---" << endl;
    
    // Crear coordinador (datos de ejemplo)
    Coordinador coordinador("00000000A", "coord@uco.es", "hash_coord123");
    
    cout << "Ejecutando asignacion automatica..." << endl;
    coordinador.asignarTutoresAutomaticamente();
    cout << "✓ Asignacion completada y notificaciones enviadas" << endl;
}

void demoH8_EnviarNotificacion() {
    cout << "\n--- H8: ENVIAR NOTIFICACION ---" << endl;
    
    string dni, titulo, mensaje;
    
    cout << "DNI destinatario: ";
    cin >> dni;
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Mensaje: ";
    getline(cin, mensaje);
    
    Notificacion noti(0, dni, titulo, mensaje);
    
    // Guardar en BD
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    if (bd->guardarNotificacion(noti)) {
        cout << "✓ Notificacion guardada en BD" << endl;
        // Enviar notificacion
        noti.enviar();
    } else {
        cout << "✗ Error al guardar notificacion" << endl;
    }
}

int main() {
    cout << "Inicializando sistema de tutorias..." << endl;
    
    // Verificar conexion a base de datos
    BaseDatosUCO* bd = BaseDatosUCO::getInstance();
    if (bd == nullptr) {
        cerr << "Error: No se pudo conectar a la base de datos" << endl;
        cerr << "Asegurese de ejecutar 'python data/create_db.py' primero" << endl;
        return 1;
    }
    
    cout << "✓ Conexion a base de datos establecida" << endl;
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                demoCU1_Autenticacion();
                break;
            case 2:
                demoCU8_SolicitarTutoria();
                break;
            case 3:
                demoCU3_ResponderMensaje();
                break;
            case 4:
                demoCU6_AsignarTutores();
                break;
            case 5:
                demoH8_EnviarNotificacion();
                break;
            case 0:
                cout << "\nCerrando sistema..." << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }
        
    } while (opcion != 0);
    
    cout << "¡Hasta pronto!" << endl;
    return 0;
}
