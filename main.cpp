#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int IC;
int PTR;
int VA;
int RA;
int kio = -1;
int flag[30];
int PI, TI, SI;
int TTC = 0, LLC = 0;
int ttl, tll;

char M[300][4], IR[4], R[4];
char C;
char temp[100];
char page[10][4];

fstream fin, fout;

string line;

void MOS();
void END();
void ALLOCATE();
void READ();
void WRITE();
void MOS();
void EXECUTE();
void START();
void INIT();
void LOAD();

struct PCB
{
    int job[4], TTL[4], TLL[4];
} pcb;

void READ()
{
    int no, i, j, k, z, x;
    getline(fin, line);
    cout << "\nLine  :" << line;
    no = ((M[RA][2] - 48) * 10) + (M[RA][3] - 48);
    no = no * 10;
    k = 0;
    for (i = 0; k <= line.size(); i++)
    {
        for (j = 0; j < 4 && k <= line.size(); j++)
        {
            cout << "\nCount  :";
            cout << no + i << endl
                 << j << "\n";
            M[no + i][j] = line[k];
            k++;
        }
    }
    for (i = 0; i < 300; i++)
    {
        cout << "[" << i << "] = ";
        for (j = 0; j < 4; j++)
        {
            cout << M[i][j];
        }
        cout << endl;
    }
}

void LOAD()
{
    // cout << "IN LOAD\n";
    int i, j, k;

    while (fin)
    {
        // cout << "In while" << endl;
        getline(fin, line);
        // cout << line << "Line 1: " << endl;
        if (line[0] == '$' && line[1] == 'A' && line[2] == 'M' && line[3] == 'J')
        {

            SI = 0;
            TI = 0;
            TTC = 0;
            LLC = 0;
            for (i = 4, j = 0; i < 8; i++, j++)
            {
                pcb.job[j] = line[i];
            }
            for (i = 8, j = 0; i < 12; i++, j++)
            {
                pcb.TTL[j] = line[i];
            }
            for (i = 12, j = 0; i < 16; i++, j++)
            {
                pcb.TLL[j] = line[i];
            }

            ttl = (pcb.TTL[0] - 48) * 1000 + (pcb.TTL[1] - 48) * 100 + (pcb.TTL[2] - 48) * 10 + (pcb.TTL[3] - 48);
            tll = (pcb.TLL[0] - 48) * 1000 + (pcb.TLL[1] - 48) * 100 + (pcb.TLL[2] - 48) * 10 + (pcb.TLL[3] - 48);
            
            cout << " TTL = " << ttl << endl;
            cout << " TLL = " << tll << endl;
            TTC = 0;
            LLC = 0;
            // INIT();
        }
        if (line[0] == '$' && line[1] == 'D' && line[2] == 'T' && line[3] == 'A')
        {
            // Start execution
        }
    }
}


int main()
{
    fin.open("input.txt");
    fout.open("output.txt");
    LOAD();
    fin.close();
    fout.close();
    return 0;
}