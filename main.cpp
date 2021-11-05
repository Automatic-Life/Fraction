#include "Fraction.h"
#include <iostream>
#include <string>
#include <vector>

Fraction create()
{
    system("cls");

    int numerator;
    while (true)
    {
        std::cout << "Input a numerator\n";
        std::cin >> numerator;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else break;

    }
    std::cin.ignore(32767, '\n');

    int denominator;
    do
    {
        std::cout << "Input a denominator (>0)\n";
        std::cin >> denominator;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }

    } while (denominator <=0);
    std::cin.ignore(32767, '\n');

    return Fraction(numerator, denominator);
}

void rewrite(std::vector<Fraction>& vars)
{
    system("cls");
    int number = 0;
    do
    {
        if ((number < 0) || (number >= vars.size()))
            {std::cout << "Number " << number << " is not exist!\n"; std::cout << std::endl;}
        for (int i = 0; i < vars.size(); ++i)
        {
            std::cout << i << ": " << vars[i] << "   ";
        }
        std::cout << std::endl;
        std::cout << "Type a number of fraction, which you want to rewrite\n";
        std::cin >> number;
        if (std::cin.fail())                //
        {                                   // Повторяющейся участок кода,
            std::cin.clear();               // необходимо заключить в функцию.
            std::cin.ignore(32767, '\n');   //
            continue;
        }
        std::cin.ignore(32767, '\n');

    } while ((number < 0) || (number >= vars.size()));

    vars[number] = create();
}

void calculate (std::vector<Fraction>& vars) // Обработка пользовательского ввода отсутствует
{
    system("cls");
    int first = 0;
    do
    {
        if ((first < 0) || (first >= vars.size()))
            {std::cout << "Number " << first << " is not exist!\n"; std::cout << std::endl;}    // Очевидное дублирование кода
        for (int i = 0; i < vars.size(); ++i)                                                   // в этой функции
        {
            std::cout << i << ": " << vars[i] << "   ";
        }
        std::cout << std::endl;
        std::cout << "Choose a first number\n";
        std::cin >> first;


    } while ((first < 0) || (first >= vars.size()));

    int second = 0;
    do
    {
        if ((second < 0) || (second >= vars.size()))
            {std::cout << "Number " << second << " is not exist!\n"; std::cout << std::endl;}
        for (int i = 0; i < vars.size(); ++i)
        {
            std::cout << i << ": " << vars[i] << "   ";
        }
        std::cout << std::endl;
        std::cout << "Choose a second number\n";
        std::cin >> second;


    } while ((second < 0) || (second >= vars.size()));
     std::cin.ignore(32767, '\n');

    std::string operation;
    do
    {
        std::cout << std::endl;
        std::cout << "Choose a operation (+,*,/)\n";
        std::cin >> operation;

    } while ((operation != "+") && (operation != "*") && (operation != "/"));

    if (operation == "+") {std::cout << vars[first] + vars[second] << '\n';}
    else if (operation == "*") {std::cout << vars[first] * vars[second] << '\n';}
    else if (operation == "/") {std::cout << vars[first] / vars[second] << '\n';}

}

int main()
{
    std::vector<Fraction> vars;

    std::string choice;

    //main loop
    while (true)
    {

        for (int i = 0; i < vars.size(); ++i)
        {
            std::cout << i << ": " << vars[i] << "   ";
        }
        std::cout << std::endl;
        std::cout << "Type \"create\" or \"cr\" to create a new fraction\n";
        std::cout << "Type \"rewrite\" or \"re\" to rewrite a existing fraction\n";
        std::cout << "Type \"calculate\"  or \"ca\" to calculate fractions\n";
        std::cout << "Type \"cls\" to clean a screen\n";
        std::cout << "Type \"exit\" to exit programm\n";

        std::getline(std::cin, choice);
        std::cout << std::endl;

        if ((choice == "create") || (choice == "cr") ) {vars.push_back(create());}
        if ((choice == "rewrite") || (choice == "re"))
            {
                if (vars.size() == 0) {std::cout << "It's nothing to rewrite!\n";}
                else rewrite(vars);
            }
        if ((choice == "calculate") || (choice == "ca"))
            {
                if (vars.size() == 0) {std::cout << "It's nothing to calculate!\n";}
                else calculate(vars);
            }

        if (choice == "cls") {system("cls");}
        if (choice == "exit") {break;}

    }




    return 0;
}
