/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:05:46 by jle-doua          #+#    #+#             */
/*   Updated: 2026/07/14 19:19:24 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapGenerator.h"

void error(std::string msg)
{
    std::cerr << BRED << "ERROR";
    if (!msg.empty())
    {
        std::cerr << ": " << msg;
    }
    std::cerr << NC << std::endl;
    exit(1);
}

int isNumber(std::string arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (!isdigit(arg[i]))
            return (0);
    return (1);
}

int main(int argc, char **argv)
{
    if(argc != 2 || !isNumber(argv[1]))
        error("Wrong arg numbers");
    DiamondSquare res(std::atoi(argv[1]), 16, 4);
    res.genMap();
}