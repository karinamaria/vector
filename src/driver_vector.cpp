/*!
 * @file driver_vector.cpp
 * @brief Programa de uso temporário para teste do vector.
 * @date 28 de Outubro de 2020
 * @author Karina Maria
 * @author Maria Eduarda
 */

#include <iostream>

#include "../include/vector.h"

using namespace sc;

int main(){
	vector<int> a;

	a.assign(8,2);

	vector<int> b;
	b.assign(9,2);

	std::cout << "Os vetores são iguais: " << (a==b) << "."<< std::endl;

	std::cout <<"Quantidade: " <<  a.size() << std::endl;
	std::cout << "Elementos" << std::endl;

	for(size_t i=0; i<a.size(); i++){
		std::cout << a.at(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}