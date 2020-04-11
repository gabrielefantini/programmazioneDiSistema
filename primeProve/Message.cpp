//
// Created by gabriele on 11/04/20.
//
#include <string>
#include "Message.h"

//implementazione dei costruttori
Message::Message(): id(-1), data(""), size(0){
    std::cout<<"Costruttore di Defaul"<<std::endl;
};
Message::Message(int n): id(globalid), data(mkMessage(n)), size(n) {
    std::cout<<"Costruttore"<<std::endl;
    globalid++;
}
Message::Message(const Message &source) {
    std::cout<<"Costruttore di Copia"<<std::endl;
    int size = source.getSize();
    this->size = size;
    this->data = new char[size];
    for (int i = 0; i < size; ++i) {
        this->data[i]=source.getData()[i];
    }
    this->id=globalid;
    globalid++;
}
//implementazione costruttore di movimento..nb! viene invocato solo utilizzando std::move(m1)
Message::Message(Message &&source) {
    std::cout<<"Costruttore di Movimento"<<std::endl;
    this->size = source.getSize();
    this->data = source.getData();
    source.data = nullptr;
    this->id = globalid;
    globalid++;
};
//implementazione operatore di assegnazione per copia
Message& Message::operator=(const Message &source) {
    std::cout<<"Operatore di Assegnazione per copia"<<std::endl;
    if (this != &source) {
        delete[] this -> data;
        this -> data = nullptr;
        //una volta liberato l'oggetto dai vecchi valori, copio i nuovi
        this->size = source.size;
        this->data = new char[size];
        for (int i = 0; i < size; ++i) {
            this->data[i]=source.getData()[i];
        }
    }
    return *this;
}
//implementazione operatore di assegnazione per movimento
Message& Message::operator = (Message&& source){
    std::cout<<"Operatore di Assegnazione per movimento"<<std::endl;
    if(this != &source){
        delete[] this->data;
        this -> data = nullptr;
        //una volta liberato l'oggetto dai vecchi valori, copio i nuovi
        this->size = source.size;
        this->data = new char[size];
        for (int i = 0; i < size; ++i) {
            this->data[i]=source.getData()[i];
        }
        //una volta copiati svuoto il vecchio oggetto
        source.data = nullptr;
    }
    return *this;
}
//implemento il distruttore
Message::~Message() {
    std::cout<<"Distruttore"<<std::endl;
    delete[] data;
}
long Message::globalid = 0;
long Message::getId() const { return this->id;};
char* Message::getData() const { return this->data;};
int Message::getSize() const { return this-> size;}

std::ostream& operator<<(std::ostream& out, const Message& m){
    out << "[id:" + std::to_string(m.getId()) + "] ";
    out << "[size:" + std::to_string(m.getSize()) + "] ";
    out << std::string("[getData:");
    char* buff = m.getData();
    for (int i = 0; i < m.getSize(); ++i) {
        out << buff[i];
    }
    out << std::string("]");
    return out;
}