#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <ctime>
#include "classes.h"


// question 2
bool hasFacture(const Client& c, const std::vector<Facture>& factures);

// question 3
void addProductToFacture(Facture& f, const Produit& p);

// question 4
void modifyProductInFacture(Facture& f, int index, const Produit& p);

bool productExistsInFacture(const Facture& f, const Produit& p);

// question 5
void modifyClientInFacture(Facture& f, const Client& c);

// question 6
double calculateTotalCost(const Facture& f);

// question 7
bool factureExists(const std::vector<Facture>& factures, const Facture& f);

// question 8
bool factureExistsForClient(const std::vector<Facture>& factures, const Client& c);

// question 9
void modifyFacturePayedState(std::vector<Facture>& factures, const std::string& code, bool payed);

// question 10
void addFacture(std::vector<Facture>& factures, const Facture& f);

// question 11
void printFactures(const std::vector<Facture>& factures);
// question 12
std::vector<Client> getNonPayedFactureClients(const std::vector<Facture>& factures);

// question 13
std::vector<Facture> getTodayFactures(const std::vector<Facture>& factures);

// question 14
void deleteFacture(std::vector<Facture>& factures, const std::string& code);

#endif
