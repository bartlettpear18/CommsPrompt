#include <iostream>
#include "Contact.h"

using namespace std;

Contact::Contact() {}

Contact::Contact(string user, string number): name(user), phoneNumber(number) {}

void Contact::setName(string user) {
    name = user;
}

void Contact::setNumber(string number) {
    phoneNumber = number;
}
