#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <windows.h>  // Para colores y gotoxy
using namespace std;

// ============================================================================
// FUNCIONES DE UTILIDAD PARA COLORES Y POSICIONAMIENTO
// ============================================================================

// Función para posicionar el cursor en coordenadas X,Y
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para cambiar color del texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Colores disponibles
#define RESET 7      // Blanco normal
#define VERDE 10     // Verde brillante
#define AZUL 9       // Azul brillante
#define ROJO 12      // Rojo brillante
#define AMARILLO 14  // Amarillo brillante
#define CYAN 11      // Cyan brillante
#define MAGENTA 13   // Magenta brillante

// ============================================================================
// ESTRUCTURA SIMPLE PARA GUARDAR DATOS DE UN ALUMNO
// ============================================================================

struct Alumno {
    // Información personal del alumno
    string nombre1;
    string apellido1;
    string apellido2;
    int ciclo;
    int cedula;
    
    // Notas de los 5 exámenes
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float nota5;
    
    // Promedio y si aprobó o no
    float promedio;
    bool aprobo;  // true = aprobado, false = reprobado
};

// ============================================================================
// FUNCIONES BÁSICAS - COMPLETAR CADA UNA
// ============================================================================

// Función 1: Preguntar cuántos alumnos evaluar - VERSION COMPATIBLE
int preguntarCantidadAlumnos() {
    int cantidad;
    
    do {
        cout << "Cuantos alumnos desea evaluar? ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "Error: Debe ingresar al menos 1 alumno." << endl;
            cout << "Por favor, intente nuevamente." << endl;
        }
           
    } while (cantidad <= 0);
    
    cout << "Se evaluaran " << cantidad << " alumno(s)." << endl;
    cout << "\n";
    return cantidad;
}

// Función 2: Pedir datos personales de un alumno - COMPLETADA POR JUAN
void pedirDatosPersonales(Alumno &estudiante) {
    // PASO 1: Pedir primer nombre y guardarlo en estudiante.nombre1
    cout << "Primer nombre: ";
    cin >> estudiante.nombre1;
    
    // Validación básica para nombre (no debe estar vacío)
    while (estudiante.nombre1.empty()) {
        cout << "Error: El nombre no puede estar vacío. Ingrese el primer nombre: ";
        cin >> estudiante.nombre1;
    }
    
    // PASO 2: Pedir primer apellido y guardarlo en estudiante.apellido1
    cout << "Primer apellido: ";
    cin >> estudiante.apellido1;
    
    // Validación básica para primer apellido
    while (estudiante.apellido1.empty()) {
        cout << "Error: El apellido no puede estar vacío. Ingrese el primer apellido: ";
        cin >> estudiante.apellido1;
    }
    
    // PASO 3: Pedir segundo apellido y guardarlo en estudiante.apellido2
    cout << "Segundo apellido: ";
    cin >> estudiante.apellido2;
    
    // Validación básica para segundo apellido
    while (estudiante.apellido2.empty()) {
        cout << "Error: El segundo apellido no puede estar vacío. Ingrese el segundo apellido: ";
        cin >> estudiante.apellido2;
    }
    
    // PASO 4: Pedir ciclo y guardarlo en estudiante.ciclo
    do {
        cout << "Ciclo (1-12): ";
        cin >> estudiante.ciclo;
        
        if (estudiante.ciclo < 1 || estudiante.ciclo > 12) {
            cout << "Error: El ciclo debe estar entre 1 y 12." << endl;
        }
    } while (estudiante.ciclo < 1 || estudiante.ciclo > 12);
    
    // PASO 5: Pedir cédula y guardarla en estudiante.cedula
    do {
        cout << "Cédula (número positivo): ";
        cin >> estudiante.cedula;
        
        if (estudiante.cedula <= 0) {
            cout << "Error: La cédula debe ser un número positivo." << endl;
        }
    } while (estudiante.cedula <= 0);
    
    cout << "Datos personales ingresados correctamente." << endl;
}

// Función 3: Pedir las 5 notas de exámenes - COMPLETADA POR ALISON
void pedirNotas(Alumno &estudiante) {
    // PASO 1: Pedir nota del examen 1 (validar que esté entre 0 y 100)
    do {
        cout << "Nota del examen 1 (0-100): ";
        cin >> estudiante.nota1;
        
        if (estudiante.nota1 < 0 || estudiante.nota1 > 100) {
            cout << "Error: La nota debe estar entre 0 y 100." << endl;
        }
    } while (estudiante.nota1 < 0 || estudiante.nota1 > 100);
    
    // PASO 2: Pedir nota del examen 2 (validar que esté entre 0 y 100)
    do {
        cout << "Nota del examen 2 (0-100): ";
        cin >> estudiante.nota2;
        
        if (estudiante.nota2 < 0 || estudiante.nota2 > 100) {
            cout << "Error: La nota debe estar entre 0 y 100." << endl;
        }
    } while (estudiante.nota2 < 0 || estudiante.nota2 > 100);
    
    // PASO 3: Pedir nota del examen 3 (validar que esté entre 0 y 100)
    do {
        cout << "Nota del examen 3 (0-100): ";
        cin >> estudiante.nota3;
        
        if (estudiante.nota3 < 0 || estudiante.nota3 > 100) {
            cout << "Error: La nota debe estar entre 0 y 100." << endl;
        }
    } while (estudiante.nota3 < 0 || estudiante.nota3 > 100);
    
    // PASO 4: Pedir nota del examen 4 (validar que esté entre 0 y 100)
    do {
        cout << "Nota del examen 4 (0-100): ";
        cin >> estudiante.nota4;
        
        if (estudiante.nota4 < 0 || estudiante.nota4 > 100) {
            cout << "Error: La nota debe estar entre 0 y 100." << endl;
        }
    } while (estudiante.nota4 < 0 || estudiante.nota4 > 100);
    
    // PASO 5: Pedir nota del examen 5 (validar que esté entre 0 y 100)
    do {
        cout << "Nota del examen 5 (0-100): ";
        cin >> estudiante.nota5;
        
        if (estudiante.nota5 < 0 || estudiante.nota5 > 100) {
            cout << "Error: La nota debe estar entre 0 y 100." << endl;
        }
    } while (estudiante.nota5 < 0 || estudiante.nota5 > 100);
    
    cout << "Todas las notas ingresadas correctamente." << endl;
}

// Función 4: Calcular el promedio del alumno - COMPLETADA POR TORTI
void calcularPromedio(Alumno &estudiante) {
    // PASO 1: Sumar las 5 notas
    float suma = estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4 + estudiante.nota5;
    
    // PASO 2: Dividir la suma entre 5
    estudiante.promedio = suma / 5.0;
    
    // PASO 3: Si el promedio es >= 70, poner estudiante.aprobo = true
    //         Si el promedio es < 70, poner estudiante.aprobo = false
    if (estudiante.promedio >= 70.0) {
        estudiante.aprobo = true;
    } else {
        estudiante.aprobo = false;
    }
    
    // Mensaje informativo
    cout << "Promedio calculado: " << fixed << setprecision(2) << estudiante.promedio;
    if (estudiante.aprobo) {
        cout << " - ¡APROBADO!" << endl;
    } else {
        cout << " - REPROBADO" << endl;
    }
}

// Función 5: Mostrar título bonito - VERSION COMPATIBLE PARA VS CODE
void mostrarTitulo() {
    // NO usar system("cls") en VS Code - causa problemas
    cout << "\n\n\n";
    
    // Título principal SIN colores problemáticos para VS Code
    cout << "============================================================" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||        SISTEMA DE EVALUACION ACADEMICA              ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "============================================================" << endl;
    
    // Información adicional
    cout << "\n            Version 1.0 - Sistema Profesional" << endl;
    cout << "          Desarrollado por: Juan, Alison y Torti" << endl;
    cout << "\n                 Bienvenido al sistema!" << endl;
    cout << "\n\n";
}

// Función auxiliar para obtener posición Y actual (Windows)
int whereY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

// Función auxiliar para mostrar encabezados de sección - VERSION SIMPLE
void mostrarEncabezadoSeccion(string titulo, int color = VERDE) {
    cout << "\n";
    cout << "============================================================" << endl;
    cout << "  " << titulo << endl;
    cout << "============================================================" << endl;
    cout << "\n";
}

// Función 6: Mostrar lista de aprobados - VERSION SIMPLE SIN COLORES
void mostrarAprobados(vector<Alumno> &lista) {
    mostrarEncabezadoSeccion("ESTUDIANTES APROBADOS");
    
    cout << "Nombre completo          Ciclo    Cedula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    bool hayAprobados = false;
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == true) {
            cout << "> " << lista[i].nombre1 << " " << lista[i].apellido1 << " " << lista[i].apellido2;
            cout << " (" << lista[i].ciclo << ") " << lista[i].cedula;
            cout << " " << fixed << setprecision(2) << lista[i].promedio << endl;
            hayAprobados = true;
        }
    }
    
    if (!hayAprobados) {
        cout << "No hay alumnos aprobados." << endl;
    }
}

// Función 7: Mostrar lista de reprobados - VERSION SIMPLE SIN COLORES
void mostrarReprobados(vector<Alumno> &lista) {
    mostrarEncabezadoSeccion("ESTUDIANTES REPROBADOS");
    
    cout << "Nombre completo          Ciclo    Cedula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    bool hayReprobados = false;
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == false) {
            cout << "> " << lista[i].nombre1 << " " << lista[i].apellido1 << " " << lista[i].apellido2;
            cout << " (" << lista[i].ciclo << ") " << lista[i].cedula;
            cout << " " << fixed << setprecision(2) << lista[i].promedio << endl;
            hayReprobados = true;
        }
    }
    
    if (!hayReprobados) {
        cout << "No hay alumnos reprobados." << endl;
    }
}

// ============================================================================
// FUNCIÓN PRINCIPAL - AQUÍ EMPIEZA EL PROGRAMA
// ============================================================================

int main() {
    // PASO 1: Mostrar título del programa
    mostrarTitulo();
    
    // PASO 2: Preguntar cuántos alumnos evaluar
    int cantidad = preguntarCantidadAlumnos();
    
    // PASO 3: Crear lista para guardar todos los alumnos
    vector<Alumno> listaAlumnos(cantidad);
    
    // PASO 4: Para cada alumno, pedir sus datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- ALUMNO #" << (i + 1) << " ---" << endl;
        
        // Pedir datos personales
        pedirDatosPersonales(listaAlumnos[i]);
        
        // Pedir las 5 notas
        pedirNotas(listaAlumnos[i]);
        
        // Calcular promedio y si aprobó
        calcularPromedio(listaAlumnos[i]);
        
        cout << "\n" << endl;
    }
    
    // PASO 5: Mostrar resultados finales
    mostrarAprobados(listaAlumnos);
    mostrarReprobados(listaAlumnos);
    
    return 0;
}

// ============================================================================
// INSTRUCCIONES PARA COMPLETAR EL CÓDIGO:
// ============================================================================

/*
🎨 AVANCE 1 DE 4 - MEJORAS DE INTERFAZ COMPLETADO 🎨

✅ AVANCE 1 - TÍTULOS Y ENCABEZADOS (Juan):
   - Título principal con marco decorativo y colores
   - Función gotoxy() para posicionamiento exacto
   - Colores definidos con constantes
   - Encabezados de sección con estilo
   - Información de desarrolladores y versión
   
PRÓXIMOS AVANCES:
❌ AVANCE 2 - ENTRADA DE DATOS (formularios con colores)
❌ AVANCE 3 - MENSAJES Y VALIDACIONES (errores en rojo, éxito en verde)  
❌ AVANCE 4 - ANIMACIONES Y EFECTOS FINALES (barras de progreso, etc.)

COLORES IMPLEMENTADOS:
- CYAN: Marcos y bordes
- AMARILLO: Títulos importantes
- VERDE: Aprobados y éxito
- ROJO: Reprobados y errores
- AZUL: Encabezados de tablas
- MAGENTA: Mensajes especiales
- RESET: Texto normal

FUNCIONES AGREGADAS:
✅ gotoxy(x, y) - Posicionamiento del cursor
✅ setColor(color) - Cambio de colores
✅ mostrarEncabezadoSeccion() - Encabezados con estilo
✅ whereY() - Obtener posición actual


*/