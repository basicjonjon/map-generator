/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:28:03 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/30 19:19:07 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDSQUARE_CPP
#define DIAMONDSQUARE_CPP

#include <vector>
#include <iostream>
#include <random>


class DiamondSquare
{
private:
    int size;
    int step;
    int x;
    int y;
    int rangeAlt;
    int rangeRand;
    std::vector<std::vector<int> > map;

public:
    DiamondSquare(int size, int rangeAlt, int rangeRand);
    ~DiamondSquare();

    void generation();
    void genCorner();
    void genCenter();
    void genBorder();

    int cornerAverage();
    int borderAverage(std::pair<int,int> c1, std::pair<int,int> c2);
    int genRandomValue(int value);
    
    void printMap() const;
    
    int getSize() const;
    int getRangeAlt() const;
    int getRangeRand() const;
    int getStepX() const;
    int getStepY() const;
    std::pair<int,int> getCenter() const;
};

int randomInt(int min, int max);
std::ostream &operator<<(std::ostream &o, DiamondSquare const &map);


#endif