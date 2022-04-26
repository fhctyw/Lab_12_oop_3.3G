// Cursor.cpp
#include "Cursor.h"
#include <sstream>
#include <iostream>

using namespace std;

Cursor::Cursor(LongLong pos, char s, bool v)
{
    if (!(setPosition(pos) && setSize(s) && setView(v)))
        *this = Cursor();
}

Cursor::Cursor(const Cursor& c)
{
    *this = c;
}

Cursor& Cursor::operator=(const Cursor& c)
{
    size = c.size;
    view = c.view;
    *this = LongLong::operator=(c);
    return *this;
}

istream& operator>>(istream& in, Cursor& c) 
{
    long x, y;
    int s;
    bool v;
    do
    {
        cout << "¬вед≥ть позиц≥ю x: "; in >> x;
        cout << "¬вед≥ть позиц≥ю y: "; in >> y;
        cout << "¬вед≥ть розм≥р: "; in >> s;
        cout << "¬ед≥ть вид курсору(1 - horizontal, 0 - vertical): "; in >> v;
    } while (!(c.setPosition(LongLong(x, y)) && c.setSize(s) && c.setView(v)));
    return in;
}

Cursor::operator string() const
{
    stringstream ss;
    ss << '(' << getHigh() << ", " << getLow() << ") size: " << (int)size << (view ? " horizontal" : " vertical");
    return ss.str();
}

ostream& operator<<(ostream& out, const Cursor& c)
{
    out << string(c);
    return out;
}

bool Cursor::setPosition(LongLong ll)
{
    if (ll.getHigh() >= 0)
    {
        LongLong::operator=(ll);
        return true;
    }
    else
        return false;
}

bool Cursor::setSize(char s)
{
    if (s > 0 && s < 16)
    {
        size = s;
        return true;
    }
    else
        return false;
}

void Cursor::move(long x, long y)
{
    Hide();

    LongLong ll(y, x);
    LongLong::operator=(*this + ll);

    Show();
}

void Cursor::changeView()
{
    view = !view;
}

void Cursor::SizeUp()
{
    setSize(size + 1);
}

void Cursor::SizeDown()
{
    setSize(size - 1);
}

void Cursor::Show()
{
    cout << "Cursor shows" << endl;
}

void Cursor::Hide()
{
    cout << "Cursor hides" << endl;
}
