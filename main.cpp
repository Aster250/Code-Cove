#include <iostream>
#include <vector>
#include <ctime>
#include "classes.h"
#include "functions.h"


// tests for each question
int main()
{
    // question 2
    std::cout << "Q2:" << std::endl;
    std::cout << "=============================" << std::endl;
    Client c1(1, "John", "Doe", "123 Main St.");
    Client c2(2, "Jane", "Doe", "456 Main St.");
    Client c3(3, "Jack", "Smith", "789 Main St.");

    Facture f1("F001", c1, {}, "2022-12-27", true);
    Facture f2("F002", c2, {}, "2022-02-01", false);
    Facture f3("F003", c3, {}, "2022-12-27", true);
    
    std::vector<Facture> factures = {f1, f2, f3};

    bool hasFactureOnName1 = hasFacture(c1, factures);
    bool hasFactureOnName2 = hasFacture(c2, factures);
    bool hasFactureOnName3 = hasFacture(c3, factures);

    if (hasFactureOnName1)
    {
        std::cout << "Client 1 has a facture on their name." << std::endl;
    }
    else
    {
        std::cout << "Client 1 does not have a facture on their name." << std::endl;
    }

    if (hasFactureOnName2)
    {
        std::cout << "Client 2 has a facture on their name." << std::endl;
    }
    else
    {
        std::cout << "Client 2 does not have a facture on their name." << std::endl;
    }

    if (hasFactureOnName3)
    {
        std::cout << "Client 3 has a facture on their name." << std::endl;
    }
    else
    {
        std::cout << "Client 3 does not have a facture on their name." << std::endl;
    }

    // question 3
    std::cout <<  std::endl;
    std::cout << "Q3:" << std::endl;
    std::cout << "=============================" << std::endl;
    Facture f("F001", c1, {}, "2022-01-01", false);

    Produit p1(1, "Product 1", "Description 1", 10.0, 5);
    Produit p2(2, "Product 2", "Description 2", 20.0, 10);

    addProductToFacture(f, p1);
    addProductToFacture(f, p2);

    // Print the purchased products
    //std::cout << f << std::endl;

    std::vector<Produit> purchasedProducts = f.getPurchasedProducts();
    for (const Produit& p : purchasedProducts)
    {
        std::cout << p.getName() << std::endl;
    }

    // question 4
    std::cout <<  std::endl;
    std::cout << "Q4:" << std::endl;
    std::cout << "=============================" << std::endl;
    modifyProductInFacture(f, 1, Produit(3, "Product 3", "Description 3", 50.0, 25));
    //std::cout << f << std::endl;
    purchasedProducts = f.getPurchasedProducts();
    for (const Produit& p : purchasedProducts)
    {
        std::cout << p.getName() << std::endl;
    }

    std::cout << std::boolalpha << productExistsInFacture(f, p1) << std::endl;
    std::cout << std::boolalpha << productExistsInFacture(f, p2) << std::endl;

    // question 5
    std::cout <<  std::endl;
    std::cout << "Q5:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    modifyClientInFacture(f, c2);
    std::cout << f.getClient().getFirstName() << std::endl;

    // question 6
    std::cout <<  std::endl;
    std::cout << "Q6:" <<  std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << calculateTotalCost(f) << std::endl;

    // question 7
    std::cout <<  std::endl;
    std::cout << "Q7:" <<  std::endl;
    std::cout << "=============================" << std::endl;
    Facture f4("F004", c1, {p1, p2}, "2022-03-01", true);

    std::cout << std::boolalpha << factureExists(factures, f1) << std::endl;
    std::cout << std::boolalpha << factureExists(factures, f4) << std::endl;

    // question 8
    std::cout <<  std::endl;
    std::cout << "Q8:" <<  std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << std::boolalpha << factureExistsForClient(factures, c1) << std::endl;
    std::cout << std::boolalpha << factureExistsForClient(factures, c3) << std::endl;

    // question 9
    std::cout <<  std::endl;
    std::cout << "Q9:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    modifyFacturePayedState(factures, "F001", false);
    //modifyFacturePayedState(factures, "F002", true);

    for (const Facture& f : factures)
    {
        std::cout << f.getCode() << " " << f.isPayed() << std::endl;
    }

    // question 10
    std::cout <<  std::endl;
    std::cout << "Q10:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    addFacture(factures, f4);
    for (const Facture& f : factures)
    {
        std::cout << f.getCode() << std::endl;
    }

    // question 11
    std::cout <<  std::endl;
    std::cout << "Q11:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    printFactures(factures);

    // question 12
    std::cout <<  std::endl;
    std::cout << "Q12:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    std::vector<Client> nonPayedFactureClients = getNonPayedFactureClients(factures);
    for (const Client& client : nonPayedFactureClients)
    {
        std::cout << client.getFirstName() << " " << client.getLastName() << std::endl;
    }

    // question 13
    std::cout <<  std::endl;
    std::cout << "Q13:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    std::vector<Facture> todayFactures = getTodayFactures(factures);
    printFactures(todayFactures);

    // question 14
    std::cout <<  std::endl;
    std::cout << "Q14:" <<  std::endl;
    std::cout << "=============================" << std::endl;

    deleteFacture(factures, "F002");
    printFactures(factures);
    
    return 0;
}
