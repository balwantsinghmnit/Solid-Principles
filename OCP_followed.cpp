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
    virtual void saveToDatabase(ShoppingCart* cart) = 0;
};

class MongoDB:public ShoppingCartStorage {
public:
    void saveToDatabase(ShoppingCart* cart){
        cout << "Saving shopping cart to MongoDB database..."<<endl;
    }
};

class SqlDB:public ShoppingCartStorage {
public:
    void saveToDatabase(ShoppingCart* cart){
        cout << "Saving shopping cart to SQL database..."<<endl;
    }
};

class FileDB:public ShoppingCartStorage {
public:
    void saveToDatabase(ShoppingCart* cart){
        cout << "Saving shopping cart to File..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* Mongo = new MongoDB();
    ShoppingCartStorage* sql = new SqlDB();
    ShoppingCartStorage* file_db = new FileDB();

    sql->saveToDatabase(cart);
    Mongo->saveToDatabase(cart);
    file_db->saveToDatabase(cart);

    return 0;
}