/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerlinNoise.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:55:06 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/10 17:41:58 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PERLINNOISE_HPP
# define PERLINNOISE_HPP

#include "mapGenerator.hpp"

class PerlinNoise
{
private:
    int size;
    std::vector<std::vector<Vector2>> perlinCells;
    public:
    PerlinNoise(int size);
    ~PerlinNoise();
    
    void genPerlinCells();

    void printPerlinCells();
};




#endif