#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Product{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
private:
    vector<Product*> products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProduct(){
        return products;
    }

    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart* cart;
public:

    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout <<"Shopping Cart Invoice:\n";
        for(auto p:cart->getProduct()){
            cout <<p->name<<" - $"<<p->price<<endl;
        }
        cout <<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart* cart;
public:

    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToDatabase(){
        cout << "Saving shopping cart to database..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToDatabase();

    return 0;
}