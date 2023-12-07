#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

void transformatemp(double tempo){
  int resto, minutos, hora; 
  if(tempo>60){
    minutos = tempo/60;
    resto = tempo - (minutos *60);
    cout << minutos << "min "<< resto << "s ";

  } else{
    cout.precision(2);
    cout << tempo <<"s ";
  }
}


bool ehVerde (char letra, string tentativa, string chave, int chance, string matriz[6][5]){
  int a=0;
  for (int i=0; i<5; i++){
    if(letra == tentativa[i] && letra == chave[i] && matriz[chance-1][i] ==" "){
      return true;
    }
  }
  return false;
};

void eh (char letra, string tentativa, string chave, int chance, string matriz[6][5]){
  string everde = ": verde ";
  for (int i=0; i<5; i++){
    if(letra == tentativa[i] && letra == chave[i]){
        matriz[chance-1] [i] = letra + everde;
    }
  } 
};

void preencher(string matriz[6][5]){
  for (int i=0; i<6; i++){
    for(int j=0; j<5; j++){
      matriz[i][j] = " ";
    }
  }
};

void gravardados(ofstream *dados, string usuario, string senha) {
  if (usuario.size() > 1 && senha.size() > 1) {
    *dados << usuario << senha << endl;
  }
}

int main() {

  cout << "\n TRABALHO FINAL\n Aluna: Jasmin Marques Maia\n Turma: IF23\n\nEsse projeto é inspirado no jogo chamado Termo (https://term.ooo/), que por sua vez foi inspirado no Wordle), o qual consiste em uma plavra que contenha 5 letras denominada palavra-chave escolhida aleatoriamente, que deve ser acertada pelo jogador dentro de 6 chances." << "\nAs letras da palavra inserida aparecerão com os seguintes textos ao lado:\n" << "\n' : verde' - Se a letra da palavra inserida conter na chave e estiver na posição correta.\n\n' : amarelo' - Se a letra da palavra inserida conter na chave, porém não está na posição correta.\n\n' : vermelho' - Se a letra da palavra inserida não estiver contida na chave.\n\n(OBS: as palavras devem ser escritas em MINÚSCULO, e NÃO aceitasse palavras ACENTUADAS)\n---------------------------------------------------------";

  string chave;
  string tentativa;
  char resp = 'S';
  double tempo;

  //CRIAR O ARQUIVO.TXT DAS CHAVES
  //ofstream gravar;
  //gravar.open("chaves.txt", ios_base::out | ios_base::app);
  //if(gravar.is_open()){
  //  cout << "Abri :)";
  //} else cout << "Não abri :(";

  cout << "\nGostaria de Jogar? (Responda 'S' ou 'N') ";
  cin >> resp;
  setbuf(stdin, NULL);
  system("clear");


  //INÍCIO DO CADASTRO--------------------------------------------

  string usuario;
  string senha;
  string linhausuario;
  string somausuario;
  char respConta;

  ofstream gravarusuario;
  ifstream lerusuario;

  if(resp =='S' || resp =='s'){ //Aceitou Jogar
    cout << "Já possui conta? (Responda 'S' ou 'N') ";
    cin >> respConta;
    cin.ignore();
    int contadorusuario = 0;

    if (respConta == 'S') { //Possui conta

      lerusuario.open("usuarios.csv", ios_base::in);

      if (lerusuario.is_open()) {

        do {
          lerusuario.seekg(0);
          contadorusuario = 0;
          setbuf(stdin, NULL);
          cout<<"\n-------------------------------\n";
          setbuf(stdin, NULL);
          cout << "Digite o nome do usuário: ";
          getline(cin, usuario); // ler nome de usuario
          setbuf(stdin, NULL);

          cout << "Digite a senha: ";
          getline(cin, senha); // ler senha
          setbuf(stdin, NULL);

          while (getline(lerusuario, linhausuario)) {
            somausuario = usuario + senha;
            if (linhausuario == somausuario) { //se for igual é pq existe
              cout << "\n~Usuário Conectado~\n";
              contadorusuario++; // Controle que "credenciais inválidas"
              lerusuario.eof(); // não aparece para o usuário
              cout << "\nE aí, vamos jogar? (Responda 'S' ou 'N'): ";
              cin >> resp;
              cin.ignore();
            }
            if (lerusuario.eof()) lerusuario.clear();
              lerusuario.close();
        }

          if (contadorusuario == 0){ // Se todas as linhas forem != de usuario,
                                    //no arquivo, mostre isso e retorne 0
            cout << "\n! Credenciais Inválidas. Usuário não encontrado. Por favor jogue novamente !\n";
            return 0;
          }

        } while (contadorusuario == 0);

      } else {
        cout << "Erro ao abrir o arquivo de dados :(. Por favor jogar novamente.";
      }

    } else {

      gravarusuario.open("usuarios.csv", ios_base::app);
      lerusuario.open("usuarios.csv", ios_base::in);

      if (gravarusuario && lerusuario) {

        do {
          setbuf(stdin, NULL);
          contadorusuario = 0;
          cout<<"\n-------------------------------\n";
          setbuf(stdin, NULL);
          cout << "\nCadastro de um Novo Jogador\n";

          cout << "Usuário: ";
          getline(cin, usuario);
          setbuf(stdin, NULL);

          cout << "Senha: ";
          getline(cin, senha);
          setbuf(stdin, NULL);

          while (getline(lerusuario, linhausuario)) { // Lê o arquivo e impede que hajam
            somausuario = usuario + senha;           // Impede que hajam usuários com 
            if (linhausuario == somausuario) {      // mesmo nome
              cout << "\n! Nome de Usuário já ocupado, tente novamente !\n";
              contadorusuario += 1;               // Se for igual é pq o nome do usuário
            }                                    // já está em uso
            if (lerusuario.eof())
              lerusuario.clear();
          }

          if (contadorusuario == 0) { 
            gravardados(&gravarusuario, usuario, senha);
            cout << "\n~Novo usuário cadastrado. Seja bem-vindo!~\n E aí, vamos jogar? (Responda 'S' ou 'N'): ";
            cin >> resp;                // Se o nome for diferente dos já arquivados
            cin.ignore();               // ele é registrado
            
          }

        } while (contadorusuario == 1); // Faça enquanto o usuario digitado for igual
                                        // a algum já arquivado
      } else {
        cout << "Erro ao abrir o arquivo de dados :(. Por favor jogar novamente.";
      }
    }
  }

  //FIM DO CADASTRO-----------------------------------------------


  do {

    if (resp=='S' || resp=='s'){ // Se o jogador aceitar jogar, entre no if

//----INÍCIO DA ESCOLHA DE CHAVE ALEATÓRIA-------
      ifstream ler;
      int ale;
      int contador = 0;
      srand(time(NULL));

      do{ // Impede que o gerador de nº aleatório dê 0
        ale = rand() %23;
      }while(ale==0);


      ler.open("chaves.txt", ios_base::in);

      if(ler.is_open()){ // Abriu Arquivo para leitura.
        cout << "Abri\n";
        ler.seekg(0);
        string linha;

        while(getline(ler,linha)){ // Enquanto houver linha, leia.
          contador +=1;           // Quando o nº da linha (medida pelo contador)  
          if(contador==ale){     // for igual ao número aleatório (ale),
            chave=linha;        // chave recebe o conteúdo de linha.
          }
        }

        if(ler.eof()) ler.clear();

      } else {
        cout << "Erro ao abrir o arquivo :(. Por favor jogar novamente.";
        return 0;
      }

//-----FIM DA ESCOLHA DE CHAVE ALEATÓRIA-----------

      system("clear"); //limpar a tela

      int chances = 1;

      setbuf(stdin, NULL);
      cout << "A palavra-chave possui 5 letras.\n(OBS: as palavras devem ser escritas em MINÚSCULO, e NÃO aceitasse palavras ACENTUADAS) O tempo começou a ser conatado! Boa partida!";
      setbuf(stdin, NULL);

      chrono::time_point<chrono::system_clock> inicio, final;
      inicio= chrono::system_clock::now();

      while(chances <=6){
          setbuf(stdin, NULL);
        do{//Faça enquanto a tentativa não tiver 5 letras
            setbuf(stdin, NULL);
            cout << "\n\nRodada " << chances << "/6. Digite uma palavra: ";          
            setbuf(stdin, NULL);
            getline(cin,tentativa);
            setbuf(stdin, NULL);
            if(tentativa.length() != 5) {
              setbuf(stdin, NULL);
              cout << "\n\nA palavra possui 5 letras, tente novamente";
            }

        }while(tentativa.length() !=5);



        if(tentativa !=chave){ //Se não for igual entre

//INÍCIO DA LÓGICA DO JOGO----------------------------------------------------

          string verde = ": verde";
          string amarelo = ": amarelo";
          string vermelho = ": vermelho";
          string matriz [6][5];


          preencher(matriz); //preenche com espaço em branco

          // Conta as ocorrências de cada letra na palavra-alvo (que deve-se adivinhar)
          unordered_map<char, int> QuantLetranaChave;
          for ( char c : chave) {
            QuantLetranaChave[c]++;

          }


          // Verifica as letras na palavra tentativa e na palavra-alvo
          for (int i = 0; i < tentativa.length(); ++i) {
              char letra = tentativa[i];

            if (chave.find(letra) != string::npos && chave.find(letra) == i && chave[i]==tentativa[i]) { //VERDE

                if (QuantLetranaChave[letra] > 0) {  
                    matriz[chances-1][i] = letra + verde;
                    QuantLetranaChave[letra]--; 
                }

            } else if (chave.find(letra) != string::npos && chave.find(letra) != i) { // AMARELO
                  // Se ainda houver ocorrências não utilizadas da letra na palavra-alvo
                  if (QuantLetranaChave[letra] > 0) {

                      if(ehVerde(letra,tentativa,chave,chances,matriz)){

                        eh(letra,tentativa,chave, chances, matriz); //Exiba "verde << no índice tal"
                        QuantLetranaChave[letra]--;

                      } else {

                        matriz[chances-1][i] = letra + amarelo;
                        QuantLetranaChave[letra]--;
                      } // Marca uma ocorrência como utilizada
                  }

              }

              for (int z=0; z<5; z++){
                  if(matriz[chances-1][z]== " "){
                    matriz[chances-1][z] = tentativa[z] + vermelho;
                  }
               }


          } //Fim do (int i = 0; i < tentativa.length(); ++i)


           for (int i=0; i<5; i++){
               cout << matriz[chances-1][i] << endl; 
              //E SE EU COLOCAR PRA MOSTRAR SÓ ATÉ O NÚMERO DE CHANCES?
           }

//FIM DA LÓGICA DO JOGO----------------------------------------------


          chances++; //Incremente as chances

          if(chances==7) {
            cout << "\nQuantidade de chances Esgotadas. A palavra era: " << chave << endl;
            setbuf(stdin, NULL);
            //Calcula tempo até o jogador utilizar sua última chance
            final = chrono::system_clock::now();
            chrono::duration<double> tempototal= final - inicio;
            time_t end_time = chrono::system_clock::to_time_t(final);
            tempo = tempototal.count();


            cout << "\nVocê levou um tempo total de ";
            transformatemp(tempo);
            cout << " para perder. Jogue melhor na próxima!\n";
            setbuf(stdin, NULL);
          }

        } else { //GANHOU O JOGO!
          cout << "\nParabéns você acertou! A palavra era: " << chave << endl;
          setbuf(stdin, NULL);
          //Calcula tempo até o jogador acertar
          final = chrono::system_clock::now();
          chrono::duration<double> tempototal = final - inicio;
          time_t end_time = chrono::system_clock::to_time_t(final);
          tempo = tempototal.count();

          cout << "\nVocê levou ";
          transformatemp(tempo);
          cout << " para descobrir!\n";
          setbuf(stdin, NULL);
          chances = 7; // quebra o while das chances
        }

      } // Chave do While (chances <=6)

    } else {// Se 'S' for a resp
      system ("clear");
      cout << "\nFica para um próxima então. Tchaau!";
      return 0;
    } 

      setbuf(stdin, NULL);
      cout << "\nGostaria de jogar novamente? (Responda 'S' ou 'N'): ";
      cin >> resp;
      cin.ignore(); // Ignora o "/n"

      if(resp !='S') {
        system("clear");
        cout << "\nQue pena :(\nAté a próxima então!\n(Obrigada por ter jogado)";}

  }while(resp=='S'); //Resposta positiva para jogar

  return 0;

}