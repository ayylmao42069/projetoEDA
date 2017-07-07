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
			}
			
		}