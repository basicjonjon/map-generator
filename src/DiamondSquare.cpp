/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:27:19 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/20 17:31:07 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondSquare.hpp"

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

DiamondSquare::DiamondSquare(int size, int rangeAlt, int rangeRand) : size(pow(2, size)), map(this->size + 1, std::vector<int>(this->size + 1, 0)), rangeAlt(rangeAlt), rangeRand(rangeRand)
{
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
    // pos.x_center = this->pos.x_start + (this->pos.x_end) / 2;
    pos.y_center = (this->pos.y_start + this->pos.y_end) / 2;
}

// t_pos  DiamondSquare::calcPos(int size, int actualSize)
// {

// }

void DiamondSquare::genCenter()
{
    int centerValue = (this->map[this->pos.y_start][this->pos.x_start] +
                       this->map[this->pos.y_start][this->pos.x_end] +
                       this->map[this->pos.y_end][this->pos.x_start] +
                       this->map[this->pos.y_end][this->pos.x_end]) /
                      4;
    this->map[this->pos.y_center][this->pos.x_center] = genValue(centerValue);
    std::cout << "centerpos : " << this->pos.x_center << " - " << this->pos.y_center << std::endl;
    std::cout << "centerValue : " << this->map[this->pos.y_center][this->pos.x_center] << std::endl;
}

void DiamondSquare::genBorder(int ignoreLeft, int ignoreTop)
{
    int res = 0;
    // top
    if (!ignoreTop)
    {
        res = (this->map[this->pos.y_start][this->pos.x_end] +
               this->map[this->pos.y_start][this->pos.x_end] +
               this->map[this->pos.y_center][this->pos.x_center]) / 3;
        this->map[this->pos.y_start][this->pos.x_start + (this->pos.x_end / 2)] = genValue(res);
    }

    // right
    res = (this->map[this->pos.y_start][this->pos.x_end] +
           this->map[this->pos.y_end][this->pos.x_end] +
           this->map[this->pos.y_center][this->pos.x_center]) /
          3;
    this->map[this->pos.y_start + (this->pos.y_end / 2)][this->pos.x_end] = genValue(res);

    // bottom
    res = (this->map[this->pos.y_end][this->pos.x_end] +
           this->map[this->pos.y_end][this->pos.x_start] +
           this->map[this->pos.y_center][this->pos.x_center]) /
          3;
    this->map[this->pos.y_end][this->pos.x_start + (this->pos.x_end / 2)] = genValue(res);
    
    // left
    if (!ignoreLeft)
    {
        res = (this->map[this->pos.y_end][this->pos.x_start] +
               this->map[this->pos.y_start][this->pos.x_start] +
               this->map[this->pos.y_center][this->pos.x_center]) / 3;
        this->map[this->pos.y_start + (this->pos.y_end / 2)][this->pos.x_start] = genValue(res);
    }
}

void DiamondSquare::genMap()
{
    srand(time(NULL));
    setPos(0, 0, size, size);
    std::cout << *this;

    genCorner();
    genCenter();
    genBorder(0,0);

    std::cout << *this;

    setPos(0, 0, size / 2, size / 2);
    genCenter();
    genBorder(0,0);

    std::cout << *this;


    setPos(size/2, 0, size, size / 2);
    genCenter();
    //(1,1) si x ou y est != 0;
    // genBorder(1,0);

    std::cout << *this;
}

// void DiamondSquare::genMap()
// {
//     t_pos P = setPos(0,0, size, size);
//     // int actualSize = 0;
//     // srand(time(NULL));

//     // genCorner();
//     // genCenter(0, size);
//     // genBorder(0, size, 0);

//     // std::cout << std::endl;
//     // printMap();

//     // actualSize = size / 2;
//     // genCenter(0, actualSize);
//     // genBorder(0, actualSize, 0);

//     // // std::cout << std::endl;
//     // // printMap();

//     // // genCenter(actualSize, size);
//     // // genBorder(actualSize, size, 1);

//     // std::cout << std::endl;
//     // printMap();
// }

// void DiamondSquare::genCenter(int start, int end)
// {
//     int midValue = (this->map[start][start] + this->map[start][end - 1] + this->map[end - 1][start] + this->map[end - 1][end - 1]) / 4;
//     int size = end - start;
//     this->map[end - (start + size / 2)][start + size / 2] = genValue(midValue);
//     // std::cout << std::endl
//     //           << "start = " << start << std::endl
//     //           << "end = " << end << std::endl;
//     // std::cout << "center = " << end - (start + size / 2) << " - " << start + size / 2 << std::endl;
//     std::cout << std::endl
//               << "value " << thiprintMap();
   // std::cout << *this;s->map[end - (start + size / 2)][start + size / 2] << std::endl;
// }

// void DiamondSquare::genBorder(int start, int end, int ignore)
// {
//     (void)ignore;
//     int size = end - start;
//     int midValue = this->map[end - (start + size / 2)][start + size / 2];

//     int resValue = (this->map[start][start] + this->map[start][end] + midValue) / 3;
//     this->map[start][start + size / 2] = genValue(resValue);
//     std::cout << "border mid = " << start << "-" << start + size / 2 << std::endl;

//     resValue = (this->map[start][end] + this->map[end][end] + midValue) / 3;
//     this->map[size / 2][end] = genValue(resValue);

//     resValue = (this->map[end][start] + this->map[end][end] + midValue) / 3;
//     this->map[end][start + size / 2] = genValue(resValue);

//     resValue = (this->map[end][start] + this->map[start][start] + midValue) / 3;
//     this->map[size / 2][start] = genValue(resValue);
// }

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
    o << std::endl;
    map.printMap();
    return (o);
}