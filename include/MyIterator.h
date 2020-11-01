#ifndef MYITERATOR_H
#define MYITERATOR_H

/*!
 * @file MyIterator.h
 * @brief Definição da classe MyIterator.
 * @date 30 de Outubro de 2020
 * @author Karina Maria
 * @author Maria Eduarda
 */

 /*!
 * Essa classe implementa um iterator para o sc::vector.
 * @tparam T Tipo de dado para o qual o iterator aponta.
 */
template < typename T >
class MyIterator {
	public:
		typedef std::ptrdiff_t difference_type; //!< Tipo de dado usado para expressar a distância entre iteradores.
		typedef T value_type; //!< Tipo de dado para o qual o iterador aponta.
		typedef T* pointer; //!< Ponteiro para o tipo de dado.
		typedef T& reference; //!< Referência para o tipo de dado.
		typedef std::bidirectional_iterator_tag iterator_category; //!< Categoria do iterador.

		//======================================================================
                //== Métodos Especiais.
                //----------------------------------------------------------------------

                /// Construtor padrão.
		MyIterator( value_type *other = nullptr ) : m_ptr{other} { /**/ }
                /// Construtor que recebe um endereço.
		MyIterator( const MyIterator& ) = default;

		//======================================================================
                //== Sobrecarga de operadores.
                //----------------------------------------------------------------------

                /// Atribui um iterador a outro.
                MyIterator& operator=( const MyIterator& ) = default;

                /// Retorna uma referência ao objeto localizado na posição apontada pelo iterador.
		reference operator*() const { return *m_ptr; }
                /// Retorna ponteiro encapsulado na classe.
		pointer operator->( void ) const { assert( m_ptr != nullptr); return m_ptr; }

                /// Avança o iterador em uma posição (pré-incremento).
		MyIterator& operator++() { m_ptr++; return *this; }
                /// Avança o iterador em uma posição (pós-incremento).
		MyIterator operator++( int ) { MyIterator other{*this}; m_ptr++; return other; }
                /// Decresce o iterador em uma posição (pré-decremento).
		MyIterator& operator--() { m_ptr--; return *this; }
                /// Decresce o iterador em uma posição (pós-decremento).
		MyIterator operator--( int ) { MyIterator other{*this}; m_ptr--; return other; }

                /// Verifica se dois iteradores são iguais.
		bool operator==( const MyIterator &other ) const { return m_ptr==other.m_ptr; }
                /// Verifica se dois iteradores são diferentes.
		bool operator!=( const MyIterator &other ) const { return not(m_ptr==other.m_ptr); }

		//======================================================================
                //== Funções friend.
                //----------------------------------------------------------------------

                /// Retorna a diferença entre dois iteradores.
                friend long operator-( MyIterator value1, MyIterator value2 )
                {
                        long count{0};
                        while (true) {
                                if( (value1+count) == value2 ) { return -count; }
                                if( (value1-count) == value2 ) { return count; }
                                ++count;
                        }
                }

                /// Retorna um iterador apontando para o enésimo sucessor no vetor apartir de `other`.
                friend MyIterator operator+( difference_type diff, MyIterator other )
                { 
                	while (diff > 0) {
                		++other;
                		--diff;
                	}
        		return other;
		}

                /// Retorna um iterador apontando para o enésimo sucessor no vetor apartir de `other`.
                friend MyIterator operator+( MyIterator other, difference_type diff )
                {
                	while (diff > 0) {
                		++other;
                		--diff;
                	}
        		return other;
                }

                /// Retorna um iterador apontando para o enésimo antecessor no vetor apartir de `other`.
                friend MyIterator operator-( difference_type diff, MyIterator other )
                {
                	while (diff > 0) {
                		--other;
                		--diff;
                	}
        		return other;
                }

                /// Retorna um iterador apontando para o enésimo antecessor no vetor apartir de `other`.
                friend MyIterator operator-( MyIterator other, difference_type diff )
                {
			while (diff > 0) {
                		--other;
                		--diff;
                	}
        		return other;
                }

	private:
		//== Membro da classe
		value_type *m_ptr; //!< Ponteiro regular, que fica encapsulado na classe.
};

#endif