#include "basedatos_uco.h"
#include <iostream>

// Inicializar instancia estática
BaseDatosUCO* BaseDatosUCO::instance = nullptr;

BaseDatosUCO::BaseDatosUCO() {
    db = nullptr;
    dbPath = "data/tutorias.db";
    conectar();
}

BaseDatosUCO::~BaseDatosUCO() {
    desconectar();
}

BaseDatosUCO* BaseDatosUCO::getInstance() {
    if (instance == nullptr) {
        instance = new BaseDatosUCO();
    }
    return instance;
}

bool BaseDatosUCO::conectar() {
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc != SQLITE_OK) {
        cerr << "Error al abrir base de datos: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    return true;
}

void BaseDatosUCO::desconectar() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

// CU1: Validar credenciales
bool BaseDatosUCO::validarCredenciales(string email, string password) {
    if (db == nullptr) return false;

    string sql = "SELECT password_hash FROM USUARIOS WHERE emailUCO = ?";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparando query: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_TRANSIENT);

    bool valid = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* stored_hash = (const char*)sqlite3_column_text(stmt, 0);
        // En producción, usar bcrypt o similar para comparar hashes
        valid = (password == stored_hash);
    }

    sqlite3_finalize(stmt);
    return valid;
}

// CU6: Registrar asignación
bool BaseDatosUCO::registrarAsignacion(string dniAlumno, string dniTutor) {
    if (db == nullptr) return false;

    string sql = "INSERT INTO RELACION_TUTORIA (dni_alumno, dni_tutor) VALUES (?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparando query: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, dniAlumno.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, dniTutor.c_str(), -1, SQLITE_TRANSIENT);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);

    return success;
}

// CU8: Guardar solicitud de ayuda
bool BaseDatosUCO::guardarSolicitud(SolicitudAyuda solicitud) {
    if (db == nullptr) return false;

    string sql = "INSERT INTO SOLICITUDES_AYUDA (dni_alumno, dni_tutor, descripcion, estado) "
                 "VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparando query: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, solicitud.getDniAlumno().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, solicitud.getDniTutor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, solicitud.getDescripcion().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, solicitud.getEstado().c_str(), -1, SQLITE_TRANSIENT);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);

    return success;
}

// H8: Guardar notificación
bool BaseDatosUCO::guardarNotificacion(Notificacion noti) {
    if (db == nullptr) return false;

    string sql = "INSERT INTO NOTIFICACIONES (dni_destinatario, titulo, mensaje) "
                 "VALUES (?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error preparando query: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, noti.getDniDestinatario().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, noti.getTitulo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, noti.getMensaje().c_str(), -1, SQLITE_TRANSIENT);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);

    return success;
}
