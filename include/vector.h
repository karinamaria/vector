#ifndef VECTOR_H
#define VECTOR_H

#include "MyIterator.h"

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
            using const_reference = const value_type&; //!< Referência const para o valor armazenado no container
            using iterator = MyIterator<value_type>; //!< Iterator para o tipo de dado dos elementos do vetor.
            using const_iterator = MyIterator<const value_type>; //!< Iterator constante para o tipo de dado dos elementos do vetor.

        public:
            //======================================================================
            //== Métodos Iteradores
            //----------------------------------------------------------------------

            /// Iterador para o ínicio do vetor.
            iterator begin(void) { return iterator( &m_storage[0] ); }

            /// Iterador para o final lógico do vetor.
            iterator end(void) { return iterator( &m_storage[m_size] ); }

            /// Iterador constante para o ínicio do vetor.
            const_iterator cbegin(void) const { return const_iterator( &m_storage[0] ); }

            /// Iterador constante para o final lógico do vetor.
            const_iterator cend(void) const { return const_iterator( &m_storage[m_size] ); }
            
        private:
            //== Membro da classe
            size_type m_size; //!< Quantidade de elementos no vetor.
            size_type m_capacity; //!< Capacidade de armazenamento do vetor.

            pointer m_storage; //!< Área de armazenamento de dados para o vetor.

        public:
            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------

            /// Construtor padrão, cria um vetor com tamanho determinado pelo valor de `count`.
            explicit vector( size_type count = 0 ) : m_capacity{count}
            {
                m_storage = new value_type[m_capacity];
                m_size = 0;
            }

            /// Construtor que recebe um range.
            template < typename InputIt >
            vector ( InputIt first, InputIt last )
            {
                m_capacity = last-first;
                m_storage = new value_type[m_capacity];
                std::copy( first, last, begin() );
                m_size = m_capacity;
            }

            /// Construtor de cópia.
            vector( const vector &other )
            {
                m_capacity = other.size();
                m_storage = new value_type[m_capacity];
                std::copy( other.cbegin(), other.cend(), begin() );
                m_size = m_capacity;
            }

            /// Construtor que recebe uma lista inicializadora.
            vector( const std::initializer_list<value_type> &ilist )
            {
                m_capacity = ilist.size();
                m_storage = new value_type[m_capacity];
                std::copy( ilist.begin(), ilist.end(), begin() );
                m_size = m_capacity;
            }

            /// Construtor de movimentação, move os elementos de `other` para o vetor em construção.
            vector( vector &&other )
            {
                m_capacity = other.size();
                m_storage = new value_type[m_capacity];
                std::copy( other.cbegin(), other.cend(), begin() );
                m_size = m_capacity;

                other.clear();
                other.shrink_to_fit();
            }

            /// Destrutor.
            ~vector()
            {
                clear();
                delete[] m_storage;
                m_capacity = 0;
            }

            /// Atribui cópia dos elementos de um vetor a outro.
            vector& operator=( const vector& other )
            {
                clear();
                if (other.size() > m_capacity)
                    reserve(other.size());

                std::copy( other.cbegin(), other.cend(), begin() );
                m_size = other.size();

                return *this;
            }

            /// Movimenta os elementos de um vetor para outro.
            vector& operator=( vector&& other )
            {
                clear();
                if (other.size() > m_capacity)
                    reserve(other.size());

                std::copy( other.cbegin(), other.cend(), begin() );
                m_size = other.size();

                other.clear();
                other.shrink_to_fit();

                return *this;
            }

            /// Atribui os elementos de uma lista inicializadora ao vetor.
            vector& operator=( const std::initializer_list<value_type> &ilist )
            {
                clear();
                if (ilist.size() > m_capacity)
                    reserve(ilist.size());

                std::copy( ilist.begin(), ilist.end(), begin() );
                m_size = ilist.size();

                return *this;
            }

            //======================================================================
            //== Capacidade.
            //----------------------------------------------------------------------

            /// Retorna quantidade de elementos no vetor.
            size_type size( void ) const { return m_size; }

            /// Retorna a capacidade de armazenamento do vetor.
            size_type capacity( void ) const { return m_capacity; }

            /// Retorna `true` se o vetor não contém elementos e `false`, caso contrário
            bool empty( void ) const { return (m_size == 0); }

            
            //======================================================================
            //== Modificadores.
            //----------------------------------------------------------------------

            /// Remove (logicamente) todos elementos do vetor
            void clear(){ m_size = 0;}

            /// Adiciona o `value` ao início(index 0) do vetor.
            void push_front(const_reference value){
                if(m_size >= m_capacity)
                    reserve(m_capacity*2);
                
                //Trocando ordem dos elementos para deixar a posição do index zero vazia
                for(size_type i=m_size; i>0; i--)
                    m_storage[i] = m_storage[i-1];
    
                m_storage[0] = value;
                ++m_size;
            }

            /// Adiciona o `value` ao início(index 0) do vetor.
            void push_back(const_reference value){
                if(m_size >= m_capacity)
                    reserve(m_capacity*2);

                m_storage[m_size] = value;
                ++m_size;
            }

            /// Remove o elemento do fim do vetor
            void pop_back(){ m_size --; }
        

            /// Remove o elemento da posição inicial(index 0) do vetor
            void pop_front(){
                m_size--;

                for(size_type i=0; i<m_size; i++)
                    m_storage[i] = m_storage[i+1];
            }

            /// Adiciona `value` ao vetor antes da posição fornecida pelo iterador `pos`
            iterator insert( iterator pos, const_reference value )
            {
                auto index = size_type(pos-begin());

                if(index > size()){
                    throw std::out_of_range("Tentativa de escrita fora do vetor...");
                }

                reserve(size()+1);

                iterator last = end();
                iterator p = begin()+index;
                
                while(last != p) {
                   *last  = *(last - 1);
                   --last;
                }
    
                ++m_size;
                *p=value;

                return p;
            }

            template < typename InItr >
            /// Insere elementos do intervalo `[first; last)` antes da `pos`.
            iterator insert( iterator pos, InItr first, InItr last )
            {
                auto index = size_type(pos-begin());

                if(index > size()){
                    return pos;
                }

                auto sizeFirstLast = size_type(last - first);
                
                if(sizeFirstLast > size())
                    reserve(sizeFirstLast+size());
         
                while(last != first ){
                    pos = insert(pos, *(last-1));
                    --last;
                }

                return pos;
            }

            iterator insert( iterator pos, const std::initializer_list<value_type>& ilist )
            {
                auto index = size_type(pos-begin());
                
                if(index > size()){
                    return pos;
                }
                size_type ilist_size = ilist.size();

                reserve( ilist_size+size() );

                auto first = ilist.begin();
                
                auto f = begin()+index;
                auto l = end()-1;
                for(auto i=l; i!=f; i--){
                    *(i+ilist_size) = *(i);
                }

                for(size_type i=index; i<=ilist_size+1; i++){
                    m_storage[i] = *(first);
                    ++first;
                }

                m_size = ilist_size+size();

                return pos;
            }

            /// Aumenta a capacidade do vetor
            void reserve(size_type new_cap){
                if(new_cap > capacity()){
                    pointer new_array = new value_type[new_cap];

                    for(size_type i=0; i<m_size; i++)
                        new_array[i]=m_storage[i];
                    

                    delete[] m_storage;
                    m_storage = new_array;
                    m_capacity = new_cap;
                }
            }

            /// Reduz o a capacidade `m_capacity` para quantidade de elementos`m_size`
            void shrink_to_fit( void ){ m_capacity = m_size;}

            /// Substitui o `value` a quantidade de vezes definida pelo `count`
            void assign( size_type count, const_reference value )
            {
                if(count > m_capacity)
                    reserve(count);

                m_size = count;
                
                for(size_type i=0; i<m_size; i++)
                    m_storage[i] = value;
            }

            /// Remove do vetor o elemento em `pos`.
            iterator erase( iterator pos ) {
                iterator p{pos};
                while(pos != end()-1) {
                    *pos = *(pos+1);
                    ++pos;
                }
    
                --m_size;
                return p;
            }

            /// Remove do vetor os elementos no intervalo [first, last).
            iterator erase( iterator first, iterator last ) {
                iterator p{first};
                size_type diff = last-first;

                while(last != end()) {
                    *first = *(first+diff);
                    ++last;
                    ++first;
                }
                m_size -= diff;

                return p;
            }

            /// Substitui o conteúdo do vetor por cópias dos elementos no intervalo [first, last).
            template < typename InItr >
            void assign( InItr first, InItr last ) {
                auto size = last-first;
                
                if(size > m_capacity)
                    reserve(size);
                
                m_size = size;
                std::copy( first, last, begin() );
            }

            /// Substitui o conteúdo do vetor pelos elementos da lista inicializadora `ilist`.
            void assign( const std::initializer_list<value_type>& ilist ) {
                if(ilist.size() > m_capacity)
                    reserve(ilist.size());

                m_size = ilist.size();
                std::copy( ilist.begin(), ilist.end(), begin() );
            }

            //======================================================================
            //== Elementos de acesso
            //----------------------------------------------------------------------

            /// Retorna um objeto para o fim do vetor
            const_reference back() const { return *(--cend()); }

             /// Retorna o elemento na posição `pos`.
            reference back( void ) { return *(--end()); }

            /// Retorna um objeto para o início do vetor
            const_reference front() const { return *cbegin(); }

            /// Retorna o elemento na posição `pos`.
            reference front( void ){ return *begin(); }

            /// Retorna um objeto para para a posição `pos` do vetor
            const_reference operator[]( size_type pos) const
            {
                if(pos >= m_size)
                    throw std::out_of_range("Tentativa de leitura fora do vetor...");
                
                return m_storage[pos];
            }

            /// Retorna o elemento na posição `pos`.
            reference operator[]( size_type pos )
            {
                if(pos >= m_size)
                    throw std::out_of_range("Tentativa de leitura fora do vetor...");
                
                return m_storage[pos];
            }

            /// Retorna um objeto para posição `pos`.
            /*!
             * @param pos Índice do elemento no vetor.
             * @return O valor na posição `pos`.
             * @throws std::out_of_range,  se `pos > size()`.
             */
            const_reference at( size_type pos ) const
            {
                if(pos >= m_size)
                    throw std::out_of_range("Tentativa de leitura fora do vetor...");

                return m_storage[pos];
            }

            /// Retorna o elemento na posição `pos`.
            /*!
             * @param pos Índice do elemento no vetor.
             * @return O valor na posição `pos`.
             * @throws std::out_of_range,  se `pos > size()`.
             */
            reference at( size_type pos )
            {
                if(pos >= m_size)
                    throw std::out_of_range("Tentativa de leitura fora do vetor...");

                return m_storage[pos];
            }

            /// Verifica se dois vetores são iguais
            //bool operator== (const vector& rhs)
            friend bool operator== ( const vector& lhs, const vector& rhs )
            {
                if(lhs.size() == rhs.size()){
                    for(size_type i=0; i<lhs.size(); i++){
                        if(lhs[i] != rhs[i])
                            return false;
                    }
                    return true;
                }
                return false;
            }

            /// Verifica se dois vetores são diferentes
            friend bool operator!=( const vector& lhs, const vector& rhs )
            {
                if(lhs.size() == rhs.size()){
                    for(size_type i=0; i<lhs.size(); i++){
                        if(lhs[i] != rhs[i])
                            return true;
                    }
                    return false;
                }
                return true;
            }

            /// Retorna um ponteiro para o primeiro elemento do vetor
            pointer data( void ){ return begin(); }

            /// Retorna um objeto para o primeiro elemento do vetor
            const_reference data( void ) const { return begin();}


            //======================================================================
            //== Funções friend.
            //----------------------------------------------------------------------

            friend std::ostream& operator<<( std::ostream& os, const vector<T>& v)
            {
                os << "[";
                for (size_type i = 0; i < v.size(); ++i)
                {
                    os << " " << v[i];
                }
                os << " ]";
                return os;
            }

            friend void swap( vector& v1, vector& v2 )
            {
                vector<value_type> other(v1);

                v1 = v2;
                v2 = other;
            }
    };
}

#endif