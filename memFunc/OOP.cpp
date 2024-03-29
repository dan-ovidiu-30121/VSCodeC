#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void display() = 0;
    virtual void communicates() = 0;
    Animal()
    {
        cout << "This in an animal!\n";
    }
};

class Dog : public Animal
{
public:
    string color = "Grey";
    void display()
    {
        cout << "This animal is a dog!\n";
    }
    void communicates()
    {
        cout << "Communication language for dogs: barking\n";
    }
    static void run()
    {
        cout << "The dog runs fast!\n";
    }
    Dog()
    {
        cout << "This is a dog!\n";
    }
};
int palindrom(int n)
{
    int rev = n, ogl = 0;
    do
    {
        ogl = (ogl * 10) + rev % 10;
        rev /= 10;
    } while (rev);
    if (ogl == n)
        return 1;
    return 0;
}
int main(void)
{
    /*Animal* d = new Dog();
    d->display();
    d->communicates();
    Dog::run();*/
    int n;
    cin >> n;
    cout << palindrom(n);
}
