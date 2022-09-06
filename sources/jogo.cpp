#include "../headers/jogo.hpp"

Jogo::Jogo(){
    this->window = nullptr;
    this->settings.antialiasingLevel=25;
    this->iniciaJanela();
    this->iniciaJogo();
}

Jogo::~Jogo(){
    this->window->close();
}

void Jogo::iniciaJogo(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> peso1(1, 50);
    std::uniform_int_distribution<int> valor1(1, 50);
    std::uniform_int_distribution<int> capacidade1(1, 150);
    this->capacidade = capacidade1(mt); 
    this->seletor.setFillColor(sf::Color::White);
    this->seletor.setRadius(10);
    this->posicaoSeletor.x = 190;
    this->posicaoSeletor.y = 100;
    this->seletor.setPosition(this->posicaoSeletor.x, this->posicaoSeletor.y);
    this->contador = 0;
    for(int i = 0; i < 5; i++){
        this->peso.push_back(peso1(mt));
        this->valor.push_back(valor1(mt));
        this->naMochila[i] = false;
    }
    this->fase = 1;
    this->iniciaSprites();
}

void Jogo::iniciaSprites(){
    std::string suporteStr;
    sf::Vector2f tamanho(80.0f, 80.0f);
    if(!font.loadFromFile("../fontes/arial.ttf")){
        std::cout << "Fonte falhou\n";
    }
    this->apertarE.setFont(font);
    suporteStr = "Peso da mochila: " + std::to_string(capacidade) + "\nAperte 'E' para conferir";
    this->apertarE.setString(suporteStr);
    this->apertarE.setPosition(sf::Vector2f((800/2) - (this->apertarE.getGlobalBounds().width / 2), 350));
    
    // iniciando espada
    if(!this->figuras[0].loadFromFile("../imagens/espada.png")){
        std::cout << "Erro\n";
    }
    this->sprites[0].setTexture(this->figuras[0]);
    this->sprites[0].setScale(
        tamanho.x / this->sprites[0].getLocalBounds().width,
        tamanho.y / this->sprites[0].getLocalBounds().height
    );
    this->sprites[0].setPosition(sf::Vector2f(160, 10));
    this->sprites[0].setColor(sf::Color(255, 255, 255, 128));
    this->texto[0].setFont(font);
    this->texto[0].setFillColor(sf::Color::Red);
    suporteStr = "Valor " + std::to_string(this->valor[0]) + '\n' + "Peso " + std::to_string(this->peso[0]);
    this->texto[0].setString(suporteStr);
    this->texto[0].setPosition(sf::Vector2f(160, 150));
    this->texto[0].setScale(
        (tamanho.x) / this->texto[0].getLocalBounds().width,
        40 / this->texto[0].getLocalBounds().height
    );
    // iniciando peitoral
    if(!this->figuras[1].loadFromFile("../imagens/peitoral.png")){
        std::cout << "Erro\n";
    }
    this->sprites[1].setTexture(this->figuras[1]);
    this->sprites[1].setScale(
        tamanho.x / this->sprites[1].getLocalBounds().width,
        tamanho.y / this->sprites[1].getLocalBounds().height
    );
    this->sprites[1].setPosition(sf::Vector2f(260, 10));
    this->sprites[1].setColor(sf::Color(255, 255, 255, 128));
    this->texto[1].setFont(font);
    this->texto[1].setFillColor(sf::Color::White);
    suporteStr = "Valor " + std::to_string(this->valor[1]) + '\n' + "Peso " + std::to_string(this->peso[1]);
    this->texto[1].setString(suporteStr);
    this->texto[1].setPosition(sf::Vector2f(260, 150));
    this->texto[1].setScale(
        tamanho.x / this->texto[1].getLocalBounds().width,
        40 / this->texto[1].getLocalBounds().height
    );
    //iniciando redstone
    if(!this->figuras[2].loadFromFile("../imagens/redstone.png")){
        std::cout << "Erro\n";
    }
    this->sprites[2].setTexture(this->figuras[2]);
    this->sprites[2].setScale(
        tamanho.x / this->sprites[2].getLocalBounds().width,
        tamanho.y / this->sprites[2].getLocalBounds().height
    );
    this->sprites[2].setPosition(sf::Vector2f(360, 10));
    this->sprites[2].setColor(sf::Color(255, 255, 255, 128));
    this->texto[2].setFont(font);
    this->texto[2].setFillColor(sf::Color::White);
    suporteStr = "Valor " + std::to_string(this->valor[2]) + '\n' + "Peso " + std::to_string(this->peso[2]);
    this->texto[2].setString(suporteStr);
    this->texto[2].setPosition(sf::Vector2f(360, 150));
    this->texto[2].setScale(
        tamanho.x / this->texto[2].getLocalBounds().width,
        40 / this->texto[2].getLocalBounds().height
    );
    //iniciando ovo
    if(!this->figuras[3].loadFromFile("../imagens/ovo.png")){
        std::cout << "Erro\n";
    }
    this->sprites[3].setTexture(this->figuras[3]);
    this->sprites[3].setScale(
        tamanho.x / this->sprites[3].getLocalBounds().width,
        tamanho.y / this->sprites[3].getLocalBounds().height
    );
    this->sprites[3].setPosition(sf::Vector2f(460, 10));
    this->sprites[3].setColor(sf::Color(255, 255, 255, 128));
    this->texto[3].setFont(font);
    this->texto[3].setFillColor(sf::Color::White);
    suporteStr = "Valor " + std::to_string(this->valor[3]) + '\n' + "Peso " + std::to_string(this->peso[3]);
    this->texto[3].setString(suporteStr);
    this->texto[3].setPosition(sf::Vector2f(460, 150));
    this->texto[3].setScale(
        tamanho.x / this->texto[3].getLocalBounds().width,
        40 / this->texto[3].getLocalBounds().height
    );
    //iniciando carne
    if(!this->figuras[4].loadFromFile("../imagens/carne.png")){
        std::cout << "Erro\n";
    }
    this->sprites[4].setTexture(this->figuras[4]);
    this->sprites[4].setScale(
        tamanho.x / this->sprites[4].getLocalBounds().width,
        tamanho.y / this->sprites[4].getLocalBounds().height
    );
    this->sprites[4].setPosition(sf::Vector2f(560, 10));
    this->sprites[4].setColor(sf::Color(255, 255, 255, 128));
    this->texto[4].setFont(font);
    this->texto[4].setFillColor(sf::Color::White);
    suporteStr = "Valor " + std::to_string(this->valor[4]) + '\n' + "Peso " + std::to_string(this->peso[4]);
    this->texto[4].setString(suporteStr);
    this->texto[4].setPosition(sf::Vector2f(560, 150));
    this->texto[4].setScale(
        tamanho.x / this->texto[4].getLocalBounds().width,
        40 / this->texto[4].getLocalBounds().height
    );

    //iniciando 
    this->window->clear();
    this->window->draw(this->sprites[0]);
    this->window->draw(this->sprites[1]);
    this->window->draw(this->sprites[2]);
    this->window->draw(this->sprites[3]);
    this->window->draw(this->sprites[4]);
    this->window->draw(this->seletor);
    this->window->draw(this->texto[0]);
    this->window->draw(this->texto[1]);
    this->window->draw(this->texto[2]);
    this->window->draw(this->texto[3]);
    this->window->draw(this->texto[4]);
    this->window->draw(this->apertarE);
    this->window->display();

    
}

void Jogo::iniciaJanela(){
    this->videomode.width = 800;
    this->videomode.height = 600;
    std::string str = "A Escolha";
	std::basic_string<sf::Uint32> out;
	sf::Utf8::toUtf32(str.begin(), str.end(), std::back_inserter(out));
    this->window = new sf::RenderWindow(this->videomode, out, sf::Style::Default, this->settings);
    this->window->setFramerateLimit(60);
}

void Jogo::desenhaObjetos(){
    while(this->window->pollEvent(this->e)){
        if(this->e.type == sf::Event::Closed){
            this->window->close();
        }else if(this->e.type == sf::Event::KeyReleased){
            if(this->e.key.code == sf::Keyboard::Right){
                //this->sprites[0].setColor(sf::Color(255, 255, 255, 128));
                this->atualizaSeletor('d');
            }else if(this->e.key.code == sf::Keyboard::Left){
                this->atualizaSeletor('e');
            }else if(this->e.key.code == sf::Keyboard::Enter){
                this->escolheObjeto();
            }else if(this->e.key.code == sf::Keyboard::E){
                if(this->confereResultado()){
                    this->proximaFase();
                    this->iniciaJogo();
                }else{
                    if(this->perdeuTudo()){
                        this->iniciaJogo();
                    }else{
                        this->window->close();
                    }
                }
            }
        }
    }
}

bool Jogo::confereResultado(){
    int total = Knapsack::fractional_knapsack(this->peso, this->valor, this->capacidade);
    int totalJogador = 0;
    for(int i = 0; i < 5; i++){
        if(this->naMochila[i] == true){
            totalJogador += valor[i];
        }
    }
    if(total == totalJogador){
        return true;
    } 
    return false;
}

const bool Jogo::rodando() const{
    return this->window->isOpen();
}

void Jogo::escolheObjeto(){
    if(this->naMochila[this->contador]){
        this->naMochila[this->contador] = false;
        this->sprites[this->contador].setColor(sf::Color(255, 255, 255, 128));
        this->texto[contador].setFillColor(sf::Color::Red);
    }else{
        this->naMochila[this->contador] = true;
        this->sprites[this->contador].setColor(sf::Color(255, 255, 255, 255));
        this->texto[contador].setFillColor(sf::Color::Green);
    }
    this->window->clear();
    this->window->draw(this->sprites[0]);
    this->window->draw(this->sprites[1]);
    this->window->draw(this->sprites[2]);
    this->window->draw(this->sprites[3]);
    this->window->draw(this->sprites[4]);
    this->window->draw(this->seletor);
    this->window->draw(this->texto[0]);
    this->window->draw(this->texto[1]);
    this->window->draw(this->texto[2]);
    this->window->draw(this->texto[3]);
    this->window->draw(this->texto[4]);
    this->window->draw(this->apertarE);
    this->window->display();
}

void Jogo::atualizaSeletor(char direcao){
    // 'd' = direita ------------- 'e' = esquerda
    if(direcao == 'd'){
        if(this->posicaoSeletor.x == 590){
            this->posicaoSeletor.x = 190;
            this->texto[contador].setFillColor(sf::Color::White);
            this->contador = 0;
            this->naMochila[contador] ? this->texto[contador].setFillColor(sf::Color::Green) : this->texto[contador].setFillColor(sf::Color::Red);
        }else{
            this->posicaoSeletor.x += 100; 
            this->texto[contador].setFillColor(sf::Color::White);
            this->contador += 1;
            this->naMochila[contador] ? this->texto[contador].setFillColor(sf::Color::Green) : this->texto[contador].setFillColor(sf::Color::Red);
        }
    }else{
        if(this->posicaoSeletor.x == 190){
            this->posicaoSeletor.x = 590; 
            this->texto[contador].setFillColor(sf::Color::White);
            this->contador = 4;
            this->naMochila[contador] ? this->texto[contador].setFillColor(sf::Color::Green) : this->texto[contador].setFillColor(sf::Color::Red);
        }else{
            this->posicaoSeletor.x -= 100; 
            this->texto[contador].setFillColor(sf::Color::White);
            this->contador -= 1;
            this->naMochila[contador] ? this->texto[contador].setFillColor(sf::Color::Green) : this->texto[contador].setFillColor(sf::Color::Red);
        }
    }
    this->seletor.setPosition(this->posicaoSeletor.x, this->posicaoSeletor.y);
    this->window->clear();
    this->window->draw(this->sprites[0]);
    this->window->draw(this->sprites[1]);
    this->window->draw(this->sprites[2]);
    this->window->draw(this->sprites[3]);
    this->window->draw(this->sprites[4]);
    this->window->draw(this->seletor);
    this->window->draw(this->texto[0]);
    this->window->draw(this->texto[1]);
    this->window->draw(this->texto[2]);
    this->window->draw(this->texto[3]);
    this->window->draw(this->texto[4]);
    this->window->draw(this->apertarE);
    this->window->display();
}

void Jogo::proximaFase(){
    if (!font.loadFromFile("../fontes/arial.ttf"))
	{
		// handle error
	}
    sf::Text texto;
    std::string suporte = "Parabéns, você passou da " + std::to_string(this->fase) + "° fase.\nPressione enter para a próxima fase.";
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

bool Jogo::perdeuTudo(){
    if (!font.loadFromFile("../fontes/arial.ttf"))
	{
		// handle error
	}
    sf::Text texto;
    std::string suporte = "Você perdeu tudo na " + std::to_string(this->fase) + "° fase.\nPressione enter para voltar ao menu\nou esc para sair.";
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