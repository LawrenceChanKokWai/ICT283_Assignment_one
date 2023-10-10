
/**
 * @file Vector.h
 * @brief Vector class definition.
 *
 * This file contains the definition of the Vector class.
 * The class allows getting, and retrieving the capacity, the used spaces and the address of the dynamic array.
 * It as well resizes the vector when its meets the condition upon appending the elements.
 * Deep copying has been applied by using a destructor, copy constructor, and the overload equals operator.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/**
* @brief A constant initial value of the dynamic array's capacity.
*
*/
const unsigned INITIAL_VALUE = 2;

template<class T>
class Vector
{
public:

    /**
    * @brief Default constructor for Vector class.
    *
    * This constructor creates a Vector object with default values for
    * capacity set as 2,
    * used slot set 0,
    * array pointer pointing to a new created array in the heap with capacity of 2.
    *
    */
    Vector();

    /**
    * @brief Destructor for Vector class.
    *
    * This destructor deletes the dynamic array in the heap and set pointer to nullptr.
    */
    ~Vector();

    /**
    * @brief Get the capacity space allocated in the heap of the dynamic array.
    *
    * This member function allows retrieving the capacity allocated in the heap.
    *
    * @return A constant unsigned data type of the capacity allocated in the heap for the dynamic array.
    */
    unsigned GetCapacity() const;

    /**
    * @brief Get the used space of the stored element in the dynamic array.
    *
    * This member function allows retrieving the used space allocated in the dynamic array.
    *
    * @return A constant unsigned data type of the used space allocated in the the dynamic array.
    */
    unsigned GetUsed() const;

    /**
    * @brief Get the address of the 1st index point that the pointer is pointing at on the dynamic array.
    *
    * This member function allows retrieving the address of the 1st index point of the dynamic array allocated in the dynamic array.
    *
    * @return A T type data type of the address of the 1st index of the dynamic array.
    */
    T *GetArray() const;

    /**
    * @brief Copy constructor that copies initialized current vector to this newly created vector.
    *
    * This member function allows copying the current vector to another newly created vector.
    *
    * @param initializer A current initialized vector that will be used to be copied from.
    */
    Vector(const Vector<T> &initializer);

    /**
    * @brief Overload equal operator for copying another current vector to this vector.
    *
    * This member function allows copying another vector to be equals or set to this vector.
    *
    * @param rhs a reference alias referring to the vector used to be copied from.
    * @return the de-reference of this copied vector.
    */
    Vector &operator = (const Vector<T> &rhs);

    /**
    * @brief Copy function that copies the elements to the current array to the new array.
    *
    * This member function allows copying to another array.
    *
    * @param rhs a reference alias referring to the array created used to be copied to.
    */
    void Copy(const Vector &rhs);

    /**
    * @brief Adds an element to the vector.
    * Checks for used slot is equals to half the size of the capacity, and will call the Resize function.
    * And updates the m_array[m_used] to the value element, updates the used space incrementing by 1.
    *
    * This member function allows adding a element to the vector / dynamic array.
    *
    * @param value The value that is used to be appended into the dynamic array.
    * @return A boolean value of true or false if the element has been appended in the dynamic array.
    */
    bool Append(const T &value);

    /**
    * @brief Get an element value from the vector with a index number.
    *
    * This member function allows adding returning back the element value of a given index in the dynamic array.
    *
    * @param index The index of the dynamic array that is used for returning the value.
    * @return The value of the element in the dynamic array of that index.
    */
    T &GetValueByIndex(unsigned index) const;

private:
    unsigned m_capacity;
    unsigned m_used;
    T *m_array;

    /**
    * @brief Its resizes the capacity and is used in the append function.
    *
    * This member function allows doubling the capacity when used slots in the dynamic array is half of the capacity size.
    * copies the elements, the capacity and used slots to a newly created array.
    * deletes the current pointer and sets back when new array has been copied. Lastly, deletes the new array.
    */
    void Resize();
};

/* Default Constructor */
template<class T>
Vector<T>::Vector()
{
    m_capacity = INITIAL_VALUE;
    m_used = 0;
    m_array = new T[INITIAL_VALUE];
}

/* Destructor */
template<class T>
Vector<T>::~Vector()
{
    if(m_array != nullptr)
    {
        delete [] m_array;
    }
    m_array = nullptr;
}

/* Copy Constructor */
template<class T>
Vector<T>::Vector(const Vector<T> &initializer)
{
    Copy(initializer);
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
{
    if (this != &rhs)
    {
        delete[] m_array;
        Copy(rhs);
    }
    return *this;
}

template<class T>
void Vector<T>::Copy(const Vector<T> &rhs)
{
    m_capacity = rhs.GetCapacity();
    m_used = rhs.GetUsed();
    m_array = new T[m_capacity];

    for(unsigned i(0); i < m_used; i++)
    {
        m_array[i] = rhs.GetValueByIndex(i);
    }
}

/* Getters */
template<class T>
unsigned Vector<T>::GetCapacity() const
{
    return m_capacity;
}

template<class T>
unsigned Vector<T>::GetUsed() const
{
    return m_used;
}

template<class T>
T *Vector<T>::GetArray() const
{
    return m_array;
}

/* Append Function */
template<class T>
bool Vector<T>::Append(const T &value)
{
    if(m_used == m_capacity / 2)
    {
        Resize();
    }
    m_array[m_used] = value;
    m_used ++;
    return true;
}

template<class T>
T &Vector<T>::GetValueByIndex(unsigned index) const
{
    return m_array[index];
}

/* Resize Function */
template<class T>
void Vector<T>::Resize()
{
    m_capacity = m_capacity * 2;
    T *newArray = new T[m_capacity];

    for(unsigned i(0); i < m_used; i++)
    {
        newArray[i] = m_array[i];
    }
    delete [] m_array;

    m_array = new T[m_capacity];
    for(unsigned i(0); i < m_used; i++)
    {
        m_array[i] = newArray[i];
    }
    delete [] newArray;
}

#endif // VECTOR_H_INCLUDED
