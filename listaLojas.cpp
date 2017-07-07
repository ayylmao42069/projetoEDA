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
		}