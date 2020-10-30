/*!
 * @file driver_vector.cpp
 * @brief Programa de uso temporário para teste do vector.
 * @date October 28th, 2020
 * @author Karina Maria
 * @author Maria Eduarda
 */

#include <iostream>

#include "../include/vector.h"

using namespace sc;

int main(){
	vector<int> a;

	a.push_back(3);
	a.push_front(10);
	a.push_front(40);
	a.push_back(50);

	a.assign(8,2);

	std::cout <<"Quantidade: " <<  a.size() << std::endl;
	std::cout << "Elementos" << std::endl;

	for(size_t i=0; i<a.size(); i++){
		std::cout << a.at(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}