-- SQLite DDL Schema for Tutoring System
-- Supporting CU1 (Authentication), CU3 (Communication), CU6 (Assignment), CU8 (Help Request)

PRAGMA foreign_keys = ON;

-- Table: USUARIOS (CL1)
CREATE TABLE USUARIOS (
    DNI TEXT PRIMARY KEY,
    emailUCO TEXT NOT NULL UNIQUE,
    password_hash TEXT NOT NULL,
    rol TEXT CHECK(rol IN ('Alumno', 'Tutor', 'Coordinador')) NOT NULL
);

-- Table: RELACION_TUTORIA (CU6)
CREATE TABLE RELACION_TUTORIA (
    dni_alumno TEXT PRIMARY KEY,
    dni_tutor TEXT NOT NULL,
    FOREIGN KEY (dni_alumno) REFERENCES USUARIOS(DNI) ON DELETE CASCADE,
    FOREIGN KEY (dni_tutor) REFERENCES USUARIOS(DNI) ON DELETE CASCADE
);

-- Table: SOLICITUDES_AYUDA (CL7, CU8)
CREATE TABLE SOLICITUDES_AYUDA (
    idSolicitud INTEGER PRIMARY KEY AUTOINCREMENT,
    dni_alumno TEXT NOT NULL,
    dni_tutor TEXT,
    descripcion TEXT NOT NULL,
    estado TEXT DEFAULT 'Pendiente',
    FOREIGN KEY (dni_alumno) REFERENCES USUARIOS(DNI) ON DELETE CASCADE,
    FOREIGN KEY (dni_tutor) REFERENCES USUARIOS(DNI) ON DELETE SET NULL
);

-- Table: NOTIFICACIONES (CL11, H8)
CREATE TABLE NOTIFICACIONES (
    idNoti INTEGER PRIMARY KEY AUTOINCREMENT,
    dni_destinatario TEXT NOT NULL,
    titulo TEXT NOT NULL,
    mensaje TEXT NOT NULL,
    FOREIGN KEY (dni_destinatario) REFERENCES USUARIOS(DNI) ON DELETE CASCADE
);
