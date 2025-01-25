#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer {
private:
    int id;
    QString name;
    int balance;
    int totalSpent;
    QString phone;
    int discount;

public:
    // Constructor
    Customer(int id, const QString &name, int balance, int totalSpent, const QString &phone, int discount);

    // Getters
    int getId() const;
    QString getName() const;
    int getBalance() const;
    int getTotalSpent() const;
    QString getPhone() const;
    int getDiscount() const;

    // Setters
    void setId(int id);
    void setName(const QString &name);
    void setBalance(int balance);
    void setTotalSpent(int totalSpent);
    void setPhone(const QString &phone);
    void setDiscount(int discount);
};

#endif // CUSTOMER_H
