#include<iostream>
using namespace std;

class Database{
public:
    virtual void save(string data)=0;
};

class MySQLDatabase:public Database {
public:
    void save(string data){
        cout <<"Executing SQL Query: INSERT INTO users VALUES('"<<data<<"');"<<endl;
    }
};

class MongoDBDatabase:public Database {
public:
    void save(string data){
        cout <<"Executing MongoDB Function: db.users.insert({name '"<<data<<"');"<<endl;
    }
};

class UserService {
private:
    Database* db;

public:
    UserService(Database* database){
        db = database;
    }
    void storeUser(string user){
        db->save(user);
    }
};

int main(){
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    UserService service2(&mongodb);

    service1.storeUser("Aditya");
    service2.storeUser("Raj");
    return 0;
}