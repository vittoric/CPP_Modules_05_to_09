#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque> // std::stack is often implemented using std::deque by default
#include <iterator> // For iterator tags if needed, and base iterator types

// By default, std::stack uses std::deque as its underlying container.
// The iterators of std::deque are random access iterators.
// We need to expose these iterators.

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Constructors and Destructor
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }
    // No explicit destructor needed as std::stack handles its members.
    // ~MutantStack() {} // Default is fine

    // Expose the underlying container's iterator types
    // The underlying container is accessible via a protected member 'c' in std::stack.
    // To access 'c', we'd ideally need a friend class or a "getter" if std::stack provided one.
    // However, std::stack is designed to be restrictive.
    // A common way to get iterators for std::stack is to expose the iterators
    // of its underlying container. Since 'c' is protected, this class (MutantStack)
    // can access it.

    // Typedefs for iterator types
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Iterator methods
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

// If any template member functions were defined outside the class, they would go into MutantStack.tpp
// For example, if iterators were more complex and defined outside.
// However, these simple forwarding iterator methods are typically defined inline within the class.
// So, MutantStack.tpp might not be strictly necessary for this particular class structure,
// unless specific coding standards of a project demand all template implementations in .tpp.
// Given the Makefile includes it, we can create an empty MutantStack.tpp or one with guards.

#endif // MUTANTSTACK_HPP
