#include <iostream>

using namespace std;

class Stack {
    char* body;
    int n, size;
public:
    Stack() : body(0), n(0), size(0) throw() {}
    Stack(const Stack& S);

    void copy(char*, char*, int) const;
    void push(char c);
    char pop();
    char top() const;
    void print() const;

    ~Stack() throw() { delete [] body; }
};

void Stack::copy(char *from, char *to, int len) const
{
    for (int i = 0; i < len; i++)
        to[i] = from[i];
}

Stack::Stack throw() (const Stack& S)
{
    body = new char[S.size];
    copy(S.body, body, S.n);
    n = S.n;
    size = S.size;
}

void Stack::push(char c)
{
    if (!body) {
        body = new char[8];
        size = 8;
    } else if (n == size) {
        char* new_body = new char[size*=2];
        copy(body, new_body, n);
        delete [] body;
        body = new_body;
    }
    body[n++] = c;
}

char Stack::pop()
{
try {
    if (!body)
        throw "StackIsEmpty";
    char ans = body[n-1];
    char *tmp = body;
    if (n == 1) {
        body = NULL;
    } else {
        char* new_body = new char[size];
        copy(body, new_body, n-1);
        body = new_body;
    }
    delete [] tmp;
    n--;
    return ans;
} catch (const char* e) { cout << "Wrong pop! Stack is empty\n" << endl; }	
}

char Stack::top() const
{
try {
    if (!body)
        throw "StackIsEmpty";
    return body[n-1];
} catch (const char* e) { cout << "Function top: stack is empty\n" << endl; }
}

void Stack::print() const
{
    for (int i = n-1; i >= 0; --i)
        cout << body[i] << endl;
}

int main(void)
{
    Stack st;
    char ch;
    while (cin >> ch) {
        try {
            if (ch == '(')
                st.push(ch);
            else if (ch == ')')
                st.pop();
        } catch (const char* e) {
            cout << endl << "Wrong" << endl;
        }
    }
    try {
        if (st.top())
            cout << endl << "Wrong" << endl;
    } catch (const char* e) {
        cout << endl << "Right" << endl;
    }
    return 0;
}

//добавлены обработки исключений в функциях и гаранатировано, что конструкторы и деструктор не выкинут никаких исключений. 
