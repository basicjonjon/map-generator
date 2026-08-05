/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:28:03 by jle-doua          #+#    #+#             */
/*   Updated: 2026/08/05 18:05:54 by jle-doua         ###   ########.fr       */
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
    int round;
    int rangeAlt;
    double rangeRand;
    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> mapPatch;

public:
    DiamondSquare(int size, int rangeAlt, int rangeRand);
    ~DiamondSquare();

    void generation();
    void genCorner();
    void genCenter(int y, int x);
    void genBorder(int y, int x);

    void foreachMap(void (DiamondSquare::*func)(int, int), int step);

    int cornerAverage(int y, int x);
    int globalAverage(std::vector<std::pair<int, int>> corner);
    int genRandomValue(int value);

    std::vector<int> getArround(int x, int y) const;
    void medianMask();

    void printMap(std::vector<std::vector<int> > map) const;

    int getSize() const;
    int getRangeAlt() const;
    int getRangeRand() const;
    std::pair<int, int> getCenter(int y, int x) const;
};

int randomInt(int min, int max);
std::ostream &operator<<(std::ostream &o, DiamondSquare const &map);

#endif