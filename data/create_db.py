import sqlite3
import os

DB_PATH = os.path.join(os.path.dirname(__file__), 'tutorias.db')
SCHEMA_PATH = os.path.join(os.path.dirname(__file__), 'schema.sql')

def create_database():
    # Remove existing database
    if os.path.exists(DB_PATH):
        os.remove(DB_PATH)
        print(f"Removed existing database: {DB_PATH}")

    # Create new database
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    # Read and execute schema
    with open(SCHEMA_PATH, 'r', encoding='utf-8') as f:
        schema_sql = f.read()
    
    cursor.executescript(schema_sql)
    print("Tables created successfully.")

    # Insert sample data
    usuarios = [
        # Coordinadores
        ('00000000A', 'coord@uco.es', 'hash_coord123', 'Coordinador'),
        # Tutores
        ('11111111B', 'tutor1@uco.es', 'hash_tutor1', 'Tutor'),
        ('22222222C', 'tutor2@uco.es', 'hash_tutor2', 'Tutor'),
        # Alumnos
        ('33333333D', 'alumno1@uco.es', 'hash_alumno1', 'Alumno'),
        ('44444444E', 'alumno2@uco.es', 'hash_alumno2', 'Alumno'),
        ('55555555F', 'alumno3@uco.es', 'hash_alumno3', 'Alumno'),
        ('66666666G', 'alumno4@uco.es', 'hash_alumno4', 'Alumno'),
        ('77777777H', 'alumno5@uco.es', 'hash_alumno5', 'Alumno'),
    ]

    cursor.executemany("""
        INSERT INTO USUARIOS (DNI, emailUCO, password_hash, rol)
        VALUES (?, ?, ?, ?)
    """, usuarios)
    print(f"Inserted {len(usuarios)} users.")

    # Asignaciones de tutoría
    relaciones = [
        ('33333333D', '11111111B'),  # alumno1 -> tutor1
        ('44444444E', '11111111B'),  # alumno2 -> tutor1
        ('55555555F', '22222222C'),  # alumno3 -> tutor2
    ]

    cursor.executemany("""
        INSERT INTO RELACION_TUTORIA (dni_alumno, dni_tutor)
        VALUES (?, ?)
    """, relaciones)
    print(f"Created {len(relaciones)} tutoring relationships.")

    # Solicitudes de ayuda
    solicitudes = [
        ('33333333D', '11111111B', 'Necesito ayuda con el TFG', 'Pendiente'),
        ('44444444E', '11111111B', 'Consulta sobre asignaturas optativas', 'Resuelta'),
    ]

    cursor.executemany("""
        INSERT INTO SOLICITUDES_AYUDA (dni_alumno, dni_tutor, descripcion, estado)
        VALUES (?, ?, ?, ?)
    """, solicitudes)
    print(f"Created {len(solicitudes)} help requests.")

    # Notificaciones
    notificaciones = [
        ('33333333D', 'Nueva asignación', 'Has sido asignado al tutor tutor1@uco.es'),
        ('11111111B', 'Nueva solicitud', 'Tienes una nueva solicitud de ayuda'),
    ]

    cursor.executemany("""
        INSERT INTO NOTIFICACIONES (dni_destinatario, titulo, mensaje)
        VALUES (?, ?, ?)
    """, notificaciones)
    print(f"Created {len(notificaciones)} notifications.")

    conn.commit()
    conn.close()
    print(f"\nDatabase created successfully at: {DB_PATH}")

if __name__ == "__main__":
    create_database()
