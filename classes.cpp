#include "classes.h"

// Constructor for Produit class
Produit::Produit(int id, std::string name, std::string description, float unitPrice, int quantity)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->unitPrice = unitPrice;
    this->quantity = quantity;
}

// Setters for Produit class
void Produit::setId(int id)
{
    this->id = id;
}

void Produit::setName(std::string name)
{
    this->name = name;
}

void Produit::setDescription(std::string description)
{
    this->description = description;
}

void Produit::setUnitPrice(float unitPrice)
{
    this->unitPrice = unitPrice;
}

void Produit::setQuantity(int quantity)
{
    this->quantity = quantity;
}

// Getters for Produit class
int Produit::getId() const
{
    return id;
}

std::string Produit::getName() const
{
    return name;
}

std::string Produit::getDescription() const
{
    return description;
}

float Produit::getUnitPrice() const
{
    return unitPrice;
}

int Produit::getQuantity() const
{
    return quantity;
}

// Constructor for Client class
Client::Client(int id, std::string firstName, std::string lastName, std::string address)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
}

Client::Client()
{
    this->id = -1;
    this->firstName = "";
    this->lastName = "";
    this->address = "";
}

// Setters for Client class
void Client::setId(int id)
{
    this->id = id;
}

void Client::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Client::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Client::setAddress(std::string address)
{
    this->address = address;
}

// Getters for Client class
int Client::getId() const
{
    return id;
}

std::string Client::getFirstName() const
{
    return firstName;
}

std::string Client::getLastName() const
{
    return lastName;
}

std::string Client::getAddress() const
{
    return address;
}

// Constructor for Facture class
Facture::Facture(std::string code, Client client, std::vector<Produit> purchasedProducts, std::string creationDate, bool payed)
{
    this->code = code;
    this->client = client;
    this->purchasedProducts = purchasedProducts;
    this->creationDate = creationDate;
    this->payed = payed;
}

// Setters for Facture class
void Facture::setCode(std::string code)
{
    this->code = code;
}

void Facture::setClient(Client client)
{
    this->client = client;
}

void Facture::setPurchasedProducts(std::vector<Produit> purchasedProducts)
{
    this->purchasedProducts = purchasedProducts;
}

void Facture::setCreationDate(std::string creationDate)
{
    this->creationDate = creationDate;
}

void Facture::setPayed(bool payed)
{
    this->payed = payed;
}

// Getters for Facture class
std::string Facture::getCode() const
{
    return code;
}

Client Facture::getClient() const
{
    return client;
}

std::vector<Produit> Facture::getPurchasedProducts() const
{
    return purchasedProducts;
}

std::string Facture::getCreationDate() const
{
    return creationDate;
}


// Getters for Facture class
bool Facture::isPayed() const
{
    return payed;
}
