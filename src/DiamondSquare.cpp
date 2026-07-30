/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/30 19:52:40 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <color.h>
#include <algorithm>

DiamondSquare::DiamondSquare(int size, int rangeAlt, int rangeRand) : size(pow(2, size)), step(pow(2, size)), x(0), y(0), rangeAlt(rangeAlt), rangeRand(rangeRand), map(this->size + 1, std::vector<int>(this->size + 1, 0))
{
}

DiamondSquare::~DiamondSquare()
{
}

void DiamondSquare::generation()
{
    std::cout << *this << std::endl;
    genCorner();
    for (; this->y < size; this->y += step)
    {
        for (; this->x < size; this->x += step)
        {
            genCenter();
        }
    }
    this->x = 0;
    this->y = 0;
    genBorder();
    step /= 2;
    for (; this->y < size; this->y += step)
    {
        std::cout << "y :" << y << std::endl;
        for (; this->x < size; this->x += step)
        {
            genCenter();
            std::cout << "x : " << x << std::endl;
            std::cout << *this << std::endl;
        }
        this->x = 0;
    }
    std::cout << *this << std::endl;
}

void DiamondSquare::genCorner()
{
    this->map[0][0] = randomInt(1, rangeAlt);
    this->map[0][size] = randomInt(1, rangeAlt);
    this->map[size][0] = randomInt(1, rangeAlt);
    this->map[size][size] = randomInt(1, rangeAlt);
}

void DiamondSquare::genCenter()
{
    this->map[getCenter().first][getCenter().second] = genRandomValue(cornerAverage());
}

void DiamondSquare::genBorder()
{
    // top
    this->map[this->y][this->getCenter().second] = genRandomValue(borderAverage(std::make_pair(this->y, this->x), std::make_pair(this->y, this->x + this->step)));
    // right

    this->map[this->getCenter().first][this->x + step] = genRandomValue(borderAverage(std::make_pair(this->y, this->x + step), std::make_pair(this->y + step, this->x + step)));
    // bot
    this->map[this->y + step][this->getCenter().second] = genRandomValue(borderAverage(std::make_pair(this->y + step, this->x), std::make_pair(this->y + step, this->x + step)));

    // left
    this->map[this->getCenter().first][this->x] = genRandomValue(borderAverage(std::make_pair(this->y, this->x), std::make_pair(this->y + step, this->x)));
}

int DiamondSquare::cornerAverage()
{
    return ((this->map[this->y][this->x] +
             this->map[this->y][this->x + this->step] +
             this->map[this->y + this->step][this->x] +
             this->map[this->y + this->step][this->x + this->step]) /
            4);
}

int DiamondSquare::borderAverage(std::pair<int, int> c1, std::pair<int, int> c2)
{
    return ((this->map[c1.first][c1.second] +
             this->map[c2.first][c2.second] +
             this->map[this->getCenter().first][this->getCenter().second]) /
            3);
}

int DiamondSquare::genRandomValue(int value)
{
    int res = value + randomInt(this->rangeRand * -1, this->rangeRand);
    if (res < 1 || res > rangeAlt)
    {
        if (res < 1)
            res = 1;
        else
            res = rangeAlt;
    }
    return (res);
}

void DiamondSquare::printMap() const
{
    for (int i = 0; i <= size; i++)
    {
        for (int y = 0; y <= size; y++)
        {
            if (this->map[i][y] != 0)
            {
                std::cout << BRED;
            }
            std::cout << this->map[i][y] << NC << " ";
        }
        std::cout << std::endl;
    }
}

int DiamondSquare::getSize() const
{
    return (this->size);
}
int DiamondSquare::getRangeAlt() const
{
    return (this->rangeAlt);
}
int DiamondSquare::getRangeRand() const
{
    return (this->rangeRand);
}

int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

std::pair<int, int> DiamondSquare::getCenter() const
{
    return (std::make_pair(this->y + this->step / 2, this->x + this->step / 2));
}

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map)
{
    o << "size : " << map.getSize() << std::endl;
    o << "range Altitude : 1 - " << map.getRangeAlt() << std::endl;
    o << "range Random : " << map.getRangeRand() * -1 << " - " << map.getRangeRand() << std::endl;
    o << "center : [" << map.getCenter().first << "][" << map.getCenter().second << "]" << std::endl;

    o << std::endl;
    map.printMap();
    o << std::endl;
    return (o);
}
