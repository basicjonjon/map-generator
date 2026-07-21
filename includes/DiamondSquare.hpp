/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:28:03 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/21 18:04:36 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDSQUARE_CPP
#define DIAMONDSQUARE_CPP

#include <vector>
#include <iostream>


typedef struct s_squarePos
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int x_center;
    int y_center;
}t_pos;
class DiamondSquare
{
private:
    int size;
    int actualSize;
    std::vector<std::vector<int> > map;
    int rangeAlt;
    int rangeRand;
    t_pos pos;
    bool ignoreLeft;
    bool ignoreTop;
    int genNumber;
public:
    DiamondSquare(int size, int rangeAlt, int rangeRand);
    ~DiamondSquare();

    int getSize() const;
    int getRangeAlt() const;
    int getRangeRand() const;
    t_pos getPos() const;
    std::vector<std::vector<int> > getMap() const;

    void genCenter();
    void setPos(int x_start, int y_start, int x_end, int y_end);
    // void calcPos(int size, int actualSize);
    void printMap() const;
    void genCorner();
    int genValue(int value);
    void genBorder();
    void genMap();
};

std::ostream &operator<<(std::ostream &o, DiamondSquare const &map);

#endif