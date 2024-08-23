#ifndef GESTORMATRICES_H
#define GESTORMATRICES_H

#include <QTableWidget>
#include <QString>
#include <QMessageBox>
#include <QLabel>


class GestorMatrices
{
public:
    GestorMatrices();
    void crearMatrices(int n1, int m1, int n2, int m2, QTableWidget* tabla1, QTableWidget* tabla2);
    void sumarMatrices(QTableWidget* tabla1, QTableWidget* tabla2, QTableWidget* resultado);
    void restarMatrices(QTableWidget* tabla1, QTableWidget* tabla2, QTableWidget* resultado);
    void multiplicarMatrices(QTableWidget* tabla1, QTableWidget* tabla2, QTableWidget* resultado);
    void crearMatriz(int n, int m, QTableWidget* tabla);
    void buscarElemento(int elemento, QTableWidget* tabla, QLabel* posicion);
    void calcularTranspuesta(QTableWidget* tabla1, QTableWidget* resultado);
    void rotarMatriz(QTableWidget* resultado);
    void copiarTabla(QTableWidget* tabla1, QTableWidget* tabla2);
};

#endif // GESTORMATRICES_H
