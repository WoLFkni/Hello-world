#ifndef FVECTOR_H_INCLUDED
#define FVECTOR_H_INCLUDED

// Vectors with a fixed length
class FVector {
public:
    // Constructors and destructors
    FVector(int n);
    ~FVector();

    // Copy constructor
    FVector(const FVector& vec);

    // Overloaded Assignment
    FVector& operator=(const FVector& vec);

    int length() const;

    void set(int i, int v);
    int at(int i) const;

private:
    void deepCopy(const FVector& vec);

    int n;
    int* arr;
};

#endif // FVECTOR_H_INCLUDED
