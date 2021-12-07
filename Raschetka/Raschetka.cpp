#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;

int main()
{
    int i = 0, j = 0, k, req = 0, edgeq=0 , tp, lastelement; // edgeq(edge quantity)- количество ребер; tp-type; reg-real edge quantity 
    int const str = 20;
    int a[str][2];

    
    string fpath = "graph2.txt";        //чтение из текстовика
    ifstream filn;
    filn.open(fpath);
    if (!filn.is_open())
    {
       cout << "file error" << endl;
    }
    else
    {
        cout << "file opened" << endl;
        string st;
            for (int b = 0; b <= edgeq; b++)
            {
                
                filn >> st;
                int o;
                o = stoi(st);
                edgeq = o;
                for (int c = 0; c <= 1; c++)
                {
                        st = "0";
                        filn >> st;
                        o = stoi(st);
                        a[b][c] = o;
                        
                }
            }
    }
        filn.close();

    stack <int> st1;
    stack <int> st2;
    stack <int> flip1;

    cout << "Graph type:" << endl;
    cout << "1)Oriented" << endl;
    cout << "2)Non-oriented" << endl;
    cin >> tp;

    if (tp == 1)                            //ориентированный граф
    {
        cout << "Eiler Cycle:" << endl;
        st1.push(a[0][0]);                  //Заполнение стека 
       // cout << a[0][0] << endl;
        st1.push(a[0][1]);
        //cout << a[0][1] << endl;
        for (int i = 0; i < str; i++)
        {

            if (a[j][1] == a[i][0])
            {
                a[j][0] = 0;
                a[j][1] = 0;
                j = i;
                i = 0;
                req++;
                st1.push(a[j][0]);
                //cout << a[j][0] << endl;
                st1.push(a[j][1]);
                //cout << a[j][1] << endl;
            };  

            lastelement=st1.top();

        }
        while (!st1.empty())              //поиск в глубину
        {
            st2.push(st1.top());
            st1.pop();
            st2.push(st1.top());
            for (int i = 0; i < str; i++)
            {
                if (st2.top() == a[i][0] && i != j)
                {
                    a[j][0] = 0;
                    a[j][1] = 0;
                    j = i;
                    i = 0;
                    req++;
                    st2.push(a[j][0]);
                    st2.push(a[j][1]);
                };

            }
            st1.pop();
        }
        while (!st2.empty())                //flip
        {
            flip1.push(st2.top());
            cout << flip1.top() << ' ';
            st2.pop();
        }
        if (lastelement != flip1.top()) { goto error; }
        if (req < edgeq) { goto error; }
    }
    if (tp == 2)                            //не ориентированный граф
    {
        cout << "Eiler Cycle:" << endl;
        st1.push(a[0][0]);
        st1.push(a[0][1]);
        for (int i = 0; i < str; i++)
        {

            if (a[j][1] == a[i][0])
            {
                a[j][0] = 0;
                a[j][1] = 0;
                j = i;
                i = 0;
                req++;
                st1.push(a[j][0]);
                st1.push(a[j][1]);
            };
            if (a[j][1] == a[i][1] && i != j)
            {
                a[j][0] = 0;
                a[j][1] = 0;
                j = i;
                k = a[j][0];
                a[j][0] = a[i][1];
                a[j][1] = k;
                i = 0;
                req++;
                st1.push(a[j][0]);
                st1.push(a[j][1]);
            }

        }
        lastelement = st1.top();
        while (!st1.empty())
        {
            cout << st1.top() << ' ';
            st2.push(st1.top());
            st1.pop();
            cout << st1.top() << ' ';
            st2.push(st1.top());
            for (int i = 0; i < str; i++)
            {
                if (st2.top() == a[i][0] && i != j)
                {
                    a[j][0] = 0;
                    a[j][1] = 0;
                    j = i;
                    i = 0;
                    req++;
                    st2.push(a[j][0]);
                    cout << st2.top() << ' ';
                    st2.push(a[j][1]);
                    cout << st2.top() << ' ';
                };
                if (st2.top() == a[i][1] && i != j)
                {
                    a[j][0] = 0;
                    a[j][1] = 0;
                    j = i;
                    k = a[j][0];
                    a[j][0] = a[i][1];
                    a[j][1] = k;
                    i = 0;
                    req++;
                    st2.push(a[j][0]);
                    cout << st2.top() << ' ';
                    st2.push(a[j][1]);
                    cout << st2.top() << ' ';
                }
            }
            st1.pop();
        }
        if(lastelement != st2.top()){ goto error; }
        cout << endl;
        if (req < edgeq) { goto error; }
    }
  if (tp!=1 && tp != 2) { goto error; }

    system("pause");
    return 0;

    error: 
    cout << "error" << endl;
    system("pause");
    return 0;
}


