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

		MyIterator( value_type *other = nullptr ) : m_ptr{other} { /**/ }
		MyIterator( const MyIterator& ) = default;

		//======================================================================
        //== Sobrecarga de operadores.
        //----------------------------------------------------------------------

        MyIterator& operator=( const MyIterator& ) = default;

		reference operator*() const { return *m_ptr; }
		pointer operator->( void ) const { assert( m_ptr != nullptr); return m_ptr; }

		MyIterator& operator++() { m_ptr++; return *this; } //++it;
		MyIterator operator++( int ) { MyIterator other{*this}; m_ptr++; return other; } //it++;
		MyIterator& operator--() { m_ptr--; return *this; } //--it;
		MyIterator operator--( int ) { MyIterator other{*this}; m_ptr--; return other; } //it--;

		bool operator==( const MyIterator &other ) const { return m_ptr==other.m_ptr; }
		bool operator!=( const MyIterator &other ) const { return not(m_ptr==other.m_ptr); }

		//======================================================================
        //== Funções friend.
        //----------------------------------------------------------------------

        friend MyIterator operator+( difference_type diff, MyIterator other )
        { 
        	while (diff > 0) {
        		++other;
        		--diff;
        	}
			return other;
		}

        friend MyIterator operator+( MyIterator other, difference_type diff )
        {
        	while (diff > 0) {
        		++other;
        		--diff;
        	}
			return other;
        }

        friend MyIterator operator-( difference_type diff, MyIterator other )
        {
        	while (diff > 0) {
        		--other;
        		--diff;
        	}
			return other;
        }

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