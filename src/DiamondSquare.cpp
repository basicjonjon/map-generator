/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/21 18:19:01 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <color.h>

DiamondSquare::DiamondSquare(int size, int rangeAlt, int rangeRand) : size(pow(2, size)), map(this->size + 1, std::vector<int>(this->size + 1, 0)), rangeAlt(rangeAlt), rangeRand(rangeRand), ignoreLeft(false), ignoreTop(false)
{
    this->actualSize = this->size;
}

DiamondSquare::~DiamondSquare()
{
}

void DiamondSquare::printMap() const
{
    for (int i = 0; i <= size; i++)
    {
        for (int y = 0; y <= size; y++)
        {
            std::cout << this->map[i][y] << " ";
        }
        std::cout << std::endl;
    }
}

void DiamondSquare::genCorner()
{
    this->map[0][0] = rand() % (this->rangeAlt + 1);
    this->map[0][size] = rand() % (this->rangeAlt + 1);
    this->map[size][0] = rand() % (this->rangeAlt + 1);
    this->map[size][size] = rand() % (this->rangeAlt + 1);
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

void DiamondSquare::setPos(int x_start, int y_start, int x_end, int y_end)
{
    pos.x_start = x_start;
    pos.x_end = x_end;
    pos.y_start = y_start;
    pos.y_end = y_end;
    pos.x_center = (this->pos.x_start + this->pos.x_end) / 2;
    pos.y_center = (this->pos.y_start + this->pos.y_end) / 2;
    if (pos.x_start != 0)
        ignoreLeft = true;
    else
        ignoreLeft = false;
    if (pos.y_start != 0)
        ignoreTop = true;
    else
        ignoreTop = false;
}

void DiamondSquare::genCenter()
{
    int centerValue = (this->map[this->pos.y_start][this->pos.x_start] +
                       this->map[this->pos.y_start][this->pos.x_end] +
                       this->map[this->pos.y_end][this->pos.x_start] +
                       this->map[this->pos.y_end][this->pos.x_end]) / 4;
    this->map[this->pos.y_center][this->pos.x_center] = genValue(centerValue);
}

void DiamondSquare::genBorder()
{
    int res = 0;
    // top
    if (!this->ignoreTop)
    {
        res = (this->map[this->pos.y_start][this->pos.x_end] +
               this->map[this->pos.y_start][this->pos.x_end] +
               this->map[this->pos.y_center][this->pos.x_center]) / 3;
        this->map[this->pos.y_start][this->pos.x_center] = genValue(res);
    }
    // right
    res = (this->map[this->pos.y_start][this->pos.x_end] +
           this->map[this->pos.y_end][this->pos.x_end] +
           this->map[this->pos.y_center][this->pos.x_center]) /
          3;
    this->map[this->pos.y_center][this->pos.x_end] = genValue(res);
    // bottom
    res = (this->map[this->pos.y_end][this->pos.x_end] +
           this->map[this->pos.y_end][this->pos.x_start] +
           this->map[this->pos.y_center][this->pos.x_center]) /
          3;
    this->map[this->pos.y_end][this->pos.x_center] = genValue(res);
    // left
    if (!this->ignoreLeft)
    {
        res = (this->map[this->pos.y_end][this->pos.x_start] +
               this->map[this->pos.y_start][this->pos.x_start] +
               this->map[this->pos.y_center][this->pos.x_center]) / 3;
        this->map[this->pos.y_center][this->pos.x_start] = genValue(res);
    }
}

void DiamondSquare::genMap()
{
    printMap();
    srand(time(NULL));
    setPos(0, 0, size, size);
    genCorner();
    genCenter();
    genBorder();
    while (actualSize > 0)
    {
        actualSize /= 2;
        setPos(0,0, actualSize, actualSize);
        while (this->pos.y_end <= this->size && this->pos.x_end <= this->size)
        {
            printMap();
            genCenter();
            genBorder();
            if (this->pos.x_end == this->size)
                setPos(0, this->pos.y_start + actualSize, actualSize, this->pos.y_end + actualSize);
            else
                setPos(this->pos.x_start + actualSize, this->pos.y_start, this->pos.x_end + actualSize, this->pos.y_end);
        }
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

t_pos DiamondSquare::getPos() const
{
    return (this->pos);
}

std::vector<std::vector<int> > DiamondSquare::getMap() const
{
    return (this->map);
}

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map)
{
    o << std::endl;
    o << "Map size : " << map.getSize() + 1 << std::endl;

    o << "Range altitude : " << map.getRangeAlt() << std::endl;
    o << "Range random : " << map.getRangeRand() * -1 << " " << map.getRangeRand() << std::endl;
    o << "Actual X pos : [" << map.getPos().x_start << "][" << map.getPos().x_end << "]" << std::endl;
    o << "Actual Y pos : [" << map.getPos().y_start << "][" << map.getPos().y_end << "]" << std::endl;
    o << "Actual C pos : [" << map.getPos().y_center << "][" << map.getPos().x_center << "]" << std::endl;
    o << "Actual top pos : [" << map.getPos().y_start << "][" << map.getPos().x_center << "]" << std::endl; 
    o << std::endl;
    map.printMap();
    return (o);
}
