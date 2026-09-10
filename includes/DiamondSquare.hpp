/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:28:03 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/10 17:33:51 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDSQUARE_HPP
#define DIAMONDSQUARE_HPP

#include "mapGenerator.hpp"

class DiamondSquare
{
private:
    int size;
    int step;
    int rangeAlt;
    double rangeRand;
    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> mapPatch;
    std::vector<std::vector<int>> finalMap;

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

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map);

#endif