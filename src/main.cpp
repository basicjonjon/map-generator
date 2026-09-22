/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:05:46 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/22 17:08:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"
#include "BacktrackingMaze.hpp"

void error(std::string msg)
{
    std::cerr << BRED << "ERROR";
    if (!msg.empty())
    {
        std::cerr << ": " << msg;
    }
    std::cerr << NC << std::endl;
    exit(1);
}

int isNumber(std::string arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (!isdigit(arg[i]))
            return (0);
    return (1);
}

void title()
{
    std::cout << "[0;34m       [0;37m [0;34m       [0;37m [0;34m       [0;37m      [0;34m       [0;37m [0;34m       [0;37m [0;34m       [0;37m [0;34m       [0;37m [0;34m    [0;37m [0;34m       [0;37m [0;34m    [0;37m [0;34m       [0;37m [0;34m    [0m" << std::endl;
    std::cout << "[0;94;44m▓▀[0;34;44m░[0;34m▄[0;94;44m▓▀[0;34;44m░[0;37m [0;94m▄[0;34m█[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m [0;94;44m▓▀[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m      [0;94m▄[0;94;44m▀[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34;44m░[0;37m [0;94m▄[0;94;44m▀[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m [0;94;44m▓▀[0;34;44m░[0;34m▄[0;94m▄▄[0;34m▄[0;37m [0;94m▄[0;94;44m▀[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m [0;94;44m▓▀[0;34;44m░[0;34m▄[0;37m [0;94m▄[0;34m█[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m [0;94;44m▓▀[0;34;44m░[0;34m▄[0;37m [0;94m▄[0;94;44m▀[0;34;44m░[0;34m▀[0;94;44m▓▀[0;34m▄[0;37m [0;94;44m▓▀[0;34;44m░[0;34m▄[0m" << std::endl;
    std::cout << "[0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;34m▄▄▄▄[0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;94;44m▒[0;34m█[0;34;44m▒[0;37m      [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m▀▀▀▀[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m▀▀▀▀[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;37m [0;34m▄▄▄▄[0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0;94;44m▒[0;34m█[0;34;44m▒[0;37m [0;94;44m▒[0;34m█[0;34;44m▒[0;34m [0m" << std::endl;
    std::cout << "[0;94;44m░[0;34;44m▄▓[0;34m [0;94;44m░[0;34;44m▄▓[0;37m [0;94;44m░[0;34m█▄▄[0;94;44m░[0;34;44m▄▓[0;37m [0;94;44m░[0;34m█[0;34;44m▓[0;34m▄[0;94;44m░[0;34m█▀[0;37m      [0;34m ▀▀▀[0;94;44m░[0;34m█[0;34;44m▓[0;37m [0;34m▀[0;34;44m▄▓[0;34m▄[0;94;44m░[0;34;44m [0;34m▀[0;37m [0;94;44m░[0;34;44m▄▓[0;34m [0;94;44m░[0;34;44m▄▓[0;37m [0;34m▀[0;34;44m▄▓[0;34m▄[0;94;44m░[0;34;44m [0;34m▀[0;37m [0;94;44m░[0;34;44m▄▓[0;34m [0;37m [0;94;44m░[0;34m█▄▄[0;94;44m░[0;34;44m▄▓[0;37m [0;94;44m░[0;34;44m▄▓[0;34m [0;37m [0;34m▀[0;34;44m▄▓[0;34m▄[0;94;44m░[0;34;44m▄[0;34m▀[0;37m [0;94;44m░[0;34;44m▄▓[0;34m [0m" << std::endl;
    std::cout << "[0;37m                [0;34m▀▀▀    [0;37m      [0;34m ▀▀▀▀▀ [0;37m                                                       [0m" << std::endl;
}

int choiceType()
{
    int numOfChoice = 2;
    int choice;
    std::cout << BYELLOW << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << BGREEN;
    std::cout << "1 - Map" << std::endl;
    std::cout << "2 - Maze" << std::endl;
    std::cout << NC;
    std::cout << std::endl
              << "choice : ";

    while (!(std::cin >> choice) || (choice < 0 || choice > numOfChoice))
    {
        std::cout << std::endl
                  << BRED << "ERROR : wrong choice" << std::endl
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << BYELLOW << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << BGREEN;
        std::cout << "1 - Map" << std::endl;
        std::cout << "2 - Maze" << std::endl;
        std::cout << NC;
        std::cout << std::endl
                  << "choice : ";
    }
    std::cout << std::endl;

    return (choice);
}

int mapAlgoChoice()
{
    int numOfChoice = 1;
    int choice;
    std::cout << BBLUE;
    std::cout << "CHOOSE THE ALGORITHM : " << std::endl;
    std::cout << BYELLOW << std::endl;
    std::cout << "0 - Back" << std::endl;
    std::cout << BGREEN;
    std::cout << "1 - DiamondSquare" << std::endl;
    std::cout << NC;
    std::cout << std::endl
              << "choice : ";

    while (!(std::cin >> choice) || (choice < 0 || choice > numOfChoice))
    {
        std::cout << std::endl
                  << BRED << "ERROR : wrong choice" << std::endl
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << BYELLOW;
        std::cout << "0 - Back" << std::endl;
        std::cout << BGREEN;
        std::cout << "1 - DiamondSquare" << std::endl;
        std::cout << NC;
        std::cout << std::endl
                  << "choice : ";
    }
    std::cout << std::endl;
    return (choice);
}

int mazeAlgoChoice()
{
    int numOfChoice = 1;
    int choice;
    std::cout << BBLUE;
    std::cout << "CHOOSE THE ALGORITHM : " << std::endl;
    std::cout << BYELLOW << std::endl;
    std::cout << "0 - Back" << std::endl;
    std::cout << BGREEN;
    std::cout << "1 - Backtracking" << std::endl;
    std::cout << NC;
    std::cout << std::endl
              << "choice : ";

    while (!(std::cin >> choice) || (choice < 0 || choice > numOfChoice))
    {
        std::cout << std::endl
                  << BRED << "ERROR : wrong choice" << std::endl
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << BYELLOW;
        std::cout << "0 - Back" << std::endl;
        std::cout << BGREEN;
        std::cout << "1 - Backtracking" << std::endl;
        std::cout << NC;
        std::cout << std::endl
                  << "choice : ";
    }
    std::cout << std::endl;
    return (choice);
}

int diamondSquareSize()
{
    int choice;

    std::cout << BBLUE << "CHOOSE MAP SIZE (max 8)" << std::endl;
    std::cout << BYELLOW << std::endl;
    std::cout << "0 - Back" << NC << std::endl;
    std::cout << std::endl
              << "choice : ";
    while (!(std::cin >> choice) || (choice < 0 || choice > 8))
    {
        std::cout << std::endl
                  << BRED << "ERROR : wrong choice" << std::endl
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << BYELLOW;
        std::cout << "0 - Back" << std::endl;
        std::cout << NC;
        std::cout << std::endl
                  << "choice : ";
    }
    return (choice);
}

int backtrackMazeSize()
{
    int choice;

    std::cout << BBLUE << "CHOOSE MAZE SIZE (max 100)" << std::endl;
    std::cout << BYELLOW << std::endl;
    std::cout << "0 - Back" << NC << std::endl;
    std::cout << std::endl
              << "choice : ";
    while (!(std::cin >> choice) || (choice < 0 || choice > 100))
    {
        std::cout << std::endl
                  << BRED << "ERROR : wrong choice" << std::endl
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << BYELLOW << std::endl;
        std::cout << "0 - Back" << std::endl;
        std::cout << NC;
        std::cout << std::endl
                  << "choice : ";
    }
    std::cout << std::endl;
    return (choice);
}

int genMap()
{
    int algoChoice;
    int mapSize;

    algoChoice = mapAlgoChoice();
    if (algoChoice == 0)
        return (1);
    mapSize = diamondSquareSize();
    if (mapSize == 0)
        return (1);
    switch (algoChoice)
    {
    case 1:
        DiamondSquare map(mapSize, 16, 4);
        map.generation();
        break;
    }
    return (0);
}

int genMaze()
{
    int mazeSize;
    int algoChoice;
    algoChoice = mazeAlgoChoice();
    if (algoChoice == 0)
        return (1);
    mazeSize = backtrackMazeSize();
    if (mazeSize == 0)
        return (1);
    switch (algoChoice)
    {
    case 1:
        BacktrackingMaze maze(mazeSize);
        maze.generation();
        break;
    }
    return (0);
}

int main()
{
    int typeChoice;
    title();
back:
    int res = 0;
    typeChoice = choiceType();
    switch (typeChoice)
    {
    case 0:
        std::cout << BBLUE << "BYE" << NC << std::endl;
        exit(0);
        break;
    case 1:
        res = genMap();
        break;
    case 2:
        res = genMaze();
        std::cout << res << std::endl;
        break;
    }
    if (res)
        goto back;
    if (typeChoice == 1)
    {
        std::cout << BGREEN << "map";
    }
    if (typeChoice == 2)
    {
        std::cout << BGREEN << "maze";
    }
    std::cout << ".txt succefully created, BYE" << std::endl;
    
}