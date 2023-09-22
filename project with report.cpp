
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX_PRODUCTS = 100;
const int MAX_CUSTOMERS = 100;
const int MAX_SALES = 100;

struct Product {
    string name;
    double price;
    int quantity;
    string expiryDate;
};

struct Customer {
    string name;
    string address;
};

struct Sale {
    Product product;
    Customer customer;
    int quantity;
    int customerIndex;
    int productIndex;
};

Product products[MAX_PRODUCTS];
Customer customers[MAX_CUSTOMERS];
Sale sales[MAX_SALES];
int productCount = 0;
int customerCount = 0;
int saleCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        std::cout << "Maximum number of products reached." << std::endl;
        return;
    }

    Product newProduct;
    std::cout << "\nEnter product name: ";
    std::cin.ignore();
    std::getline(std::cin, newProduct.name);
    std::cout << "Enter product price: ";
    std::cin >> newProduct.price;
    std::cout << "Enter product quantity: ";
    std::cin >> newProduct.quantity;
    std::cout << "Enter product expiry date: ";
    std::cin.ignore();
    std::getline(std::cin, newProduct.expiryDate);

    products[productCount++] = newProduct;
    std::cout << "\nProduct added successfully.\n" << std::endl;
}

void deleteProduct() {
    if (productCount <= 0) {
        std::cout << "No products available." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter product index to delete (0-" << productCount - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < productCount) {
        for (int i = index; i < productCount - 1; ++i) {
            products[i] = products[i + 1];
        }
        productCount--;
        std::cout << "Product deleted successfully." << std::endl;
    } else {
        std::cout << "Invalid product index." << std::endl;
    }
}

void updateProduct() {
    if (productCount <= 0) {
        std::cout << "No products available." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter product index to update (0-" << productCount - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < productCount) {
        Product& product = products[index];
        std::cout << "Enter updated product name: ";
        std::cin.ignore();
        std::getline(std::cin, product.name);
        std::cout << "Enter updated product price: ";
        std::cin >> product.price;
        std::cout << "Enter updated product quantity: ";
        std::cin >> product.quantity;
        std::cout << "Enter updated product expiry date: ";
        std::cin.ignore();
        std::getline(std::cin, product.expiryDate);
        std::cout << "Product updated successfully." << std::endl;
    } else {
        std::cout << "Invalid product index." << std::endl;
    }
}

void displayProducts() {
    if (productCount <= 0) {
        std::cout << "No products available." << std::endl;
        return;
    }

    std::cout << "Products List:" << std::endl;
    for (int i = 0; i < productCount; ++i) {
        std::cout << "Product #" << i << std::endl;
        std::cout << "Name: " << products[i].name << std::endl;
        std::cout << "Price: " << products[i].price << std::endl;
        std::cout << "Quantity: " << products[i].quantity << std::endl;
        std::cout << "Expiry Date: " << products[i].expiryDate << std::endl;
        std::cout << std::endl;
    }
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        std::cout << "Maximum number of customers reached." << std::endl;
        return;
    }

    Customer newCustomer;
    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, newCustomer.name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, newCustomer.address);

    customers[customerCount++] = newCustomer;
    std::cout << "Customer added successfully." << std::endl;
}

void deleteCustomer() {
    if (customerCount <= 0) {
        std::cout << "No customers available." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter customer index to delete (0-" << customerCount - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < customerCount) {
        for (int i = index; i < customerCount - 1; ++i) {
            customers[i] = customers[i + 1];
        }
        customerCount--;
        std::cout << "Customer deleted successfully." << std::endl;
    } else {
        std::cout << "Invalid customer index." << std::endl;
    }
}

void updateCustomer() {
    if (customerCount <= 0) {
        std::cout << "No customers available." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter customer index to update (0-" << customerCount - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < customerCount) {
        Customer& customer = customers[index];
        std::cout << "Enter updated customer name: ";
        std::cin.ignore();
        std::getline(std::cin, customer.name);
        std::cout << "Enter updated customer address: ";
        std::getline(std::cin, customer.address);
        std::cout << "Customer updated successfully." << std::endl;
    } else {
        std::cout << "Invalid customer index." << std::endl;
    }
}

void displayCustomers() {
    if (customerCount <= 0) {
        std::cout << "No customers available." << std::endl;
        return;
    }

    std::cout << "Customers List:" << std::endl;
    for (int i = 0; i < customerCount; ++i) {
        std::cout << "Customer #" << i << std::endl;
        std::cout << "Name: " << customers[i].name << std::endl;
        std::cout << "Address: " << customers[i].address << std::endl;
        std::cout << std::endl;
    }
}

void addSale() {
    if (saleCount >= MAX_SALES) {
        std::cout << "Maximum number of sales reached." << std::endl;
        return;
    }

    Sale newSale;
    std::cout << "Enter customer index (0-" << customerCount - 1 << "): ";
    std::cin >> newSale.customerIndex;
    std::cout << "Enter productindex (0-" << productCount - 1 << "): ";
    std::cin >> newSale.productIndex;
    std::cout << "Enter quantity: ";
    std::cin >> newSale.quantity;
    
    sales[saleCount++] = newSale;
    std::cout << "Sale added successfully." << std::endl;
}

void displaySales() {
    if (saleCount <= 0) {
        std::cout << "No sales available." << std::endl;
        return;
    }

    std::cout << "Sales List:" << std::endl;
    for (int i = 0; i < saleCount; ++i) {
        const Sale& sale = sales[i];
        std::cout << "Sale #" << i << std::endl;
        std::cout << "Customer Name: " << customers[sale.customerIndex].name << std::endl;
        std::cout << "Product Name: " << products[sale.productIndex].name << std::endl;
        std::cout << "Quantity: " << sale.quantity << std::endl;
        std::cout << "Total Price: " << products[sale.productIndex].price * sale.quantity << std::endl;
        
        std::cout << std::endl;
    }
}

void generateReport() {
    ofstream out;
    out.open("report.txt");
    if (!out) {
        cout << "Failed to create the report file." << std::endl;
        return;
    }

    out << "----------------------------------------------" << std::endl;
    out << "Nature's Glow:Eco Beauty Products Store Report" << std::endl;
    out << "----------------------------------------------" << std::endl;
    out << std::endl;

    // Products
    out << "Products List:" << std::endl;
    out << std::endl;
    for (int i = 0; i < productCount; ++i) {
        out << "Product #" << i << std::endl;
        out << "Name: " << products[i].name << std::endl;
        out << "Price: " << products[i].price << std::endl;
        out << "Quantity: " << products[i].quantity << std::endl;
        out << "Expiry Date: " << products[i].expiryDate << std::endl;
        out << std::endl;
    }
    out << std::endl;

    // Customers
     out<< "Customers List:" << std::endl;
    out << std::endl;
    for (int i = 0; i < customerCount; ++i) {
        out << "Customer #" << i << std::endl;
        out << "Name: " << customers[i].name << std::endl;
        out << "Address: " << customers[i].address << std::endl;
        out << std::endl;
    }
    out << std::endl;

    // Sales
    out << "Sales List:" << std::endl;
    out << std::endl;
    for (int i = 0; i < saleCount; ++i) {
        const Sale& sale = sales[i];
        out << "Sale #" << i << std::endl;
        out << "Customer Name: " << customers[sale.customerIndex].name << std::endl;
        out << "Product Name: " << products[sale.productIndex].name << std::endl;
        out << "Quantity: " << sale.quantity << std::endl;
        out << "Total Price: " << products[sale.productIndex].price * sale.quantity << std::endl;
        out << std::endl;
    }

    out.close();
    cout << "Report generated successfully." << std::endl;
}

int main() {
    int choice;
    while (true) {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Nature's Glow:Eco Beauty Products Store" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "\n1. Add Product" << std::endl;
        std::cout << "2. Delete Product" << std::endl;
        std::cout << "3. Update Product" << std::endl;
        std::cout << "4. Display Products" << std::endl;
        std::cout << "5. Add Customer" << std::endl;
        std::cout << "6. Delete Customer" << std::endl;
        std::cout << "7. Update Customer" << std::endl;
        std::cout << "8. Display Customers" << std::endl;
        std::cout << "9. Add Sale" << std::endl;
        std::cout << "10. Display Sales" << std::endl;
        std::cout << "11. Generate Report" << std::endl;
        std::cout << "12. Exit" << std::endl;
        std::cout << "\nEnter your choice: " ;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                addCustomer();
                break;
            case 6:
                deleteCustomer();
                break;
            case 7:
                updateCustomer();
                break;
            case 8:
                displayCustomers();
                break;
            case 9:
                addSale();
                break;
            case 10:
                displaySales();
                break;
            case 11:
                generateReport();
                break;
            case 12:
                std::cout << "Exiting program..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }
}

