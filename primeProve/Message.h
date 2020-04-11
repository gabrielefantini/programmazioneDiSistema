//
// Created by gabriele on 11/04/20.
//
#include <string>
#include <iostream>

#ifndef PRIMEPROVE_MESSAGE_H
#define PRIMEPROVE_MESSAGE_H


class Message {
    long id;
    char *data;
    int size;
private:
    static long globalid;

    char* mkMessage(int n) {
        std::string vowels = "aeiou";
        std::string consonants = "bcdfghlmnpqrstvz";
        char* m = new char[n+1];
        for (int i = 0; i < n; ++i) {
            m[i] = i%2 ? vowels[rand()%vowels.size()]:
                   consonants[rand()%consonants.size()];
        }
        m[n] = 0;
        return m;
    }

public:
    Message(); //costruttore di default
    Message(int n); //costruttore
    Message(const Message& source); //costruttore di copia
    Message(Message&& source);//costruttore di movimento
    Message& operator = (const Message& source);//operatore di assegnazione per copia
    Message& operator = (Message&& source);//operatore di assegnazione per movimento
    ~Message();//distruttore
    long getId() const;
    char* getData() const;
    int getSize() const;


};

std::ostream& operator<<(std::ostream& out, const Message& m);
#endif //PRIMEPROVE_MESSAGE_H
