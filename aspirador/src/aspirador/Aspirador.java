//Trabalho de Sistemas Operacionais
//Alunas: Ana Clara C. e Carolina Ataíde
//data última atualização: 24/08/17
package aspirador;

import java.util.Random;

public class Aspirador {

	public static void main(String[] args) throws InterruptedException {

		int[][] matriz = new int[5][5];
		Random num = new Random();
		int cont_limpeza = 0;
		int cont_quadrantes = 0;
		System.out.print("-- Estado inicial dos cômodos--\n");
		for (int a = 0; a < 2; a++) { //faz o processo duas vezes
			for (int i = 0; i < 5; i++) { //
				System.out.println();
				for (int j = 0; j < 5; j++) {
					matriz[i][j] = num.nextInt(100);
					if (matriz[i][j] % 2 == 0) { // se num é par preenche cômodo
													// com 0
						matriz[i][j] = 0;
					} else {
						matriz[i][j] = 1;
					}
					System.out.print("[" + matriz[i][j] + "]"); // exibe todos
																// os cômodos
				}
			}
			System.out.print("\n \n-- Executando a limpeza -- \n");
			Thread.sleep(2500);

			// Inicio da limpeza

			for (int i = 0; i < 5; i++) {
				System.out.println();
				for (int j = 0; j < 5; j++) {
					cont_quadrantes++;
					if (matriz[i][j] == 1) { // se for 1 esta sujo então limpa e
												// soma ao contador
						Thread.sleep(2000); // gasta 2 segundos para limpar

						matriz[i][j] = 0;
						cont_limpeza++;

						if (cont_quadrantes == 22 || cont_limpeza == 6) {
							Thread.sleep(3000); // 3 segundos pra recarregar ou
												// limpar o filtro
							cont_quadrantes = 0;
							cont_limpeza = 0;

						}

					}
					System.out.print("[" + matriz[i][j] + "]");
					Thread.sleep(250); // 1/4 de segundo para ir para o proximo
										// quadrante quando está limpo

				}
				//onde tem 1 é o que precisa limpar, por isso demora mais o processo. E quando precisa trocar
				//o filtro ou recarregar permanece no quadrante por mais segundos para recarregar  ou trocar o filtro
			}
			System.out.print("\n");
		}

		// Final da limpeza

		System.out.println();
		System.out.println("\nLimpeza concluída!\n");

	}
}