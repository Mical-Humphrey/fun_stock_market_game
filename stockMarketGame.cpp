#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <iomanip>

int main()
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<double> distribution(-10.00, 10.00);

    double stock1 {100.00};
    double stock2 {100.00};
    double stock3 {100.00};
    double userMoneyStart {100.00};
    double userMoneyEnd {};
    double stockBuy {};
    double stockSell {};
    int roundNumber {0};
    char userInput {};

    while (userInput != 'q') {
        roundNumber++;
        std::cout << "\nYou have $" << userMoneyStart << ". Choose a stock to hold.\n";
        std::cout << "Select stock 'a' 'b' or 'c': ";
        std::cin >> userInput;
        if (userInput == 'q') {
            std::cout << "Quit!";
            return 0;
        }

        if (userInput == 'a')
            stockBuy = stock1;
        else if (userInput == 'b')
            stockBuy = stock2;
        else if (userInput == 'c')
            stockBuy = stock3;
        else
            break;

        for (int i = 0; i < 5; i++) {
            double change1 = distribution(generator);
            stock1 += change1;
            double change2 = distribution(generator);
            stock2 += change2;
            double change3 = distribution(generator);
            stock3 += change3;

        std::cout << std::fixed << std::setprecision(2)
            << " A: $" << stock1
            << " B: $" << stock2
            << " C: $" << stock3 
            << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (userInput == 'a')
            stockSell = stock1 - stockBuy;
        else if (userInput == 'b')
            stockSell = stock2 - stockBuy;
        else if (userInput == 'c')
            stockSell = stock3 - stockBuy;

        userMoneyEnd = userMoneyStart + stockSell;

        std::cout << "\n" << std::endl;
        std::cout << "Round " << roundNumber << std::endl;
        std::cout << "You started with $" << userMoneyStart << " and ended with $" << userMoneyEnd << std::endl;

        if (stockSell < 0)
            std::cout << "You lost money: -$" << -(stockSell) << std::endl;
        else
            std::cout << "You made money: +$" << stockSell << std::endl;

        userMoneyStart = userMoneyEnd; // reset the total for the next round
          
    }
    if (userMoneyEnd < 100)
        std::cout << "Tough Luck, you started with $100 and ended with " << userMoneyEnd;
    else
        std::cout << "Awesome job, you started with $100 and ended with: " << userMoneyEnd;

}