//
// Created by victo on 09/01/2023.
//

#include <iostream>;

#include <iostream>

// Clase "Punto" que representa un punto en el plano
class Punto {
public:
    // Constructor que inicializa las coordenadas x e y
    Punto(double x, double y) : x_(x), y_(y) {}

    // Métodos para obtener el valor de x e y
    double x() const { return x_; }
    double y() const { return y_; }

private:
    // Coordenadas x e y del punto
    double x_, y_;
};

// Clase "Nodo" cuyo campo de valor es un objeto de la clase "Punto"
class Nodo {
public:
    // Constructor que inicializa el valor del nodo con un objeto de la clase "Punto"
    Nodo(const Punto& valor) : valor_(valor) {}

    // Método para obtener el valor del nodo
    const Punto& valor() const { return valor_; }

private:
    // Valor del nodo (un objeto de la clase "Punto")
    Punto valor_;
};

int main() {
    // Crea un objeto de la clase "Punto" con coordenadas (1, 2)
    Punto p(1, 2);

    // Crea un objeto de la clase "Nodo" con el punto creado anteriormente como valor
    Nodo n(p);

    // Imprime las coordenadas del punto almacenado en el nodo
    std::cout << "Coordenadas del punto: (" << n.valor().x() << ", " << n.valor().y() << ")" << std::endl;

    return 0;
}
