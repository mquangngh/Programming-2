/*
 * *
 * Program author
 * Name: Quang Nguyen
 * Student number: 152276070
 * UserID: phqung
 * E-Mail: quang.h.nguyen@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *
 * */
#include "cli.hh"
#include "hospital.hh"
#include <string>

const std::string PROMPT = "Hosp> ";


int main()
{
    Hospital* hospital = new Hospital();
    Cli cli(hospital, PROMPT);
    while ( cli.exec() ){}

    delete hospital;
    return EXIT_SUCCESS;
}
