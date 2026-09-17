/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/17 16:16:47 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKINGMAZE_HPP
#define BACKTRACKINGMAZE_HPP

#include "mapGenerator.hpp"

enum {
    WALL,
    UNEXPLORED,
    ACT_STACK,
    VALID,
};

class BacktrackingMaze
{
private:
    int size;
    std::vector<std::vector<int>> maze;
public:
    BacktrackingMaze(int size);
    ~BacktrackingMaze();

    void generation();
    void initMaze();

    
};




#endif