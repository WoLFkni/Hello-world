#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

struct LinkedList;

class IVector{
public:
    IVector();
    ~IVector();

    //Copy constructor
    IVector(const IVector& vec);

    //Assignment operator
    IVector& operator=(const IVector& vec);

    int size() const;
    bool isEmpty() const;
    void clear();

    int get(int i);
    void set(int i, int v);

    void add(int v);
    void insert(int i, int v);
    void remove(int i);

private:
    LinkedList* lst;
};

#endif // VECTOR_H_INCLUDED
