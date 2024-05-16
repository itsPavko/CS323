#pragma once
#include <string>
#include "ExpirationDateException.h"

class Product {
private:
    string name;
    float price;
    int expirationDate;

public:
    Product(const string& name, float price, int expirationDate)
        : name(name), price(price), expirationDate(expirationDate) {
        if (expirationDate < 0) {
            throw ExpirationDateException();
        }
    }

    const string& getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    int getExpirationDate() const {
        return expirationDate;
    }
};

