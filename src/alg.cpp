// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    // Приводим к double, чтобы деление было точным
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    // Для exp первый член при n=0 равен 1
    for (uint16_t n = 0; n < count; n++) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        double item = pown(x, 2*n - 1) / static_cast<double>(fact(2*n - 1));
        if (n % 2 == 0) {
            sum -= item;
        } else {
            sum += item;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        double item = pown(x, 2*n - 2) / static_cast<double>(fact(2*n - 2));
        if (n % 2 == 0) {
            sum -= item;
        } else {
            sum += item;
        }
    }
    return sum;
}
