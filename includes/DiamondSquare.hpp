/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondSquare.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:28:03 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/14 19:18:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDSQUARE_CPP
#define DIAMONDSQUARE_CPP

#include <vector>
#include <iostream>

class DiamondSquare
{
private:
    int size;
    std::vector<std::vector<int> > map;
    int rangeAlt;
    int rangeRand;
public:
    DiamondSquare(int size, int rangeAlt, int rangeRand);
    ~DiamondSquare();

    void printMap();
    void genMap();
};

#endif