#include "customer.h"

// Constructor
Customer::Customer(int id, const QString &name, int balance, int totalSpent, const QString &phone, int discount)
    : id(id), name(name), balance(balance), totalSpent(totalSpent), phone(phone), discount(discount) {}

// Getters
int Customer::getId() const { return id; }
QString Customer::getName() const { return name; }
int Customer::getBalance() const { return balance; }
int Customer::getTotalSpent() const { return totalSpent; }
QString Customer::getPhone() const { return phone; }
int Customer::getDiscount() const { return discount; }

// Setters
void Customer::setId(int id) { this->id = id; }
void Customer::setName(const QString &name) { this->name = name; }
void Customer::setBalance(int balance) { this->balance = balance; }
void Customer::setTotalSpent(int totalSpent) { this->totalSpent = totalSpent; }
void Customer::setPhone(const QString &phone) { this->phone = phone; }
void Customer::setDiscount(int discount) { this->discount = discount; }
