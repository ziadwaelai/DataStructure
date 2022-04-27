#include <iostream>
#include<list>
#include<algorithm>
using namespace std;
template <typename t>
/** \brief
 * Node class
 * to use it in all program
 * it has a default constructor and pointing to NULL
 * parameterize constructor and passing data and next through the pointer ptr
 */

class node{
public:
    t info;
    node<t> *next;
    node() : next(nullptr) {}
    node(const t& item, node<t> *ptr = nullptr) : info(item), next(ptr) {}
};
template <class type>
class myList{
private:
    node<type>* head_;
    node<type>* tail_;
    type value_;
    int initial_size_;
public:
    /*
    default constructor
    */
    myList() {
        // create the dummy head node
        head_ = tail_ = new node<type>();
    }
    myList(type value, int initial_size) : value_(value), initial_size_(initial_size) {}
    /*
    Destructor to clear list data
    */
    ~myList() {
        while (head_->next != nullptr){
            node<type>* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        delete head_;
    }
    /*
    return the current size of list
    */
    int size(node<type> *first) {
        int counter = 0;
        node<type> *current = first;
        while (current != nullptr){
            counter++;
            current = current->next;
        }
        return counter;
    }
    /** \brief
     * an inner iterator class
     */
    class iterator{
    private:
        node<type> *current_;
    public:
        iterator() : current_(nullptr) {}
        iterator(node<type> *new_ptr) : current_(new_ptr) {}
        /** \brief
         * overloading the operator ++ postfix and prifix
         * overloading the dereference operator (*) to return the value
         * contained in the current node
         * overloading the equality comparison operator ( == )
         *
         */

        // prifix ++
         operator++() {
            ++current_;
            return *this;
        }
        // postfix ++
        iterator& operator++(int) {
            current_++;
            return *this;
        }
        // prifix --
        iterator& operator--() {
            --current_;
            return *this;
        }
        iterator& operator--(int) {
            current_--;
            return *this;
        }
        // deference operator *
        type& operator*() const {return current_->next->info;}
        // equality comparison ==
        bool operator==(const iterator& it) {return current_ = it.current_;}
        bool operator!=(const iterator& it) {return current_ = it.current_;}
    };
    // iterator pointing to the first element
    iterator begin() const {return iterator(head_);}
    // iterator pointing to the last element
    iterator end() const {return iterator(tail_);}
    /*
    overloading assignment operator =
    to copy a list into another one and return the current list
    */
    myList<type>& operator=(myList<type> another_list) {
        another_list.swap(*this);
        return *this;
    }
    /*
    adding a value at specific position with specified operator
    */
     insert(iterator position, type value) {
        node<type> *new_node = new node<type>(value, position.current_->next);
        if (position.current_ == tail_){
            tail_ = new_node;
            position.current_->next = new_node;
            return position;
        }
    }
    /*
    deleting a value with specified operator
    */
    iterator erase(iterator position){
        node<type> *toErase = position.current_->next;
        if (toErase == tail_) {
            tail_ = position.current_;
            delete toErase;
            return position;
        }
    }
};
int main()
{
    list<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    myList.push_back(7);
    myList.push_back(8);
    myList.push_back(9);
    for (auto itr = myList.begin(); itr != myList.end(); ++itr){
        cout << *itr << "  ";
    }
    cout << "\n--------------------------\n\n";
    cout << "Size of List = " << myList.size() << endl;
    list<int>::iterator it1 = myList.begin();
    cout << "Begin -> " << *it1 << endl; // 1
    it1++; // -> 2
    cout << "Second Position -> " << *it1 << endl;
    list<int>::iterator it2 = myList.end();
    cout << "End -> " << *it2 << endl << endl;
    myList.insert(it1, 4); // insert 4 at position 2
    myList.insert(it1++, 7);// insert 7 at position 3
    myList.insert(it1, 5);
    myList.insert(it1++, 6);
    myList.erase(it1); // delete the value contained in position 3
    cout << *it1 << " Erased\n";
    cout << "\nThe List After Inserting and Erasing: \n\n--------------------------\n\n";
    for (auto itr = myList.begin(); itr != myList.end(); ++itr){
        cout << *itr << "  ";
    }
    cout << endl;
    cout << "Size of List = " << myList.size() << endl;
}
