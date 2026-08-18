/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/08/18 15:54:25 by jle-doua         ###   ########.fr       */
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

DiamondSquare::DiamondSquare(int size, int rangeAlt, int rangeRand) : size(pow(2, size)), step(pow(2, size)), round(1), rangeAlt(rangeAlt), rangeRand(rangeRand), map(this->size + 1, std::vector<int>(this->size + 1, 0)), mapPatch(this->size + 1, std::vector<int>(this->size + 1, 0))
{
}

DiamondSquare::~DiamondSquare()
{
}

void DiamondSquare::generation()
{
    genCorner();

    double amplitude = 4.0;
    const double roughness = 0.70;
    while (step > 1)
    {
        rangeRand = static_cast<int>(std::round(amplitude));
        foreachMap(&DiamondSquare::genCenter, this->step);
        foreachMap(&DiamondSquare::genBorder, this->step);
        step /= 2;
        amplitude *= roughness;
        if (step <= 4)
            amplitude = 0;
    }
    medianMask();
    printMap(this->mapPatch);
}

void DiamondSquare::genCorner()
{
    this->map[0][0] = randomInt(1, rangeAlt);
    this->map[0][size] = randomInt(1, rangeAlt);
    this->map[size][0] = randomInt(1, rangeAlt);
    this->map[size][size] = randomInt(1, rangeAlt);
}

void DiamondSquare::genCenter(int y, int x)
{
    this->map[getCenter(y, x).first][getCenter(y, x).second] = genRandomValue(cornerAverage(y, x));
}

void DiamondSquare::genBorder(int y, int x)
{
    if (y == 0)
        this->map[y][this->getCenter(y, x).second] = genRandomValue(
            globalAverage(
                {std::make_pair(y, x), std::make_pair(y, x + this->step), getCenter(y, x)}));
    else
        this->map[y][this->getCenter(y, x).second] = genRandomValue(
            globalAverage(
                {std::make_pair(y, x), std::make_pair(y, x + this->step), getCenter(y, x), getCenter(y - this->step, x)}));
    if (x == 0)
        this->map[this->getCenter(y, x).first][x] = genRandomValue(
            globalAverage(
                {std::make_pair(y, x), std::make_pair(y + this->step, x), getCenter(y, x)}));
    else
        this->map[this->getCenter(y, x).first][x] = genRandomValue(
            globalAverage(
                {std::make_pair(y, x), std::make_pair(y + this->step, x), getCenter(y, x), getCenter(y, x - this->step)}));
    if (x + this->step == this->size)
        this->map[this->getCenter(y, x).first][x + this->step] = genRandomValue(
            globalAverage(
                {std::make_pair(y, x + this->step), std::make_pair(y + this->step, x + this->step), getCenter(y, x)}));
    if (y + this->step == this->size)
        this->map[y + this->step][this->getCenter(y, x).second] = genRandomValue(
            globalAverage(
                {std::make_pair(y + this->step, x), std::make_pair(y + this->step, x + this->step), getCenter(y, x)}));
}

void DiamondSquare::foreachMap(void (DiamondSquare::*func)(int, int), int step)
{
    for (int y = 0; y < this->size; y += step)
    {
        for (int x = 0; x < this->size; x += step)
        {
            (this->*func)(y, x);
        }
    }
}

std::vector<int> DiamondSquare::getArround(int y, int x) const
{
    std::vector<int> values;

    for (int offsetY = -1; offsetY <= 1; offsetY++)
    {
        for (int offsetX = -1; offsetX <= 1; offsetX++)
        {
            int currentY = y + offsetY;
            int currentX = x + offsetX;

            if (currentY >= 0 && currentY < this->size && currentX >= 0 && currentX < this->size)
            {
                values.push_back(this->map[currentY][currentX]);
            }
        }
    }
    return (values);
}

void DiamondSquare::medianMask()
{
    std::vector<int> values;
    std::size_t middle;
    for (size_t y = 0; y < this->map.size(); y++)
    {

        for (size_t x = 0; x < this->map.size(); x++)
        {
            values = this->getArround(y, x);

            if (values.empty())
                return;
            std::sort(values.begin(), values.end());
            middle = values.size() / 2;
            if (values.size() % 2 == 1)
            {
                this->mapPatch[y][x] = values[middle];
            }
            else
            {
                this->mapPatch[y][x] =
                    (values[middle - 1] + values[middle]) / 2;
            }
        }
    }
}

int DiamondSquare::cornerAverage(int y, int x)
{
    return ((this->map[y][x] +
             this->map[y][x + this->step] +
             this->map[y + this->step][x] +
             this->map[y + this->step][x + this->step]) /
            4);
}

int DiamondSquare::globalAverage(std::vector<std::pair<int, int>> pos)
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

void DiamondSquare::printMap(std::vector<std::vector<int>> map) const
{
    for (int i = 0; i <= size; i++)
    {
        for (int y = 0; y <= size; y++)
        {
            std::cout << map[i][y] << " ";
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

std::pair<int, int> DiamondSquare::getCenter(int y, int x) const
{
    return (std::make_pair(y + this->step / 2, x + this->step / 2));
}

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map)
{
    o << "size : " << map.getSize() << std::endl;
    o << "range Altitude : 1 - " << map.getRangeAlt() << std::endl;
    o << "range Random : " << map.getRangeRand() * -1 << " - " << map.getRangeRand() << std::endl;

    o << std::endl;
    return (o);
}
