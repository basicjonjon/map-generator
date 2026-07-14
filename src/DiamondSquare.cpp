/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/14 19:31:01 by jle-doua         ###   ########.fr       */
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



void DiamondSquare::genMap()
{
    std::cout << "test : " << size /2 + 1 << std::endl;
    srand(time(NULL));
    // generate corner
    this->map[0][0] = rand() % (this->rangeAlt + 1);
    this->map[0][size - 1] = rand() % (this->rangeAlt + 1);
    this->map[size - 1][0] = rand() % (this->rangeAlt + 1);
    this->map[size - 1][size - 1] = rand() % (this->rangeAlt + 1);

    // generate center 
    int randNum = (rand() % (this->rangeRand * 2) - this->rangeRand);
    this->map[size /2][size /2] = (this->map[0][0] + this->map[0][size - 1] + this->map[size - 1][0] + this->map[size - 1][size - 1]) / 4;
    std::cout << "mid map : " << this->map[size /2][size /2] << " rand : " << randNum <<std::endl;
    if (this->map[size /2][size /2] + (rand() % (this->rangeRand * 2) - this->rangeRand) > rangeAlt)
        this->map[size /2][size /2] = rangeAlt;
    else if (this->map[size /2][size /2] + (rand() % (this->rangeRand * 2) - this->rangeRand) < 0)
        this->map[size /2][size /2] = 0;
    else
        this->map[size /2][size /2] += randNum;
    printMap();
}