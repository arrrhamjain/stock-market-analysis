#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Stock {
public:
    std::string name;
    double currentPrice;
    int quantity;

    Stock(std::string n, double price, int qty)
        : name(n), currentPrice(price), quantity(qty) {}
};

class Portfolio {
private:
    std::vector<Stock> stocks;

public:
    void addStock(const std::string& name, double price, int quantity) {
        for (auto& stock : stocks) {
            if (stock.name == name) {
                stock.quantity += quantity;
                stock.currentPrice = price;
                std::cout << "Updated existing stock: " << name << "\n";
                return;
            }
        }
        stocks.emplace_back(name, price, quantity);
        std::cout << "Added new stock: " << name << "\n";
    }

    void updateStockPrice(const std::string& name, double newPrice) {
        for (auto& stock : stocks) {
            if (stock.name == name) {
                stock.currentPrice = newPrice;
                std::cout << "Updated " << name << " to new price: $" << std::fixed << std::setprecision(2) << newPrice << "\n";
                return;
            }
        }
        std::cout << "Stock " << name << " not found in portfolio.\n";
    }

    void displayPortfolio() const {
        std::cout << "\nStock Portfolio:\n";
        std::cout << "------------------------------------------------\n";
        std::cout << std::left << std::setw(15) << "Name"
                  << std::setw(18) << "Current Price"
                  << std::setw(10) << "Quantity" << "\n";
        std::cout << "------------------------------------------------\n";
        std::cout << std::fixed << std::setprecision(2);
        for (const auto& stock : stocks) {
            std::cout << std::left << std::setw(15) << stock.name
                      << std::setw(18) << stock.currentPrice
                      << std::setw(10) << stock.quantity << "\n";
        }
        std::cout << "------------------------------------------------\n";
    }

    double totalValue() const {
        double total = 0.0;
        for (const auto& stock : stocks) {
            total += stock.currentPrice * stock.quantity;
        }
        return total;
    }
};

void displayMenu() {
    std::cout << "\nStock Market Application Menu:\n";
    std::cout << "1. Add Stock\n";
    std::cout << "2. Update Stock Price\n";
    std::cout << "3. Display Portfolio\n";
    std::cout << "4. Calculate Total Portfolio Value\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Portfolio myPortfolio;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error
            std::cin.ignore(10000, '\n'); // discard input
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name;
                double price;
                int quantity;

                std::cout << "Enter stock name: ";
                std::cin >> name;

                std::cout << "Enter current price: ";
                std::cin >> price;
                if (price < 0 || std::cin.fail()) {
                    std::cout << "Invalid price. Must be a non-negative number.\n";
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    break;
                }

                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                if (quantity < 0 || std::cin.fail()) {
                    std::cout << "Invalid quantity. Must be a non-negative integer.\n";
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    break;
                }

                myPortfolio.addStock(name, price, quantity);
                break;
            }
            case 2: {
                std::string name;
                double newPrice;

                std::cout << "Enter stock name to update: ";
                std::cin >> name;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                if (newPrice < 0 || std::cin.fail()) {
                    std::cout << "Invalid price. Must be a non-negative number.\n";
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                    break;
                }

                myPortfolio.updateStockPrice(name, newPrice);
                break;
            }
            case 3:
                myPortfolio.displayPortfolio();
                break;
            case 4:
                std::cout << "Total Portfolio Value: $" << std::fixed << std::setprecision(2)
                          << myPortfolio.totalValue() << "\n";
                break;
            case 5:
                std::cout << "Exiting the application.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
