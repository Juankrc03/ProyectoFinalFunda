#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

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

// Función 1: Preguntar cuántos alumnos evaluar
int preguntarCantidadAlumnos() {
    int cantidad;
    
    do {
         cout << "¿Cuántos alumnos desea evaluar? ";
        cin >> cantidad;

        if (cantidad <= 0) {
          cout << "Error, tienes que ingresar minimo un alumno";

        }
           
    } while (cantidad <=0);
    
    
  
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

// Función 3: Pedir las 5 notas de exámenes
void pedirNotas(Alumno &estudiante) {
    // PASO 1: Pedir nota del examen 1 (validar que esté entre 0 y 100)
    // PASO 2: Pedir nota del examen 2 (validar que esté entre 0 y 100)
    // PASO 3: Pedir nota del examen 3 (validar que esté entre 0 y 100)
    // PASO 4: Pedir nota del examen 4 (validar que esté entre 0 y 100)
    // PASO 5: Pedir nota del examen 5 (validar que esté entre 0 y 100)
    
    cout << "Nota del examen 1 (0-100): ";
    cin >> estudiante.nota1;
    // AQUÍ FALTA: validar que esté entre 0 y 100
    
    cout << "Nota del examen 2 (0-100): ";
    cin >> estudiante.nota2;
    // AQUÍ FALTA: validar que esté entre 0 y 100
    
    // COMPLETAR LAS DEMÁS NOTAS...
}

// Función 4: Calcular el promedio del alumno
void calcularPromedio(Alumno &estudiante) {
    // PASO 1: Sumar las 5 notas
    // PASO 2: Dividir la suma entre 5
    // PASO 3: Guardar el resultado en estudiante.promedio
    // PASO 4: Si el promedio es >= 70, poner estudiante.aprobo = true
    //         Si el promedio es < 70, poner estudiante.aprobo = false
    
    float suma = estudiante.nota1 + estudiante.nota2; // COMPLETAR SUMA
    estudiante.promedio = suma / 5.0;
    
    if (estudiante.promedio >= 70.0) {
        estudiante.aprobo = true;
    } else {
        estudiante.aprobo = false;
    }
}

// Función 5: Mostrar título bonito
void mostrarTitulo() {
    // PASO 1: Mostrar línea de símbolos (============================)
    // PASO 2: Mostrar el título del programa
    // PASO 3: Mostrar otra línea de símbolos
    
    cout << "======================================" << endl;
    cout << "    SISTEMA DE EVALUACIÓN ACADÉMICA   " << endl;
    cout << "======================================" << endl;
}

// Función 6: Mostrar lista de aprobados
void mostrarAprobados(vector<Alumno> &lista) {
    cout << "\n==================== APROBADOS ====================" << endl;
    cout << "Nombre completo          Ciclo    Cédula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    // PASO 1: Recorrer toda la lista de alumnos
    // PASO 2: Si el alumno aprobó (aprobo == true), mostrarlo
    // PASO 3: Formato: > María Pérez Gómez (2) 20182345 78.40
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == true) {
            // AQUÍ FALTA: mostrar los datos del alumno
            cout << "> " << lista[i].nombre1 << " " << lista[i].apellido1 << " " << lista[i].apellido2;
            // COMPLETAR LA LÍNEA...
        }
    }
}

// Función 7: Mostrar lista de reprobados
void mostrarReprobados(vector<Alumno> &lista) {
    cout << "\n==================== REPROBADOS ===================" << endl;
    cout << "Nombre completo          Ciclo    Cédula      Promedio" << endl;
    cout << "----------------------------------------------------" << endl;
    
    // PASO 1: Recorrer toda la lista de alumnos
    // PASO 2: Si el alumno reprobó (aprobo == false), mostrarlo
    // PASO 3: Mismo formato que los aprobados
    
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].aprobo == false) {
            // AQUÍ FALTA: mostrar los datos del alumno reprobado
        }
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
        
        cout << "Promedio: " << listaAlumnos[i].promedio << endl;
        if (listaAlumnos[i].aprobo) {
            cout << "Estado: APROBADO" << endl;
        } else {
            cout << "Estado: REPROBADO" << endl;
        }
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
TAREAS SIMPLES PARA COMPLETAR:

1. En preguntarCantidadAlumnos(): Torti 🔄
   - Mejorar mensaje de error y formato
   - Ya funciona pero falta pulir

2. En pedirDatosPersonales(): Juan ✅ COMPLETADO
   - Función completamente terminada con validaciones
   - LISTO PARA USAR

3. En pedirNotas(): Alison ❌
   - Completar las notas que faltan (nota3, nota4, nota5)
   - Agregar validación: si nota < 0 o nota > 100, mostrar error

4. En calcularPromedio(): Torti ❌
   - Completar la suma con todas las 5 notas
   - Ahora solo suma 2 notas

5. En mostrarAprobados() y mostrarReprobados(): Alison ❌
   - Completar el formato de salida con todos los datos
   - Falta mostrar ciclo, cédula y promedio formateado
   
6. Menu y estilo: Juan ❌
   - Agregar colores a los mensajes
   - Hacer la interfaz más bonita

ESTADO ACTUAL:
✅ pedirDatosPersonales() - COMPLETADA (Juan)
✅ preguntarCantidadAlumnos() - FUNCIONA (Torti, falta pulir)
❌ pedirNotas() - PENDIENTE (Alison)
❌ calcularPromedio() - PENDIENTE (Torti)
❌ mostrarAprobados() - PENDIENTE (Alison)
❌ mostrarReprobados() - PENDIENTE (Alison)
❌ Mejoras de interfaz - PENDIENTE (Juan)

CONSEJOS:
- Completar una función a la vez
- Probar el programa después de cada cambio
- Si algo no funciona, revisar los paréntesis y puntos y comas
- Usar cout para mostrar mensajes
- Usar cin para leer datos del usuario
*/