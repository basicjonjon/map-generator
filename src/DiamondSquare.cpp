/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/08/03 18:34:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"

#include <vector>
#include <map>
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
    genCorner();

    int i = 3;
    while (step > 1)
    {
        for (; this->y < size; this->y += step)
        {
            for (; this->x < size; this->x += step)
            {
                genCenter();
            }
            this->x = 0;
        }
        this->y = 0;
        for (; this->y < size; this->y += step)
        {
            for (; this->x < size; this->x += step)
            {
                genBorder();
            }
            this->x = 0;
        }
        step /= 2;
        rangeRand /= 2;
        this->y = 0;
        i--;
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
    this->map[getCenter(this->y, this->x).first][getCenter(this->y, this->x).second] = genRandomValue(cornerAverage());
}

void DiamondSquare::genBorder()
{

    if (this->y == 0)
    {
        // top
        this->map[this->y][this->getCenter(this->y, this->x).second] = genRandomValue(borderAverage({std::make_pair(this->y, this->x), std::make_pair(this->y, this->x + this->step), getCenter(this->y, this->x)}));
    }
    else
    {
        this->map[this->y][this->getCenter(this->y, this->x).second] = genRandomValue(borderAverage({std::make_pair(this->y, this->x), std::make_pair(this->y, this->x + this->step), getCenter(this->y, this->x), getCenter(this->y - this->step, this->x)}));
    }
    if (this->y + this->step == this->size)
    {
        // bot
        this->map[this->y + step][this->getCenter(this->y, this->x).second] = genRandomValue(borderAverage({std::make_pair(this->y + step, this->x), std::make_pair(this->y + step, this->x + step), getCenter(this->y, this->x)}));
    }
    if (this->x == 0)
    {
        // left
        this->map[this->getCenter(this->y, this->x).first][this->x] = genRandomValue(borderAverage({std::make_pair(this->y, this->x), std::make_pair(this->y + step, this->x), getCenter(this->y, this->x)}));
    }
    else
    {
        this->map[this->getCenter(this->y, this->x).first][this->x] = genRandomValue(borderAverage({std::make_pair(this->y, this->x), std::make_pair(this->y + step, this->x), getCenter(this->y, this->x), getCenter(this->y, this->x - this->step)}));
    }
    if (this->x + this->step == this->size)
    {
        // right
        this->map[this->getCenter(this->y, this->x).first][this->x + step] = genRandomValue(borderAverage({std::make_pair(this->y, this->x + step), std::make_pair(this->y + step, this->x + step), getCenter(this->y, this->x)}));
    }
}

int DiamondSquare::cornerAverage()
{
    return ((this->map[this->y][this->x] +
             this->map[this->y][this->x + this->step] +
             this->map[this->y + this->step][this->x] +
             this->map[this->y + this->step][this->x + this->step]) /
            4);
}

int DiamondSquare::borderAverage(std::vector<std::pair<int, int>> pos)
{
    int res = 0;
    for (size_t i = 0; i < pos.size(); i++)
    {
        res += this->map[pos[i].first][pos[i].second];
    }
    res /= pos.size();
    return (res);
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

int DiamondSquare::checkAround(int y, int x)
{
    // int value = this->map[y][x];
    std::map<int, int> color;

    if (x != 0)
    {
        color[this->map[y][x - 1]] += 1;
    }
    if (x != size)
    {
        color[this->map[y][x + 1]] += 1;
    }
    if (y != 0)
    {
        color[this->map[y - 1][x]] += 1;
    }
    if (y != size)
    {
        color[this->map[y + 1][x]] += 1;
    }
    std::map<int, int>::iterator it = color.begin();
    std::map<int, int>::iterator max = it;

    for (; it != color.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
        if (it->second > max->second)
        {
            max = it;
        }
    }
    std::cout << "max = " << max->first << std::endl;

    return (max->first);
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

int DiamondSquare::getStepX() const
{
    return (this->x);
}

int DiamondSquare::getStepY() const
{
    return (this->y);
}

int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

std::pair<int, int> DiamondSquare::getCenter(int y, int x) const
{
    return (std::make_pair(y + this->step / 2, x + this->step / 2));
}

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map)
{
    o << "size : " << map.getSize() << std::endl;
    o << "range Altitude : 1 - " << map.getRangeAlt() << std::endl;
    o << "range Random : " << map.getRangeRand() * -1 << " - " << map.getRangeRand() << std::endl;
    o << "center : [" << map.getCenter(map.getStepY(), map.getStepX()).first << "][" << map.getCenter(map.getStepY(), map.getStepX()).second << "]" << std::endl;

    o << std::endl;
    map.printMap();
    o << std::endl;
    return (o);
}
