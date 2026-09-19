/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BacktrackingMaze.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:51:10 by jle-doua          #+#    #+#             */
/*   Updated: 2026/09/19 18:16:50 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKINGMAZE_HPP
#define BACKTRACKINGMAZE_HPP

#include "mapGenerator.hpp"

typedef struct s_movePossibility
{
    int x;
    int y;
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

public:
    BacktrackingMaze(int size);
    ~BacktrackingMaze();

    void generation();
    void backtrack();
    std::vector<t_move> getMovePossibility();
    std::vector<t_move> checkMovePossibility( std::vector<t_move> move_list);
    void setWall(int y, int x);
};

#endif