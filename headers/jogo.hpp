#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <random>
#include <vector>
#include "../headers/knapsack.hpp"

class Jogo : public Knapsack{
    public:
        Jogo();
        ~Jogo();
        void desenhaObjetos();
        const bool rodando() const;

    private:
        // variáveis
        std::vector<int> peso;
        std::vector<int> valor;
        int capacidade;
        sf::Text texto[5];
        sf::Text apertarE;
        sf::CircleShape seletor;
        sf::Texture figuras[5];
        sf::Sprite sprites[5];
        sf::RenderWindow* window;
        sf::Event e;
        sf::VideoMode videomode;
        sf::ContextSettings settings;
        sf::Font font;
        sf::Vector2f posicaoSeletor;
        char lixo;
        bool naMochila[5];
        int contador;
        int fase;
        // funções
        void iniciaJanela();
        void iniciaSprites();
        void atualizaSeletor(char direcao);
        void escolheObjeto();
        void iniciaJogo();
        bool confereResultado();
        void proximaFase();
        bool perdeuTudo();
};