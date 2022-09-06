#include "SFML/Graphics.hpp"
#include <iostream>
#include "../headers/jogo.hpp"

int main(){
    Jogo jogo;
    
    while(jogo.rodando()){
        jogo.desenhaObjetos();
    }
    return 0;
}