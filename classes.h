#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <iostream>
#include <vector>

// Class to represent a product
class Produit
{
private:
    int id;
    std::string name;
    std::string description;
    float unitPrice;
    int quantity;

public:
    Produit(int id, std::string name, std::string description, float unitPrice, int quantity);
    void setId(int id);
    void setName(std::string name);
    void setDescription(std::string description);
    void setUnitPrice(float unitPrice);
    void setQuantity(int quantity);
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    float getUnitPrice() const;
    int getQuantity() const;
};

// Class to represent a client
class Client
{
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string address;

public:
    Client(int id, std::string firstName, std::string lastName, std::string address);
    Client();
    void setId(int id);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setAddress(std::string address);
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
};

// Class to represent a invoice
class Facture
{
private:
    std::string code;
    Client client;
    std::vector<Produit> purchasedProducts;
    std::string creationDate;
    bool payed;

public:
    Facture(std::string code, Client client, std::vector<Produit> purchasedProducts, std::string creationDate, bool payed);
    void setCode(std::string code);
    void setClient(Client client);
    void setPurchasedProducts(std::vector<Produit> purchasedProducts);
    void setCreationDate(std::string creationDate);
    void setPayed(bool payed);
    std::string getCode() const;
    Client getClient() const;
    std::vector<Produit> getPurchasedProducts() const;
    std::string getCreationDate() const;
    bool isPayed() const;
};

#endif

