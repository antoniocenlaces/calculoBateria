/*********************************************************************************************\
 * Programación 1. Trabajo obligatorio
 * Autores: Antonio José González Almela
 * Ultima revisión: 10/12/2022
 * Resumen: Fichero de implementación del módulo principal que implementa el trabajo
 *          obligatorio de Programación 1 del curso 2022-23.
\*********************************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    struct tpBateria {
        double carga; // carga al final del día de la batería en KWh
        double aConsumo; // consumo enviado, durante el día, desde la batería al cliente en KWh
        double compraMercado; // compra en mercado de energía, durnate este día en KWh
        double aRed; // energía vertida a red por no entrar en batería ni en cliente en KWh

    };
    tpBateria bateria[367];
    // bateria[0] es el estado inicial de la batería antes de comenzar con el primer día
    // de análisis de carga/descarga
    bateria[0].carga=1200.0;
    string ficheroBalance;
    cout << "Ruta del fichero con el balance energético día a día: ";
    cin >> ficheroBalance;
    ifstream f;
    f.open(ficheroBalance);
    if (!f.is_open()) {
        cerr << "\x1b[1;31m" << "ERROR AL ABRIR EL FICHERO: \"" << ficheroBalance << "\". "
            << "\x1b[0m" << endl;
        return false;
    }
    double balance = 0.0; // Balance energético de un día leido de fichero
    unsigned dia = 0; // Día del año (entre 1 y 366)
    unsigned hora = 0; // Hora del día que estoy leyendo el balance
    string dato;
    // f viene de windows y tirne tres bytes al inicio que hay que descartar
    f.seekg(3);

    // if (getline(f, dato, ';')) {
    //     dia++;
    //     string bueno;
    //     unsigned d = 0;
    //     for (unsigned i = 0;i < dato.length(); i++) {
    //         if (dato[i]==46 || (dato[i]>= 48 && dato[i] <= 57)){
    //         bueno[d]=dato[i];
    //         d++;
    //         }
    //     }
    //     balance = stod(bueno);
    //     bateria[1].carga=balance;
    //     hora++;
    // }
    while (getline(f, dato, ';') && dia < 50) {
         dia++; // Paso al siguiente dia
        balance = std::stod(dato);
        bateria[dia].carga = balance;
        cout << "Dia: " << dia << " hora: " << hora << " leido: " << dato << " double: " << balance << endl;
        hora++;
        if (hora == 24) {
            cout << endl;
            hora=0;
            }
        
    }
    f.close();
    for (unsigned i = 0;i <= dia; i++){
        cout << bateria[i].carga << endl;
    }
    // cout << fixed << bateria[0].carga << endl;;
}