#include "Visualization.h"
#include <iostream>
#include <cmath>
#include <vector>

Visualization::Visualization() {}

Visualization::~Visualization() {}

void Visualization::createTimeSeriesPlot(LinkedList &list)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Time Series Plot");
    window.setFramerateLimit(60);

    std::vector<sf::Vertex> tempLine, ch4Line, co2Line;
    Node *current = list.getHead();

    int i = 0;
    while (current)
    {
        float x = 50 + i * 10;
        tempLine.emplace_back(sf::Vector2f(x, 300 - current->globalTemperature * 100), sf::Color::Blue);
        ch4Line.emplace_back(sf::Vector2f(x, 300 - current->CH4Level / 10), sf::Color::Magenta);
        co2Line.emplace_back(sf::Vector2f(x, 300 - current->CO2Level / 10), sf::Color::Green);
        current = current->next;
        i++;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        sf::RectangleShape xAxis(sf::Vector2f(700, 2)), yAxis(sf::Vector2f(2, 500));
        xAxis.setPosition(50, 300);
        yAxis.setPosition(50, 100);
        xAxis.setFillColor(sf::Color::Black);
        yAxis.setFillColor(sf::Color::Black);

        window.draw(xAxis);
        window.draw(yAxis);
        window.draw(tempLine.data(), tempLine.size(), sf::LinesStrip);
        window.draw(ch4Line.data(), ch4Line.size(), sf::LinesStrip);
        window.draw(co2Line.data(), co2Line.size(), sf::LinesStrip);

        window.display();
    }
}

void Visualization::createScatterPlot(LinkedList &list, double correlationCH4, double correlationCO2)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Scatter Plot");
    window.setFramerateLimit(60);

    std::vector<sf::CircleShape> pointsCH4, pointsCO2;
    Node *current = list.getHead();

    while (current)
    {
        sf::CircleShape pointCH4(2), pointCO2(2);
        pointCH4.setPosition(100 + current->CH4Level / 2, 500 - current->globalTemperature * 100);
        pointCO2.setPosition(100 + current->CO2Level / 2, 500 - current->globalTemperature * 100);

        pointCH4.setFillColor(sf::Color::Blue);
        pointCO2.setFillColor(sf::Color::Red);

        pointsCH4.push_back(pointCH4);
        pointsCO2.push_back(pointCO2);
        current = current->next;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        sf::RectangleShape xAxis(sf::Vector2f(700, 2)), yAxis(sf::Vector2f(2, 500));
        xAxis.setPosition(50, 500);
        yAxis.setPosition(50, 100);
        xAxis.setFillColor(sf::Color::Black);
        yAxis.setFillColor(sf::Color::Black);

        window.draw(xAxis);
        window.draw(yAxis);

        for (const auto &point : pointsCH4)
            window.draw(point);
        for (const auto &point : pointsCO2)
            window.draw(point);

        window.display();
    }
}
