#ifndef CONTACT_H
#define CONTACT_H

// #include <string>
//
using namespace std;

class Contact {
    private:
        string name;
        string phoneNumber;

    public:
        Contact();
        Contact(string user,string num);

        void setName(string user);
        void setNumber(string number);

        string getName() { return name; }
        string getNumber() { return phoneNumber; }
};

#endif
