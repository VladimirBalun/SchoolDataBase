#ifndef DATABASE_H
#define DATABASE_H


class DataBase
{
public:
    DataBase* getInstance();
    ~DataBase();
private:
    DataBase();
    DataBase dataBase;
};

#endif // DATABASE_H
