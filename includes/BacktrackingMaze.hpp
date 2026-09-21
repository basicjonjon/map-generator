/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/21 19:26:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKINGMAZE_HPP
#define BACKTRACKINGMAZE_HPP

#include "mapGenerator.hpp"

typedef struct s_movePossibility
{
    int x;
    int y;

    s_movePossibility(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
} t_move;

enum
{
    UNEXPLORED,
    EXPLORED,
    VALID,
};

enum
{
    NORTH = 1,
    EAST = 2,
    SOUTH = 4,
    WEST = 8,
};

class BacktrackingMaze
{
private:
    int x;
    int y;
    int size;
    std::vector<std::vector<int>> maze;
    std::vector<std::vector<int>> wall;
    std::vector<std::vector<int>> finalMaze;

public:
    BacktrackingMaze(int size);
    ~BacktrackingMaze();

    void generation();
    void backtrack();
    void setWalls(int y, int x);
    void creatMaze();
    void buildArroundWall();
    void patchMaze();
    std::vector<t_move> getMovePossibility();
    std::vector<t_move> checkMovePossibility(std::vector<t_move> move_list);
};

#endif