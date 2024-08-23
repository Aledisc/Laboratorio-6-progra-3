#include "gestormatrices.h"

GestorMatrices::GestorMatrices() {}

void GestorMatrices::crearMatrices(int n1, int m1, int n2, int m2, QTableWidget* tabla1, QTableWidget* tabla2)
{
    tabla1->setRowCount(n1);
    tabla1->setColumnCount(m1);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            tabla1->setItem(i, j, new QTableWidgetItem(QString::number(0)));
        }
    }

    tabla2->setRowCount(n2);
    tabla2->setColumnCount(m2);

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            tabla2->setItem(i, j, new QTableWidgetItem(QString::number(0)));
        }
    }
}


void GestorMatrices::sumarMatrices(QTableWidget *tabla1, QTableWidget *tabla2, QTableWidget *resultado)
{
    int filas1 = tabla1->rowCount();
    int columnas1 = tabla1->columnCount();
    int filas2 = tabla2->rowCount();
    int columnas2 = tabla2->columnCount();

    if (filas1 != filas2 || columnas1 != columnas2) {
        QMessageBox::warning(nullptr, "Error", "Las matrices no tienen las mismas dimensiones.");
        return; // salir
    }

    resultado->setRowCount(filas1);
    resultado->setColumnCount(columnas1);

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            int valor1 = tabla1->item(i, j)->text().toInt();
            int valor2 = tabla2->item(i, j)->text().toInt();
            int suma = valor1 + valor2;

            resultado->setItem(i, j, new QTableWidgetItem(QString::number(suma)));
        }
    }
}

void GestorMatrices::restarMatrices(QTableWidget *tabla1, QTableWidget *tabla2, QTableWidget *resultado)
{
    int filas1 = tabla1->rowCount();
    int columnas1 = tabla1->columnCount();
    int filas2 = tabla2->rowCount();
    int columnas2 = tabla2->columnCount();

    if (filas1 != filas2 || columnas1 != columnas2) {
        QMessageBox::warning(nullptr, "Error", "Las matrices no tienen las mismas dimensiones.");
        return;
    }

    resultado->setRowCount(filas1);
    resultado->setColumnCount(columnas1);

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            int valor1 = tabla1->item(i, j)->text().toInt();
            int valor2 = tabla2->item(i, j)->text().toInt();

            int resta = valor2 - valor1;

            resultado->setItem(i, j, new QTableWidgetItem(QString::number(resta)));
        }
    }
}

void GestorMatrices::multiplicarMatrices(QTableWidget *tabla1, QTableWidget *tabla2, QTableWidget *resultado)
{
    int filas1 = tabla1->rowCount();
    int columnas1 = tabla1->columnCount();
    int filas2 = tabla2->rowCount();
    int columnas2 = tabla2->columnCount();

    if (columnas1 != filas2) {
        QMessageBox::warning(nullptr, "Error", "El número de columnas de la primera matriz debe coincidir con el número de filas de la segunda matriz.");
        return;
    }


    resultado->setRowCount(filas1);
    resultado->setColumnCount(columnas2);

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            int suma = 0;
            for (int k = 0; k < columnas1; ++k) {
                int valor1 = tabla1->item(i, k)->text().toInt();
                int valor2 = tabla2->item(k, j)->text().toInt();
                suma += valor1 * valor2;
            }
            resultado->setItem(i, j, new QTableWidgetItem(QString::number(suma)));
        }
    }
}

void GestorMatrices::crearMatriz(int n, int m, QTableWidget *tabla)
{
    tabla->setRowCount(n);
    tabla->setColumnCount(m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tabla->setItem(i, j, new QTableWidgetItem(QString::number(0)));
        }
    }
}

void GestorMatrices::buscarElemento(int elemento, QTableWidget *tabla, QLabel *posicion)
{
    QString posiciones;
    bool encontrado = false;

    int filas = tabla->rowCount();
    int columnas = tabla->columnCount();

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            int valor = tabla->item(i, j)->text().toInt();
            if (valor == elemento) {
                if (encontrado) {
                    posiciones += ", ";
                }
                posiciones += QString("(%1,%2)").arg(i + 1).arg(j + 1);
                encontrado = true;
            }
        }
    }

    if (encontrado) {
        posicion->setText(posiciones);
    } else {
        QMessageBox::information(nullptr, "Resultado de Búsqueda", "No se encontró el elemento.");
        posicion->clear();
    }
}

void GestorMatrices::calcularTranspuesta(QTableWidget *tabla1, QTableWidget *resultado)
{
    int filas1 = tabla1->rowCount();
    int columnas1 = tabla1->columnCount();

    resultado->setRowCount(columnas1);
    resultado->setColumnCount(filas1);

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            int valor = tabla1->item(i, j)->text().toInt();
            resultado->setItem(j, i, new QTableWidgetItem(QString::number(valor)));
        }
    }
}

void GestorMatrices::rotarMatriz(QTableWidget *resultado)
{

    if (resultado->rowCount() == 0 || resultado->columnCount() == 0) {
        QMessageBox::warning(nullptr, "Advertencia", "Primero debe generar la matriz.");
        return;
    }

    int filas = resultado->rowCount();
    int columnas = resultado->columnCount();

    QTableWidget* temp = new QTableWidget();
    temp->setRowCount(columnas);
    temp->setColumnCount(filas);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            QString valor = resultado->item(i, j)->text();
            temp->setItem(j, filas - 1 - i, new QTableWidgetItem(valor));
        }
    }

    resultado->setRowCount(temp->rowCount());
    resultado->setColumnCount(temp->columnCount());
    for (int i = 0; i < temp->rowCount(); ++i) {
        for (int j = 0; j < temp->columnCount(); ++j) {
            resultado->setItem(i, j, temp->takeItem(i, j));
        }
    }
    delete temp;
}

void GestorMatrices::copiarTabla(QTableWidget *tabla1, QTableWidget *tabla2)
{
    int filas1 = tabla1->rowCount();
    int columnas1 = tabla1->columnCount();

    tabla2->setRowCount(filas1);
    tabla2->setColumnCount(columnas1);

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            QString valor = tabla1->item(i, j) ? tabla1->item(i, j)->text() : "";
            if (tabla2->item(i, j)) {
                tabla2->item(i, j)->setText(valor);
            } else {
                tabla2->setItem(i, j, new QTableWidgetItem(valor));
            }
        }
    }
}
