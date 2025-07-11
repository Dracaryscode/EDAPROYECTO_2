#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "baseDeDatos.h" // Incluimos para que conozca la clase Persona

// CAMBIO: La entrada ahora almacena un puntero al objeto Persona completo.
struct EntradaHash {
    Persona* personaPtr; // Puntero a la persona
    bool activo;
};

class TablaHash {
private:
    EntradaHash* tabla;
    int capacidad;
    int cantidad;
    float factorCarga;

    int hash(int id);
    void rehacerHash();

public:
    TablaHash(int cap = 50009, float fc = 0.7f); // Capacidad mayor para 50k
    ~TablaHash();
    // --- CAMBIO: AÑADIMOS LA REGLA DE TRES ---
    TablaHash(const TablaHash& otra); // Constructor de copia
    TablaHash& operator=(const TablaHash& otra); // Operador de asignación


    // CAMBIO: El méto do ahora inserta un puntero a Persona.
    bool insertar(Persona* persona);
    // CAMBIO: El méto do ahora busca y devuelve un puntero a Persona.
    Persona* buscar(int id);
    bool eliminar(int id);
    int obtenerCantidad() const;
};

#endif // HASHTABLE_H