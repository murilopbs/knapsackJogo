#include "../headers/tela.hpp"

void Tela::iniciarVariaveis(){
    this->window = nullptr;
    this->settings.antialiasingLevel=25;
    this->fps = 4;
    this->direcao = 4;
}

void Tela::iniciarWindow(){
    this->videomode.width = 800;
    this->videomode.height = 600;
    std::string str = "A Escolha";
	std::basic_string<sf::Uint32> out;
	sf::Utf8::toUtf32(str.begin(), str.end(), std::back_inserter(out));
    this->window = new sf::RenderWindow(this->videomode, out, sf::Style::Default, this->settings);
    this->window->setFramerateLimit(4);
}

Tela::Tela(){
    this->iniciarVariaveis();
    this->iniciarWindow();
}

Tela::~Tela(){
    this->window->close();
}

const bool Tela::running() const{
    return this->window->isOpen();
}

void Tela::pollEvents(){
    sf::Event e;
    while(this->window->pollEvent(this->e)){
        if(this->e.type == sf::Event::Closed)
            this->window->close();
        if(this->e.type == sf::Event::KeyPressed) /// Se alguma tecla for pressionada
        {
            if(this->e.key.code == sf::Keyboard::Up)
                this->direcao=1;
            if(this->e.key.code == sf::Keyboard::Down)
                this->direcao=2;
            if(this->e.key.code == sf::Keyboard::Right)
                this->direcao=4;
            if(this->e.key.code == sf::Keyboard::Left)
                this->direcao=3;
        }
    }
}

void Tela::setFrtL(int fps){
    this->window->setFramerateLimit(fps);
}

void Tela::update(){
    this->pollEvents();
}

void Tela::render(){
    this->window->display();
}

void Tela::proximaFase(int fase){
    if (!font.loadFromFile("../Fontes/arial.ttf"))
	{
		// handle error
	}
    sf::Text texto;
    std::string suporte = "Parabéns, você passou da " + std::to_string(fase) + "° fase.\nPressione enter para a próxima fase.";
    std::basic_string<sf::Uint32> out;
	sf::Utf8::toUtf32(suporte.begin(), suporte.end(), std::back_inserter(out)); 
    texto.setString(out);
	texto.setPosition(sf::Vector2f(800 / 4, (600 / 2) - 50));
    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    this->window->clear();
    this->window->draw(texto);
    this->window->display();
    while (this->window->isOpen()){
		sf::Event event;

		while (this->window->pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Return){
                    return;
                }
            }else if(event.type == sf::Event::Closed){
                this->window->close();
            }
        }
    }
}

bool Tela::perdeuTudo(int fase){
    if (!font.loadFromFile("../Fontes/arial.ttf"))
	{
		// handle error
	}
    sf::Text texto;
    std::string suporte = "Você perdeu tudo na " + std::to_string(fase) + "° fase.\nPressione enter para voltar ao menu\nou esc para sair.";
    std::basic_string<sf::Uint32> out;
	sf::Utf8::toUtf32(suporte.begin(), suporte.end(), std::back_inserter(out)); 
    texto.setString(out);
	texto.setPosition(sf::Vector2f(800 / 4, (600 / 2) - 50));
    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    this->window->clear();
    this->window->draw(texto);
    this->window->display();
    while (this->window->isOpen()){
		sf::Event event;

		while (this->window->pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Return){
                    return true;
                } else if(event.key.code == sf::Keyboard::Escape){
                    return false;
                }
            }else if(event.type == sf::Event::Closed){
                this->window->close();
            }
        }
    }
    return true;
}

void Tela::voltaMenu(){
    this->iniciarVariaveis();
    this->iniciarWindow();
}