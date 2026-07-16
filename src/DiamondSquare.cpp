/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/16 15:48:11 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>


DiamondSquare::DiamondSquare(int size, int rangeAlt, int rangeRand) : size(pow(2,size) + 1), map(this->size, std::vector<int>(this->size, 0)), rangeAlt(rangeAlt), rangeRand(rangeRand)
{
    printMap();
}

DiamondSquare::~DiamondSquare()
{
}

void DiamondSquare::printMap()
{
    for (int i = 0; i < size; i++)
   {
        for (int y = 0; y < size; y++)
        {
            std::cout << this->map[i][y] << " ";     
        }
        std::cout << std::endl;
   }
}

void DiamondSquare::genCorner()
{
    this->map[0][0] = rand() % (this->rangeAlt + 1);
    this->map[0][size - 1] = rand() % (this->rangeAlt + 1);
    this->map[size - 1][0] = rand() % (this->rangeAlt + 1);
    this->map[size - 1][size - 1] = rand() % (this->rangeAlt + 1);
}

int DiamondSquare::genValue(int value)
{
    int randNum = (rand() % (this->rangeRand * 2) - this->rangeRand);
    int centerValue = randNum + value;
    if (centerValue > this->rangeAlt || centerValue < 0)
    {
        if (centerValue > this->rangeAlt)
            centerValue = rangeAlt;
        else
            centerValue = 0;
    }
    return (centerValue);
}

void DiamondSquare::genCenter(int start, int end)
{
    int midValue = (this->map[start][start] + this->map[start][end -1] + this->map[end - 1][start] + this->map[end - 1][end - 1]) / 4;
    int size = end - start;

    this->map[size /2][size /2] = genValue(midValue);
}


void DiamondSquare::genBorder(int start, int end)
{
    int size = end - start;
    int midValue = this->map[size/2][size/2];
    int resValue = (this->map[start][start] + this->map[start][end - 1] + midValue) / 3;
    this->map[start][size/2] = genValue(resValue);
    resValue = (this->map[start][end - 1] + this->map[end - 1][end - 1] + midValue) / 3;
    this->map[size/2][end - 1] = genValue(resValue);
    resValue = (this->map[end - 1][start] + this->map[end - 1][end - 1] + midValue) / 3;
    this->map[end - 1][size/2] = genValue(resValue);
    resValue = (this->map[end - 1][start] + this->map[start][start] + midValue) / 3;
    this->map[size/2][start] = genValue(resValue);

}

void DiamondSquare::genMap()
{
    srand(time(NULL));
    genCorner();
    genCenter(0, size);
    genBorder(0, size);
    std::cout << std::endl;
    printMap();
}