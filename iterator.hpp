#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "./iterator_traits.hpp"


namespace ft {
    template <class T>
    struct iterator {
        public:
            typedef typename iterator_traits<T*>::iterator_category    iterator_category;
            typedef typename iterator_traits<T*>::value_type           value_type;
            typedef typename iterator_traits<T*>::difference_type      difference_type;
            typedef typename iterator_traits<T*>::pointer              pointer;
            typedef typename iterator_traits<T*>::reference            reference;

        public:
            iterator() {};
            iterator(const iterator& it) {*this = it;};
            iterator(pointer it) {
                this->_itr_ptr = it;
            };
            iterator& operator = (const iterator& it) {
                this->_itr_ptr = it._itr_ptr;
                return *this;
            };


            // overload member functions
            // access operators
            reference operator * () const {return *_itr_ptr;}
            pointer operator -> () const {return _itr_ptr;}
            reference operator[] (difference_type n) const {return *(_itr_ptr + n);};

            // pre/post increment operators
            iterator operator ++ () {++_itr_ptr; return *this;}
            iterator& operator ++ (int) {iterator *tmp = new iterator(*this); _itr_ptr++; return *tmp;}
            iterator operator -- () {--_itr_ptr; return *this;}
            iterator& operator -- (int) {iterator *tmp = new iterator(*this); _itr_ptr--; return *tmp;}


            // comparison operators
            bool operator != (const iterator &it) {return this->_itr_ptr != it._itr_ptr;}
            bool operator == (const iterator &it) {return this->_itr_ptr == it._itr_ptr;}
            bool operator > (const iterator &it) {return this->_itr_ptr > it._itr_ptr;}
            bool operator < (const iterator &it) {return this->_itr_ptr < it._itr_ptr;}
            bool operator >= (const iterator &it) {return this->_itr_ptr >= it._itr_ptr;}
            bool operator <= (const iterator &it) {return this->_itr_ptr <= it._itr_ptr;}

            // arithmatic operators
            iterator operator + (difference_type n) {iterator tmp(_itr_ptr); tmp._itr_ptr += n; return tmp;}
            iterator operator - (difference_type n) {iterator tmp(_itr_ptr); tmp._itr_ptr -= n; return tmp;}
            difference_type operator - (iterator &it) {return _itr_ptr - it._itr_ptr;}
            iterator& operator += (difference_type n) {_itr_ptr += n; return *this;}
            iterator& operator -= (difference_type n) {_itr_ptr -= n; return *this;}

            friend iterator operator+(difference_type n, const iterator& it) {return iterator(it._itr_ptr + n);}

            // still in progress

            // *a++
            // *a--
            // *a = t

        private:
            pointer _itr_ptr;
    };
};

#endif