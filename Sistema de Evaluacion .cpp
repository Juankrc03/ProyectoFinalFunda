#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

// Constantes para colores
const int VERDE = 10;
const int ROJO = 12;
const int BLANCO = 15;
const int AMARILLO = 14;
const int CYAN = 11;

// Función para cambiar el color del texto
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

struct Alumno {
    string nombre1;
    string apellido1;
    string apellido2;
    int ciclo;
    int cedula;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float nota5;
    float promedio;
    bool aprobo;
};

int preguntarCantidadAlumnos() {
    string cantidadStr;
    int cantidad;
    
    cout << "Cuantos alumnos desea evaluar? ";
    cin >> cantidadStr;
    
    cantidad = 1;
    for (char c : cantidadStr) {
        if (isdigit(c)) {
            cantidad = atoi(cantidadStr.c_str());
            break;
        }
    }
    
    if (cantidad <= 0) cantidad = 1;
    
    cout << "Se evaluaran " << cantidad << " alumno(s)." << endl;
    return cantidad;
}

void pedirDatosPersonales(Alumno &estudiante) {
    cout << "\n";
    setColor(CYAN);
    cout << "==================================================\n";
    cout << "         DATOS PERSONALES\n";
    cout << "==================================================\n";
    setColor(BLANCO);
    
    setColor(CYAN);
    cout << "\nPrimer nombre: ";
    setColor(BLANCO);
    cin >> estudiante.nombre1;
    cout << "OK" << endl;
    
    setColor(CYAN);
    cout << "\nPrimer apellido: ";
    setColor(BLANCO);
    cin >> estudiante.apellido1;
    cout << "OK" << endl;
    
    setColor(CYAN);
    cout << "\nSegundo apellido: ";
    setColor(BLANCO);
    cin >> estudiante.apellido2;
    cout << "OK" << endl;
    
    // Ciclo con validación que vuelve a preguntar
    string cicloStr;
    while (true) {
        setColor(CYAN);
        cout << "\nCiclo (1-12): ";
        setColor(BLANCO);
        cin >> cicloStr;
        
        bool esValido = true;
        for (char c : cicloStr) {
            if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !cicloStr.empty()) {
            int temp = atoi(cicloStr.c_str());
            if (temp >= 1 && temp <= 12) {
                estudiante.ciclo = temp;
                setColor(CYAN);
                cout << "Ciclo: " << estudiante.ciclo << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: El ciclo debe estar entre 1 y 12." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
    
    // Cédula con validación que vuelve a preguntar
    string cedulaStr;
    while (true) {
        setColor(CYAN);
        cout << "\nCedula: ";
        setColor(BLANCO);
        cin >> cedulaStr;
        
        bool esValido = true;
        for (char c : cedulaStr) {
            if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !cedulaStr.empty()) {
            int temp = atoi(cedulaStr.c_str());
            if (temp > 0) {
                estudiante.cedula = temp;
                setColor(CYAN);
                cout << "Cedula: " << estudiante.cedula << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La cedula debe ser un numero positivo." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
}

void pedirNotas(Alumno &estudiante) {
    cout << "\n";
    setColor(AMARILLO);  // Cambiar a amarillo
    cout << "==================================================\n";
    cout << "           NOTAS\n";
    cout << "==================================================\n";
    setColor(BLANCO);    // Volver a blanco para el resto
    
    string notaStr;
    
    // Nota 1 con validación
    while (true) {
        setColor(AMARILLO);
        cout << "\nNota 1 (0-100): ";
        setColor(BLANCO);
        cin >> notaStr;
        
        bool esValido = true;
        bool tienePunto = false;
        
        for (char c : notaStr) {
            if (c == '.' && !tienePunto) {
                tienePunto = true;
            } else if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !notaStr.empty()) {
            float temp = atof(notaStr.c_str());
            if (temp >= 0 && temp <= 100) {
                estudiante.nota1 = temp;
                setColor(AMARILLO);
                cout << "Nota 1: " << estudiante.nota1 << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La nota debe estar entre 0 y 100." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
    
    // Nota 2 con validación
    while (true) {
        setColor(AMARILLO);
        cout << "\nNota 2 (0-100): ";
        setColor(BLANCO);
        cin >> notaStr;
        
        bool esValido = true;
        bool tienePunto = false;
        
        for (char c : notaStr) {
            if (c == '.' && !tienePunto) {
                tienePunto = true;
            } else if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !notaStr.empty()) {
            float temp = atof(notaStr.c_str());
            if (temp >= 0 && temp <= 100) {
                estudiante.nota2 = temp;
                setColor(AMARILLO);
                cout << "Nota 2: " << estudiante.nota2 << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La nota debe estar entre 0 y 100." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
    
    // Nota 3 con validación
    while (true) {
        setColor(AMARILLO);
        cout << "\nNota 3 (0-100): ";
        setColor(BLANCO);
        cin >> notaStr;
        
        bool esValido = true;
        bool tienePunto = false;
        
        for (char c : notaStr) {
            if (c == '.' && !tienePunto) {
                tienePunto = true;
            } else if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !notaStr.empty()) {
            float temp = atof(notaStr.c_str());
            if (temp >= 0 && temp <= 100) {
                estudiante.nota3 = temp;
                setColor(AMARILLO);
                cout << "Nota 3: " << estudiante.nota3 << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La nota debe estar entre 0 y 100." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
    
    // Nota 4 con validación
    while (true) {
        setColor(AMARILLO);
        cout << "\nNota 4 (0-100): ";
        setColor(BLANCO);
        cin >> notaStr;
        
        bool esValido = true;
        bool tienePunto = false;
        
        for (char c : notaStr) {
            if (c == '.' && !tienePunto) {
                tienePunto = true;
            } else if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !notaStr.empty()) {
            float temp = atof(notaStr.c_str());
            if (temp >= 0 && temp <= 100) {
                estudiante.nota4 = temp;
                setColor(AMARILLO);
                cout << "Nota 4: " << estudiante.nota4 << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La nota debe estar entre 0 y 100." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
    
    // Nota 5 con validación
    while (true) {
        setColor(AMARILLO);
        cout << "\nNota 5 (0-100): ";
        setColor(BLANCO);
        cin >> notaStr;
        
        bool esValido = true;
        bool tienePunto = false;
        
        for (char c : notaStr) {
            if (c == '.' && !tienePunto) {
                tienePunto = true;
            } else if (!isdigit(c)) {
                esValido = false;
                break;
            }
        }
        
        if (esValido && !notaStr.empty()) {
            float temp = atof(notaStr.c_str());
            if (temp >= 0 && temp <= 100) {
                estudiante.nota5 = temp;
                setColor(AMARILLO);
                cout << "Nota 5: " << estudiante.nota5 << endl;
                setColor(BLANCO);
                break;
            } else {
                setColor(ROJO);
                cout << "ERROR: La nota debe estar entre 0 y 100." << endl;
                cout << "Por favor, intente nuevamente." << endl;
                setColor(BLANCO);
            }
        } else {
            setColor(ROJO);
            cout << "ERROR: Debe ingresar un numero valido." << endl;
            cout << "Por favor, intente nuevamente." << endl;
            setColor(BLANCO);
        }
    }
}

void calcularPromedio(Alumno &estudiante) {
    float suma = estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4 + estudiante.nota5;
    estudiante.promedio = suma / 5.0;
    
    if (estudiante.promedio >= 70.0) {
        estudiante.aprobo = true;
    } else {
        estudiante.aprobo = false;
    }
    
    cout << "\n========================================\n";
    cout << "RESULTADO FINAL:\n";
    cout << "Promedio: " << fixed << setprecision(2) << estudiante.promedio;
    
    if (estudiante.aprobo) {
        setColor(VERDE);
        cout << " - APROBADO" << endl;
        setColor(BLANCO);
    } else {
        setColor(ROJO);
        cout << " - REPROBADO" << endl;
        setColor(BLANCO);
    }
    cout << "========================================\n";
}

void mostrarTitulo() {
    setColor(CYAN);
    cout << "\n\n";
    cout << "============================================================" << endl;
    cout << "||                                                      ||" << endl;
    cout << "||        SISTEMA DE EVALUACION ACADEMICA               ||" << endl;
    cout << "||                                                      ||" << endl;
    cout << "============================================================" << endl;
    setColor(AMARILLO);
    cout << "\n            Version 1.0 - Sistema Profesional" << endl;
    cout << "          Desarrollado por: Juan, Alison y Torti" << endl;
    setColor(BLANCO);
    cout << "\n                 Bienvenido al sistema!" << endl;
    cout << "\n\n";
}

void mostrarAprobados(vector<Alumno> &lista) {
    cout << "\n============================================================" << endl;
    setColor(VERDE);
    cout << "  ESTUDIANTES APROBADOS" << endl;
    setColor(BLANCO);
    cout << "============================================================" << endl;
    
    cout << "Nombre completo          Ciclo    Cedula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    bool hayAprobados = false;
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == true) {
            setColor(VERDE);
            cout << "> " << lista[i].nombre1 << " " << lista[i].apellido1 << " " << lista[i].apellido2;
            cout << " (" << lista[i].ciclo << ") " << lista[i].cedula;
            cout << " " << fixed << setprecision(2) << lista[i].promedio << endl;
            setColor(BLANCO);
            hayAprobados = true;
        }
    }
    
    if (!hayAprobados) {
        cout << "No hay alumnos aprobados." << endl;
    }
}

void mostrarReprobados(vector<Alumno> &lista) {
    cout << "\n============================================================" << endl;
    setColor(ROJO);
    cout << "  ESTUDIANTES REPROBADOS" << endl;
    setColor(BLANCO);
    cout << "============================================================" << endl;
    
    cout << "Nombre completo          Ciclo    Cedula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    bool hayReprobados = false;
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == false) {
            setColor(ROJO);
            cout << "> " << lista[i].nombre1 << " " << lista[i].apellido1 << " " << lista[i].apellido2;
            cout << " (" << lista[i].ciclo << ") " << lista[i].cedula;
            cout << " " << fixed << setprecision(2) << lista[i].promedio << endl;
            setColor(BLANCO);
            hayReprobados = true;
        }
    }
    
    if (!hayReprobados) {
        cout << "No hay alumnos reprobados." << endl;
    }
}

int main() {
    mostrarTitulo();
    
    int cantidad = preguntarCantidadAlumnos();
    
    vector<Alumno> listaAlumnos(cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        cout << "\n============================================================" << endl;
        cout << "           ALUMNO #" << (i + 1) << " DE " << cantidad << endl;
        cout << "============================================================" << endl;
        
        pedirDatosPersonales(listaAlumnos[i]);
        pedirNotas(listaAlumnos[i]);
        calcularPromedio(listaAlumnos[i]);
        
        cout << "\n" << endl;
    }
    
    mostrarAprobados(listaAlumnos);
    mostrarReprobados(listaAlumnos);
    
    cout << "\nGracias por usar el Sistema!" << endl;
    cout << "Presiona Enter para salir...";
    cin.ignore();
    cin.get();
    
    return 0;
}