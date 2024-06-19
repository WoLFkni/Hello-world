#ifndef FVECTOR_H_INCLUDED
#define FVECTOR_H_INCLUDED

// Vectors with a fixed length
class FVector {
public:
    // Constructors and destructors
    FVector(int n);
    ~FVector();

    int length() const;

    void set(int i, int v);
    int at(int i) const;

private:
    int n;
    int* arr;
};

#endif // FVECTOR_H_INCLUDED
