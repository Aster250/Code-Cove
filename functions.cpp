#include <iostream>
#include <vector>
#include <ctime>
#include "classes.h"
#include "functions.h"


// question 2
bool hasFacture(const Client& c, const std::vector<Facture>& factures)
{
    for (const auto& f : factures)
    {
        if (f.getClient().getId() == c.getId())
        {
            return true;
        }
    }
    return false;
}

// question 3
void addProductToFacture(Facture& f, const Produit& p)
{
    std::vector<Produit> purchasedProducts = f.getPurchasedProducts();
    purchasedProducts.push_back(p);
    f.setPurchasedProducts(purchasedProducts);
}

// question 4
void modifyProductInFacture(Facture& f, int index, const Produit& p)
{
    std::vector<Produit> purchasedProducts = f.getPurchasedProducts();
    if (index >= 0 && index < static_cast<int>(purchasedProducts.size()))
    {
        purchasedProducts[index] = p;
        f.setPurchasedProducts(purchasedProducts);
    }
}

bool productExistsInFacture(const Facture& f, const Produit& p)
{
    const std::vector<Produit>& purchasedProducts = f.getPurchasedProducts();
    for (const Produit& p2 : purchasedProducts)
    {
        if (p2.getId() == p.getId())
        {
            return true;
        }
    }
    return false;
}

// question 5
void modifyClientInFacture(Facture& f, const Client& c)
{
    f.setClient(c);
}

// question 6
double calculateTotalCost(const Facture& f)
{
    double totalCost = 0.0;
    const std::vector<Produit>& purchasedProducts = f.getPurchasedProducts();
    for (const Produit& p : purchasedProducts)
    {
        totalCost += p.getUnitPrice() * p.getQuantity();
    }
    return totalCost;
}

// question 7
bool factureExists(const std::vector<Facture>& factures, const Facture& f)
{
    for (const Facture& facture : factures)
    {
        if (facture.getCode() == f.getCode())
        {
            return true;
        }
    }
    return false;
}

// question 8
bool factureExistsForClient(const std::vector<Facture>& factures, const Client& c)
{
    for (const Facture& facture : factures)
    {
        if (facture.getClient().getId() == c.getId())
        {
            return true;
        }
    }
    return false;
}

// question 9
void modifyFacturePayedState(std::vector<Facture>& factures, const std::string& code, bool payed)
{
    for (Facture& facture : factures)
    {
        if (facture.getCode() == code)
        {
            facture.setPayed(payed);
            break;
        }
    }
}

// question 10
void addFacture(std::vector<Facture>& factures, const Facture& f)
{
    factures.push_back(f);
}

// question 11
void printFactures(const std::vector<Facture>& factures)
{
    for (const Facture& facture : factures)
    {
        std::cout << "Facture code: " << facture.getCode() << std::endl;
        std::cout << "Associated client: " << facture.getClient().getFirstName() << " " << facture.getClient().getLastName() << std::endl;
        std::cout << "Creation date: " << facture.getCreationDate() << std::endl;
        std::cout << "Payed: " << (facture.isPayed() ? "yes" : "no") << std::endl;
        std::cout << "Purchased products:" << std::endl;
        for (const Produit& product : facture.getPurchasedProducts())
        {
            std::cout << " - " << product.getQuantity() << " x " << product.getName() << "    " << product.getUnitPrice()*product.getQuantity() << std::endl;
        }
        std::cout << std::endl;
    }
}

// question 12
std::vector<Client> getNonPayedFactureClients(const std::vector<Facture>& factures)
{
    std::vector<Client> clients;
    for (const Facture& facture : factures)
    {
        if (!facture.isPayed())
        {
            bool exists = false;
            for (const Client& client : clients)
            {
                if (client.getId() == facture.getClient().getId())
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
            {
                clients.push_back(facture.getClient());
            }
        }
    }
    return clients;
}

// question 13
std::vector<Facture> getTodayFactures(const std::vector<Facture>& factures)
{
    std::vector<Facture> todayFactures;
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    std::string today(buffer);

    for (const Facture& facture : factures)
    {
        if (facture.getCreationDate() == today)
        {
            todayFactures.push_back(facture);
        }
    }
    return todayFactures;
}

// question 14
void deleteFacture(std::vector<Facture>& factures, const std::string& code)
{
    for (auto it = factures.begin(); it != factures.end(); ++it)
    {
        if (it->getCode() == code)
        {
            factures.erase(it);
            break;
        }
    }
}
