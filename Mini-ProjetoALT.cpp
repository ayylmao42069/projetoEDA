#include <iostream
#include <string>
#include <ctime>
#include <time.h> // library para o uso da funÃ§Ã£o time() e da struct time_t
#include <iomanip>
#include <math.h>
using namespace std;

/* CÓDIGOS DE VESTUÁRIO:
		Camisa-----A
		CalÃ§as-----B
		Blusa------C
		Camisola---D
		Casaco-----E
		Sapatos----F
		Cinto------G
		AcessÃ³rio--H

		CODIGOS DE SEXO:
		Homem----M
		Mulher---F
		CrianÃ§a--C
*/



class CProdutosVest : public CGestaoLojas{ // Para um so produto
	protected:
		string ref; //referÃªncia
		char sexo; //char porque Ã© mais eficiente para uso de memÃ³ria. M=Homem, F=Mulher, C=CrianÃ§a.
		char TipoProduto; //char porque Ã© mais eficiente para a conservaÃ§Ã£o de memÃ³ria. A lista de correspondÃªncias
											//estarÃ¡ listada noutro sitio.
		unsigned float Pvenda; //PreÃ§o de venda
		unsigned float Pcompra; //PreÃ§o de compra
		bool existe; // serve para marcar os produtos que nunca existiram em stock
		CProdutosVest *proximo; // Ponteiro que aponta para o prÃ³ximo produto

		//NOTA PARA O MALO: Os ponteiros nÃ£o apontam para outra classe, apontam para outro CProdutosVest.

	public:
		CProdutosVest(){ //Construtor por omissÃ£o
			Pvenda = Pcompra = 0;
			proximo = NULL;
		}

};

class CListaLojas : public CGestaoLojas{ // Para cada loja
	protected:
		unsigned int codigo;
		string local;
		unsigned float area;
		CStock* stockIn;
		CVendas vendas;
		//trocas
		bool existe
		CListaLojas *proximo;

	public:
		CListaLojas(){
			codigo = stock = vendas = 0;
			area = 0;
			proximo = NULL;
		}

		void repoeStock(){

		}
};

class CStock : public CGestaoLojas{ // Para cada produto em stock
	protected:
		string refProduto;
		unsigned int quantidade;
		unsigned int stockMin;
		unsigned int stockMax;
		unsigned float montante;
		CStockLoja *proximo;

	public:
		CStock(){
			quantidade = stockMin = stockMax = 0;
			montante = 0;
			proximo = NULL;
		}
};

class CVendas : public CGestaoLojas{ // Para cada venda
	protected:
		unsigned int codigo;
		time_t DataHora; // Usaremos mais ï¿½ frente a funï¿½ï¿½o time(NULL)
		//lista de referencias
		unsigned float montanteTot;
		CVendas *proximo;

	public:
		CVendas(){
			codigo = 0;
			montanteTot = 0;
			proximo = NULL;
		}
};

class CGestaoLojas{ // Classe mï¿½e
	protected:
		CProdutosVest *inicioPV;
		CListaLojas *inicioLL;	

	public:



		/*##############################################################################################################################################################
		#################################################-INSERIR/ELIMINAR/LISTAR PRODUTOS-########################################################################################################
		################################################################################################################################################################
		*/

		void inserePV(){ //Insere um novo produto de vestuÃ¡rio na lista de produtos
			CProdutosVest *novo = new CProdutosVest;
			CProdutosVest *atual;
			string aux;
			do{
				cout << "\nIntroduza a referÃªncia do produto:\n"
				getline(cin,novo->ref);
				if((novo->ref).length()!=10) cout << "\nERRO: Tamanho de referÃªncia invÃ¡lido; introduza novamente.\n";
			}while((novo->ref).length()!=10);

			do{
				cout << "\nIntroduza a secÃ§Ã£o do produto (Homem, mulher ou crianÃ§a):"
				getline(cin, aux);

	  		for (int i=0; i<aux.length(); ++i) aux[i]=toupper(aux[i]);

				switch(aux){
					case "HOMEM": novo->sexo='M';
												break;
					case "MULHER": novo->sexo='F';
												break;
					case "CRIANÃ‡A": novo->sexo='C';
												break;
					default: cout << "\nERRO: Nome incompatÃ­vel, insira novamente.\n";
									 novo->sexo='O';
				}
			}while(novo->sexo=='0');

			do{
				cout << "\nIntroduza o tipo do produto:\n";
				cin >> aux;

				for (int i=0; i<aux.length(); ++i) aux[i]=toupper(aux[i]);

				switch(aux){
					case "CAMISA": novo->TipoProduto='A';
												break;
					case "CALÃ‡AS": novo->TipoProduto='B';
												break;
					case "BLUSA": novo->TipoProduto='C';
												break;
					case "CAMISOLA": novo->TipoProduto='D';
												break;
					case "Casaco": novo->TipoProduto='E';
												break;
					case "SAPATOS": novo->TipoProduto='F';
												break;
					case "CINTO": novo->TipoProduto='G';
												break;
					case "ACESSÃ“RIO": novo->TipoProduto='H';
												break;
					case "ACESSORIO": novo->TipoProduto='H';
												break;
					default: cout << "\nERRO: Nome incompatÃ­vel, insira novamente.\n";
									 novo->TipoProduto='O';
									 break;
				}
			}while(novo->TipoProduto=='0');

			cout << "\nInsira o preÃ§o de venda:\n";
			cin >> novo->Pvenda;

			cout << "\nInsira o preÃ§o de compra:\n";
			cin >> novo->Pcompra;

			novo->proximo = NULL;

			if(inicioPV == NULL)  inicio PV = novo;
			else{
				atual = inicioPV;
				while (atual->proximo != NULL) atual = atual->proximo;
				atual->proximo = novo;
			}
			return;
		}

		bool eliminaPV(){ // retorna true se eliminou com sucesso, retorna false se falhou ao eliminar
			CProdutosVest *atual = inicioPV;
			CProdutosVest *anterior;
			string aux;
			if (inicioPV == NULL) return false;

			anterior = NULL;

			cout << "\nInsira a referÃªncia do produto que pretende eliminar (SÃ“ PODE ELIMINAR PRODUTOS QUE ";
			cout << "\nNUNCA TENHAM EXITIDO EM STOCK!):\n";
			getline(cin, aux);

			if((novo->ref).length()!=10) cout << "\nERRO: Tamanho de referÃªncia invÃ¡lido; introduza novamente.\n";

			while (atual != NULL){
				if(atual->ref == aux){
					if(atual->existe == false){
						if (anterior == NULL){
							inicioPV = atual->proximo;
							delete atual;
							return true;
						}else
							anterior->proximo = atual->proximo;
							delete atual;
							return true;
						}
					}
				anterior = atual;
				atual = atual->proximo;
				}
			}
			return false;
		}

		void listaPV() const{
			CProdutosVest *atual = inicioPV;
			string aux;
			cout << "\nReferencia | Seccao | Tipo de Produto | Preco de venda | Preco de compra\n" //72 letras

			while(atual != NULL){
				cout << atual->ref << " | "; //NAO MUDES ESTA LINHA CARALHO, ESTA ALINHADA

				switch(aux){
					case "M": aux='Homem';
												break;
					case "F": aux='Mulher';
												break;
					case "C": aux='Criança';
												break;
				}

				cout << setw() << aux << " | ";              // SWITCH

				switch(aux){
					case "A": aux='Camisa';
												break;
					case "B": aux='Calças';
												break;
					case "C": aux='Blusa';
												break;
					case "D": aux='Camisola';
												break;
					case "E": aux='Casaco';
												break;
					case "F": aux='Sapatos';
												break;
					case "G": aux='Cinto';
												break;
					case "H": aux='Acessorio';
												break;
				}

				cout << setw() << aux << " | ";       // SWITCH


				cout << setprecision(2) << setw() << atual->Pvenda << " | " << setw() << setprecision(2) << atual->Pcompra << endl;

				atual=atual->proximo;
			}
			return;
		}

		/*##############################################################################################################################################################
		#################################################-INSERIR/ELIMINAR LOJAS-########################################################################################################
		################################################################################################################################################################
		*/
		
		void insereL(){  
			CListaLojas *novo = new CListaLojas;
			CListaLojas *atual = inicioLL;
			string aux;
			
			if(atual == NULL) inicioLL = novo;
			else {
				while(atual->proximo != NULL){
					atual = atual->proximo;
				}
				atual->proximo=novo;
			}
			
			cout << "Introduza o código da loja:" << endl; //Malo 19/06
			cin >> novo->codigo;
			
			do{
				cout <<"\nIntroduza o local da loja:" << endl;  //Malo 19/06
				getline(cin, aux);
			}while(aux.length() == 0);
			
			cout << "\nIntroduza a área que a loja ocupa:" << endl; //Malo 19/06
			cin >> novo->area;
			
			novo->stock = new CStock;
			
			novo->vendas = new CVendas;

			//FALTA INSERIR AS TROCAS

			return;
		}

		bool eliminaL(){
			CListaLojas *atual = inicioPV;
			CListaLojas *anterior;
			int aux;
			if(inicioLL == NULL) return false;

			anterior = NULL;

			cout << "\nInsira o código da loja que pretende eliminar (SÃ“ PODE ELIMINAR LOJAS QUE ";
			cout << "\nNUNCA TENHAM TIDO QUALQUER PRODUTO EM STOCK!):\n";
			cin >> aux;

			while (atual != NULL){
				if(atual->codigo == aux){
					if(atual->existe == false){
						if (anterior == NULL){
							inicioLL = atual->proximo;
							delete atual;
							return true;
						}else{
							anterior->proximo = atual->proximo;
							delete atual;
							return true;
						}
					}
				anterior = atual;
				atual = atual->proximo;
				}
			}
			return false;		
		}

		void listaLojas(){
			CProdutosVest *atual = inicioLL;
			string aux;
			cout << "\n Codigo | Local | Area \n" //72 letras
			if(atual==NULL) cout << "Não existem lojas para apresentar." << endl;
			while(atual != NULL){
				cout << atual->codigo << " | ";

				cout << setw() << atual->local << " | "; 

				cout << setw() << setprecision(2) << atual->area << " | ";       

				atual=atual->proximo;
			}
			return;
		}

		/*##############################################################################################################################################################
		#################################################-OPERAÇÕES DE STOCKS-##########################################################################################
		################################################################################################################################################################
		*/

		void insereStock(CListaLojas* loja){
			CStock* atual=loja->stockIn;
			CStock* novo=new CStock;
			CProdutosVest* crsp=inicioPV;
			bool mod=0;
			int opn;


			if(crsp==NULL){
				cout << "\nERRO: Não existem produtos na lista de produtos, por favor atualize.\n"
				return;
			}

			if(atual!=NULL){
				while(atual->proximo!=NULL){
					atual=atual->proximo;
				}
			} else loja->stockIn=novo;
			cout << "\nInsira os detalhes do novo produto a acrescentar:\n-Referência:"
			while(mod==0){
				cin << novo->refProduto;
				while((novo->refProduto).length()!=10){
					cout << "\nTamanho de referência incorreto, reinsira por favor.\n";
					cin << novo->refProduto;
				}
				while(crsp!=NULL){
					if(crsp->ref==novo->refProduto) {
						mod=1;
						goto label;
					}
					crsp=crsp->proximo;
				}
				label:
				if(mod==0){
					cout << "\nNão existe nenhum produto na lista de produtos com essa referência, pretende: \n(Insira o número da operação pretendida)\n";
					cout << "1-Inserir um novo produto na lista de produtos\n";
					cout << "2-Reinserir a referência. (Referência inserida= " << novo-refProduto << ")\n";
					cout << "0-Cancelar a operação\n"

					cin << opn;

					switch(opn){
					case 1:	inserePV();
							break;
					case 2: break;
					case 0: delete novo;
							return;
							break;
					default: cout << "\nInseriu um número inválido, por favor reinsira.\n";
							break;
				}
				}
			}
			cout << "\n\n-Quantidade:";
			cin >> novo->quantidade;

			cout << "\n\n-Stock minimo:";
			cin >> novo->stockMin;

			cout << "\n\n-Stock maximo:";
			cin >> novo->stockMax;

			novo->montante=(crsp->Pvenda)-(crsp->Pcompra); //montante??

			return;
		}

		void repoeStock(CListaLojas* loja){

		}

		/*##############################################################################################################################################################
		#################################################-MENUS-########################################################################################################
		################################################################################################################################################################
		*/
		void gereStock(CListaLojas *loja){
			while(1==1){
				int opn;

				cout << "\nInsira o número da operação que pretende executar:\n";
				cout << "\n1-Inserir produtos"
				cout << "\n2-Repor stocks"
				cout << "\n0-Retornar ao menu anterior"

				cin >> opn;

				switch(opn){
					case 1:	insereStock(loja);
							break;
					case 2:	repoeStock(loja);
							break;
					case 0:	return;
							break;
					default: cout << "\nInseriu um número inválido, por favor reinsira.\n";
							break;
				}
			}
		}

		void operatorLojas(){
			listaLojas();
			int code, opt=0;
			CListaLojas *gerida;
			if(gerida==NULL) {
				cout << "\nNenhuma loja para gerir. Retornando ao menu principal." << endl;
				return;
			}
				cout << "\n Selecione o codigo da loja que pretende gerir:\n"
			do{
					cin >> code;
					gerida=inicioLL;
				}
				while(opt==0){
					if(gerida->codigo==code) goto label2; //Alternativa para goto's
					else if(gerida==NULL){
						cout << "\nO codigo que inseriu não corresponde a nenhuma loja, por favor, reinsira:\n"
						opt=5;
					};
					gerida=gerida->proximo;
				}
			}while(opt==5)

			label2:

			while{1==1}{
				cout << "\n Selecione uma opção de gestão:\n";
				cout << "1-GERIR STOCK\n";
				cout << "2-REGISTAR VENDA\n";
				cout << "3-TROCAR PRODUTO\n";
				cout << "4-LISTAR INVENTÁRIO\n";
				cout << "0-REGRESSAR AO MENU ANTERIOR" << endl;

				cin >> opt;

				switch(opt){
					case 1:	gereStock(gerida);
							break;
					case 2:	regVenda(gerida);
							break;
					case 3:	trocaProd();
							break;
					case 4:	listaInv();
							break;
					case 0:	return;
							break;
					default: cout << "\nInseriu um número inválido, por favor reinsira.\n";
							break;
				}
			}

		}

