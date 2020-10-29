#ifndef VECTOR_H
#define VECTOR_H

/*!
 * @file vector.h
 * @brief Definição da classe vector.
 * @date October 28th, 2020
 * @author Karina Maria
 * @author Maria Eduarda
 */
namespace sc {
	 /*!
     * Essa classe representa um vetor dinâmico genérico do C++, que é um tipo
     * de **container sequencial**.
     * @tparam T Tipo de dado que será amazenado no array.
     */
    template < typename T >
    class vector {
    	public:
            // Apelidos para os tipos
    		using size_type = unsigned long; //!< O tipo do tamanho.
    		using value_type = T; //!< O tipo de dado dos elementos do vetor.

    	public:
    		// Iteradores
    	private:
            //== Membro da classe
            size_type m_size; //!< Quantidade de elementos no vetor.
            size_type m_capacity; //!< Capacidade de armazenamento do vetor.

            T *m_storage; //!< Área de armazenamento de dados para o vetor.

    	public:
            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------
            
            /// Construtor padrão, cria um vetor vazio.
            vector()
            {
            	m_capacity = 0;
            	m_storage = new T[m_capacity];
            	m_size = 0;
            }

            /// Construtor que recebe um tamanho para o vetor.
            explicit vector( size_type count )
            {
            	m_capacity = count;
            	m_storage = new T[m_capacity];
            	m_size = 0;
            }

            /// Construtor que recebe um range.
            template < typename InputIt >
            vector ( InputIt first, InputIt last )
            {
            	m_capacity = last-first;
                m_storage = new T[m_capacity];

            	for ( m_size = 0; m_size < m_capacity; ++m_size )
            		m_storage[m_size] = *first++;
            }

            /// Construtor de cópia.
            vector( const vector &other )
            {
            	
            }

            /// Construtor que recebe uma lista inicializadora.
            vector( const std::initializer_list<T> &ilist )
            {
            	m_capacity = ilist.size();
                m_storage = new T[m_capacity];

            	auto ilptr = ilist.begin();

            	for ( m_size = 0; m_size < m_capacity; ++m_size )
            		m_storage[m_size] = *ilptr++;
            }

            /// Destrutor.
            ~vector()
            {
            	//clear();
            	delete[] m_storage;
            	m_capacity = 0;
            }

            //======================================================================
            //== Capacidade.
            //----------------------------------------------------------------------

            /// Retorna quantidade de elementos no vetor.
            size_type size( void ) const { return m_size; };

            /// Retorna a capacidade de armazenamento do vetor.
            size_type capacity( void ) const { return m_capacity; };

            /// Verifica se o vetor não possui elementos.
            bool empty( void ) const { return (m_size == 0); };

            
            //======================================================================
            //== Modificadores.
            //----------------------------------------------------------------------

            /// Apaga todos os elementos do vetor.
            /*void clear()
            {
            	for ( int i{0}; i < m_size; ++i )
            		~m_storage[i]();

            	m_size = 0;
            }*/
    };
}

#endif