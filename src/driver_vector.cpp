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
	/**vector<int> a{1,2,4};
	try{
       std::cout << a[0] << std::endl;
    } 
    catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
	a.assign(8,2);

	vector<int> b;
	b.assign(7,2);

	
	std::cout << "Os vetores são diferentes: " << (a!=b) << "."<< std::endl;

	std::cout <<"Tamanho vetor a: " <<  a.size() << std::endl;
	std::cout << "Elementos vetor a" << std::endl;

	for(size_t i=0; i<a.size(); i++){
		std::cout << a.at(i) << " ";
	}
	std::cout <<"\n---------------" << std::endl;

	std::cout <<"Tamanho vetor b: " <<  b.size() << std::endl;
	std::cout << "Elementos vetor b" << std::endl;

	for(size_t i=0; i<b.size(); i++){
		std::cout << b.at(i) << " ";
	}
	std::cout << std::endl;**/

	sc::vector<int> vec1 { 1, 2, 3, 4, 5 };
    sc::vector<int> vec2 { 1, 2, 3, 4, 5 };
    sc::vector<int> source { 6, 7, 8, 9, 10 };

    vec1.insert( vec1.begin(), source.begin(), source.end() );
    std::cout << "[ ";
    for(size_t i=0; i<vec1.size(); i++){
		std::cout << vec1.at(i) << " ";
	}
	std::cout << " ]"<< std::endl;
	return 0;
}