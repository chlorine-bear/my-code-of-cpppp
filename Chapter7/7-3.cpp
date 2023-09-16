#include <iostream>
using namespace std;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void show(box b);
void calc(box * b);
void show(box b)
{
    cout << "Maker: " << b.maker << endl
         << "Height: " << b.height << endl
         << "Width: " << b.width << endl
         << "Length: " << b.length << endl
         << "Volume: " << b.volume << endl;
}
void calc(box * b)
{
    b->volume = b->height * b->length * b->width;
}
int main()
{
    box b;
    cout << "Please enter the maker: ";
    cin.getline(b.maker, 40);
    cout << "Please enter the height: ";
    cin >> b.height;
    cout << "Please enter the width: ";
    cin >> b.width;
    cout << "Please enter the length: ";
    cin >> b.length;
    calc(&b);
    show(b);
    return 0;
}