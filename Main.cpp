#include <iostream>
#include <string>
#include "funcoes.h"
#include "horta.h"
#include "Produto.h"
#include "Armazem.h"
#include "files.h"
#include "arrays_string.h"

using namespace std;

int main(int argc, char* argv[]) {

    string Produtos_diretorio = "";
    string Areas_diretorio = "";
    string Fornecedores_diretorio = "";
    string Armazem_diretorio = "";
    string Plantacao_diretorio = "";
    string Colhidos_diretorio = "";

    if (argc == 7) {

        Produtos_diretorio = argv[1];
        Areas_diretorio = argv[2];
        Fornecedores_diretorio = argv[3];
        Armazem_diretorio = argv[4];
        Plantacao_diretorio = argv[5];
        Colhidos_diretorio = argv[6];

    }
    else {

        Produtos_diretorio = "Produtos.txt";
        Areas_diretorio = "Areas.txt";
        Fornecedores_diretorio = "Fornecedores.txt";
        Armazem_diretorio = "Armazem.txt";
        Plantacao_diretorio = "Plantação.txt";
        Colhidos_diretorio = "Colhidos.txt";
    }

    // variaveis auxiliares
    int dia = 0;
    int duracao = 0;
    string nome;
    string area = "";

    srand(time(NULL));

    int capacidade = 5 + rand() % 6;
    string* a_atuais = NULL;
    int tamanho_a_atuais = 0;

    //carregar Produtos
    int tamanho_produtos = tamanho(Produtos_diretorio);
    string* produtos = new string[tamanho_produtos];
    import_files(Produtos_diretorio, produtos);

    //carregar Areas
    int tamanho_areas = tamanho(Areas_diretorio);
    string* areas = new string[tamanho_areas];
    import_files(Areas_diretorio, areas);

    //carregar Fornecedores
    int tamanho_forneecedores = tamanho(Fornecedores_diretorio);
    string* fornecedores = new string[tamanho_forneecedores];
    import_files(Fornecedores_diretorio, fornecedores);

    //inicializar plantação
    horta* plantacao = new horta[capacidade];
    inicializar_plantacao(plantacao, areas, tamanho_areas, id, capacidade);

    //areas das hortas para o array
    tamanho_a_atuais = area_atual(plantacao, capacidade, tamanho_a_atuais, a_atuais);

    int n = 0;

    //inicializar armazem 
    Fila_Armazem armazem;
    inicializar_armazem(armazem, 15, produtos, fornecedores, a_atuais, tamanho_produtos, tamanho_forneecedores, tamanho_a_atuais,n);

    //cout << "Armazem:" << endl;
    //escrever_armazem(armazem);
  
    //vars auxiliares
    char choice = 'a';//seguinte ou gestor
    bool in_gestor = false;
    int tempo = 0;

    do {

        if (choice == 's' || dia == 0) {

            cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
            executar_ciclo(plantacao, capacidade, dia);  
            inicializar_armazem(armazem, 10, produtos, fornecedores, a_atuais, tamanho_produtos, tamanho_forneecedores, tamanho_a_atuais,n);
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
            cout << "Foram plantados: " << adicionar_produtos_horta(armazem, plantacao, capacidade) << " produtos !" << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;

           
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
            escrever_plantacao(plantacao, capacidade);
            cout << "Armazem:" << endl;
            escrever_armazem(armazem);

            cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
            cin >> choice;
            system("CLS");

        }

        if (choice == 'g') {
            
            in_gestor = true;
            do {
                cout << endl;
                cout << "* Bem Vindo Gestor **" << endl;
                cout << "(1) .Colher Produto" << endl;
                cout << "(2) .Atualizar Tempo de rega" << endl;
                cout << "(3) .Fertilizacao" << endl;
                cout << "(4) .Gravar Plantacao" << endl;
                cout << "(5) .Carregar Plantacao" << endl;
                cout << "(6) .Imprimir plantacao" << endl;
                cout << "(7) .Criar nova area" << endl;
                cout << "(8) .Mostrar registro de agricultor" << endl;
                cout << "(9) .Alterar area" << endl;
                cout << "(0) .Voltar" << endl;
                cout << "Seleccione a sua opcao" << endl;
                cin >> choice;
                system("CLS");

                switch (choice)
                {
                case '1':

                    cout << "Escolheu Colher Produto" << endl << endl;
                    cout << "Insira um nome de um produto:" << endl;
                    getline(cin, nome);
                    ColherProduto(plantacao, capacidade, nome);

                    cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
                    cout << "Plantacao:" << endl;
                    escrever_plantacao(plantacao, capacidade);
                    cout << "Armazem:" << endl;
                    escrever_armazem(armazem);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '2':
                    cout << "Escolheu Atualizar Tempo de rega" << endl;
                    cout << "Insira o Nome do Produto que pretende alterar o tempo de rega"<<endl;
                    cin.get();
                    getline(cin, nome);
                    cout << "Insira novo tempo de rega" << endl;
                    cin >> tempo;
                    AtualizarRega(armazem,plantacao, nome, capacidade, tempo);

                    cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
                    cout << "Plantacao:" << endl;
                    escrever_plantacao(plantacao, capacidade);
                    cout << "Armazem:" << endl;
                    escrever_armazem(armazem);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '3':

                    cout << "Escolheu Fertilizacao" << endl;
                    cout << "Introduza a duracao da fertelizacao" << endl;
                    cin >> duracao;
                    cout << "Introduza a area que pretende fazer a fertelizacao"<<endl;
                    cin.get();
                    getline(cin, area);
                    Fertilizacao(plantacao,duracao,area,capacidade);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '4':
                    cout << "Escolheu Gravar Plantacao" << endl;  
                    //guardar armazem, guardar plantacao(colhidos e plantados)
                    GravarPlantacao(plantacao, capacidade, armazem, Plantacao_diretorio, Colhidos_diretorio, Armazem_diretorio);

                    cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
                    cout << "Plantacao:" << endl;
                    escrever_plantacao(plantacao, capacidade);
                    cout << "Armazem:" << endl;
                    escrever_armazem(armazem);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");
                    
                    in_gestor = false;
                    break;
                case '5':
                    cout << "Escolheu Carregar plantacao" << endl;
                    capacidade = CarregarPlantacao(plantacao, capacidade, armazem, Plantacao_diretorio, Colhidos_diretorio, Armazem_diretorio);

                    //atualizar array de areas atuais
                    delete[] a_atuais;
                    a_atuais = NULL;
                    tamanho_a_atuais = 0;
                    tamanho_a_atuais = area_atual(plantacao, capacidade, tamanho_a_atuais, a_atuais);
                    
                    dia = 0; //ver questao da capacidade

                    cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
                    cout << "Plantacao:" << endl;
                    escrever_plantacao(plantacao, capacidade);
                    cout << "Armazem:" << endl;
                    escrever_armazem(armazem);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '6':
                    cout << "Escolheu Imprimir plantacao" << endl << endl;

                    choice = NULL;
                    do {

                        if (choice != NULL && choice != '0' && choice != '1') {
                            cout << "A sua escolha tem de ser entre 0 e 1!!!." << endl;
                        }
                           

                        cout << "Pretende imprimir por:" << endl;
                        cout << "(0) .Ordem alfabetica" << endl;
                        cout << "(1) .Odem crecente do tempo de plantacao" << endl;
                        cin >> choice;
                        system("CLS");

                    } while (choice != '0' && choice != '1');

                    ImprimirPlantacao(armazem, plantacao, capacidade, choice);
                    
                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '7':
                    cout << "Escolheu Criar nova area" << endl << endl;
                 
                    tamanho_a_atuais = CriarArea(a_atuais, tamanho_a_atuais);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '8':
                    cout << "Escolheu Mostrar registro de agricultor" << endl;
                    RegistroAgricultor(plantacao, capacidade);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '9':
                    cout << "Escolheu Alterar area" << endl;
                    AlterarArea(a_atuais,tamanho_a_atuais,plantacao,capacidade);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;
                case '0':
                    cout << "Escolheu Voltar " << endl << endl;

                    cout << "------------------------------------------------- Dia " << dia << " ------------------------------------------------" << endl;
                    cout << "Plantacao:" << endl;
                    escrever_plantacao(plantacao, capacidade);
                    cout << "Armazem:" << endl;
                    escrever_armazem(armazem);

                    cout << endl << "(s) eguinte ********** (g) estao ********** (f) echar" << endl;
                    cin >> choice;
                    system("CLS");

                    in_gestor = false;
                    break;

                default:
                    cout << "A sua escolha tem de ser entre 0 e 9!!!." << endl;
                }

            } while (in_gestor || choice == 'g');

            if(choice == 's')
                dia++;

        }
        else if (choice == 's') {

           
           // cout << "----------------------------------------------- Fim do dia " << dia << "-----------------------------------------------" << endl;

            cout << "Escolheu dia seguinte!!" << endl;
            dia++;
        }

    } while (choice != 'f');
    cout << "A fechar o programa!!!";
}