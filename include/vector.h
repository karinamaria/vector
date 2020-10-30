#ifndef VECTOR_H
#define VECTOR_H

/*!
 * @file vector.h
 * @brief Definição da classe vector.
 * @date 28 de Outubro de 2020
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
            using pointer = value_type*; //!< Ponteiro para o valor armazenado no container
            using reference = value_type&; //!< Referência para o valor armazenado no container
            using const_reference = const value_type&; //! Referência const para o valor armazenado no container

    	public:
    		// Iteradores
    	private:
            //== Membro da classe
            size_type m_size; //!< Quantidade de elementos no vetor.
            size_type m_capacity; //!< Capacidade de armazenamento do vetor.

            value_type *m_storage; //!< Área de armazenamento de dados para o vetor.

    	public:
            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------
            
            /// Construtor padrão, cria um vetor vazio.
            vector()
            {
            	m_capacity = 0;
            	m_storage = new value_type[m_capacity];
            	m_size = 0;
            }

            /// Construtor que recebe um tamanho para o vetor.
            explicit vector( size_type count )
            {
            	m_capacity = count;
            	m_storage = new value_type[m_capacity];
            	m_size = 0;
            }

            /// Construtor que recebe um range.
            template < typename InputIt >
            vector ( InputIt first, InputIt last )
            {
            	m_capacity = last-first;
                m_storage = new value_type[m_capacity];

            	for ( m_size = 0; m_size < m_capacity; ++m_size )
            		m_storage[m_size] = *first++;
            }

            /// Construtor de cópia.
            vector( const vector &other )
            {
            	
            }

            /// Construtor que recebe uma lista inicializadora.
            vector( const std::initializer_list<value_type> &ilist )
            {
            	m_capacity = ilist.size();
                m_storage = new value_type[m_capacity];

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

            /// Retorna `true` se o vetor não contém elementos e `false`, caso contrário
            bool empty( void ) const { return (m_size == 0); };

            
            //======================================================================
            //== Modificadores.
            //----------------------------------------------------------------------

            /// Remove (logicamente) todos elementos do vetor
            void clear(){
            	m_size = 0;
            }

            /// Adiciona o `value` ao início(index 0) do vetor.
            void push_front(const_reference value){
            	m_size++;

 				if(m_size > m_capacity){
 					reserve((m_capacity == 0) ? 2 : m_capacity * 2);
 				}
 				
 				//Trocando ordem dos elementos para deixar a posição do index zero vazia
 				for(size_type i=m_size-1; i>0; i--){
 					m_storage[i] = m_storage[i-1];
 				}
 	
 				m_storage[0] = value;
 	
            }

            /// Adiciona o `value` ao início(index 0) do vetor.
            void push_back(const_reference value){
            	m_size++;

 				if(m_size > m_capacity){
 					reserve((m_capacity == 0) ? 2 : m_capacity * 2);
 				}

 				m_storage[m_size-1] = value;
            }

            /// Remove o elemento do fim do vetor
            void pop_back(){
            	m_size --;
            }

            /// Remove o elemento da posição inicial(index 0) do vetor
            void pop_front(){
            	m_size --;

            	for(size_type i=0; i<m_size; i++){
            		m_storage[i] = m_storage[i+1];
            	}
            }

            /// Substitui o `value` a quantidade de vezes definida pelo `count`
            void assign(size_type count, const_reference value){
            	if(count > m_capacity){
 					reserve(count * 2);
 				}
 				m_size = count;
 				for(size_type i=0; i<m_size; i++){
 					m_storage[i] = value;
 				}
            }

            /// Aumenta a capacidade do vetor
            void reserve(size_type new_cap){
            	if(new_cap > m_capacity){
            		
 					T* new_array = new T[new_cap];

 					for(size_type i=0; i<m_size; i++){
 						new_array[i]=m_storage[i];
 					}

 					delete[] m_storage;
 					m_storage = new_array;
 					m_capacity = new_cap;
            	} 
            }

            //======================================================================
            //== Elementos de acesso
            //----------------------------------------------------------------------

            /// Retorna um objeto para o fim do vetor
            const_reference back() const{
            	return m_storage[m_size];
            }

            /// Retorna um objeto para o início do vetor
            const_reference front() const{
            	return m_storage[0];
            }

            /// Retorna o elemento na posição `pos`.
            /*!
             * @param pos Índice do elemento no vetor.
             * @return O valor na posição `pos`.
             * @throws std::out_of_range,  se `pos > size()`.
             */
            reference at (size_type pos){
            	if(pos > m_size){
            		throw std::out_of_range("Tentativa de leitura fora do vetor...");
            	}

            	return m_storage[pos];
            }

    };
}

#endif