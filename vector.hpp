#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>
#include <cmath>

// implement is_integral

namespace ft {
    template<bool b, typename T = void>
    struct enable_if {typedef T type;};

    template<typename T>
    struct enable_if<false, T> {};

    template <class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            typedef T                                   value_type;
            typedef Allocator                           allocator_type;
            typedef typename std::size_t                size_type;
            typedef typename std::ptrdiff_t             difference_type;
            typedef value_type&                         reference;
            typedef const value_type&                   const_reference;
            typedef typename Allocator::pointer         pointer;
            typedef typename Allocator::const_pointer   const_pointer;
            typedef typename ft::iterator<value_type>   iterator;
            // typedef const_iterator;
            // typedef std::reverse_iterator<iterator>       reverese_iterator;
            // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

            explicit vector (const allocator_type& alloc = allocator_type())
            :_ptr(NULL), _size(0), _capacity(0), _alloc(alloc){}

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            :_ptr(NULL), _size(n), _capacity(n), _alloc(alloc) {
                if (_size > 0) {
                    _ptr = _alloc.allocate(_size);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(_ptr + i, val);
                }
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename enable_if<!std::is_integral<InputIterator>::value>::type * = 0) {
                _size = last - first;
                _capacity = _size;
                _alloc = alloc;

                if (_size > 0) {
                    _ptr = _alloc.allocate(_size);
                    for (size_type i = 0; i < _size; i++) {
                        _alloc.construct(_ptr + i, *first);
                        first++;
                    }
                }
            }

            vector (const vector& x) {
                *this = x;
            };

            vector& operator= (const vector& x) {
                this->_size = x._size;
                this->_capacity = x._capacity;
                this->_alloc = x._alloc;
                this->_ptr = x._ptr;

                return *this;
            };

            void print() {
                for (size_type i = 0; i < _size; i++) {
                    std::cout << *(_ptr + i) << " ";
                }
                std::cout << std::endl;
            }
            // member function
            iterator begin() {
                return _ptr;
            }
            iterator end() {
                return _ptr + _size;
            }

            // capcity
            bool empty() const { if (_size == 0) return true; else return false;}
            size_type size() const { return _size;}
            size_type max_size() const {return std::numeric_limits<difference_type>::max();}
            size_type capacity() const {return _capacity;}
            void reserve(size_type n) {
                if (n > max_size())
                    throw std::length_error("cannot allocate more than max_size elements");
                if (n > _capacity) {
                    _capacity = n;
                    try {
                        pointer tmp_ptr = _alloc.allocate(_capacity);
                        for (size_type i = 0; i < _size; i++) {
                            _alloc.construct(tmp_ptr + i, _ptr[i]);
                        }
                        // this->clear();
                        _alloc.deallocate(_ptr, _size); 
                        _ptr = tmp_ptr;
                    } catch (std::bad_alloc &err) {
                        std::cout << err.what() << std::endl;
                    }
                }
            }

            // Element access
            reference operator[](size_type n) {return *(_ptr + n);}
            const_reference operator[](size_type n) const {return *(_ptr + n);};
            reference front() {return *_ptr;};
            const_reference front() const {return *_ptr;};
            reference back() {return *(_ptr + _size - 1);};
            const_reference back() const {return *(_ptr + _size - 1);};
            // pointer data() {return _alloc.data();};
            // const_pointer data() const {std::cout << "const" << std::endl;return _alloc.data();};

            // // Iterators
            // iterator begin();
            // const_iterator begin() const; 
            // const_iterator rbegin() const;
            // iterator end();
            // const_iterator end() const;
            // const_iterator rend() const;


            // Modifiers
            void clear() {
                for (int i = 0; i < _size; i++)
                    _alloc.destroy(_ptr + i);

                _size = 0;
            }

            iterator erase (iterator position) {
                iterator tmp_ptr = this->end();
                
                int index = _size - (this->end() - position);

                if (index == -1)
                    return (this->begin());

                _alloc.destroy(_ptr + index);
                _size--;
                for(int i = index; i < _size; i++)
                    _alloc.construct(_ptr + i, *(_ptr + i + 1));
                

                return _ptr + index;
            };

            iterator erase (iterator first, iterator last) {
                int f_idx = _size - (this->end() - first);
                int l_idx = (last - first) + f_idx;

                _size -= l_idx - f_idx;

                for (int i = f_idx; i < l_idx; i++) {
                    _alloc.destroy(_ptr + i);
                }

                for(int i = f_idx; i < _size; i++) {
                    _alloc.construct(_ptr + i, *(_ptr + i + l_idx - f_idx));
                }

                return _ptr + f_idx;
            };

            iterator insert (iterator position, const value_type& val) {
                int index = _size - (this->end() - position);

                if (_size >= _capacity)
                    this->reserve(_capacity * 2);

                if (_size < _capacity) {
                    for (int i = _size ; i > index; i--)
                        _alloc.construct(_ptr + i, *(_ptr + i - 1));
                }
                _size++;
                _alloc.construct(_ptr + index, val);

                return _ptr + index;
            };
            // void insert (iterator position, size_type n, const value_type& val);
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last);

            void push_back (const value_type& val) {
                if (_size >= _capacity)
                    this->reserve(_size * 2);
 
                _alloc.construct(_ptr + _size, val);
                _size++;
            };

            void pop_back() {
                _alloc.destroy(_ptr + _size - 1);
                _size--;
            };

            void resize (size_type n, value_type val = value_type()) {
                if (n > _capacity)
                    this->reserve(_capacity * 2 > n ? _capacity * 2: n);

                if (n < _size) {
                    _size = n;
                    _alloc.destroy(_ptr + _size);
                } else if (n > _size) {
                    for (int i = _size; i < n; i++)
                        _alloc.construct(_ptr + i, val);
                    
                    _size = n;
                }
            };


            // non member functions 
            void swap (vector& x);

            ~vector() {}
        private:
            pointer _ptr;
            size_type _size;
            size_type _capacity;
            Allocator _alloc;
    };
}; 

#endif