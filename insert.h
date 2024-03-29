#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void logs(string);
void clear_file()
{
    fstream data_log("Dates/log_id.txt", ios_base::trunc);
    data_log.close();
}
void file_write(int idd)
{
    ofstream data_log("Dates/log_id.txt");
    data_log << idd;
}
struct database
{
    string name;
    string pre;
    string adress;
    string email;
    string born_date;
    string cot_date;
    string telefon;
    string companii;
    string id;
} dates[101];
void insertD()
{
    string columns[25];
    string str, result, table_name;
    int nr_col, type[25], nr_tab, id_log;
//Dates reading from files
    ifstream name("Dates/Nume.txt");
    ifstream pre("Dates/Prenume.txt");
    ifstream adress("Dates/Adrese.txt");
    ifstream email("Dates/Email.txt");
    ifstream born_date("Dates/An_nast.txt");
    ifstream cot_date("Dates/An_cot.txt");
    ifstream telefon("Dates/Telefon.txt");
    ifstream companii("Dates/Companii.txt");
    ifstream id("Dates/ID.txt");
    ofstream c("Results/insert.txt");

    for(int i = 1; !name.eof(); i++)
    {
        string namen, pren, adressn, emailn, born_daten, cot_daten, telefonn, companiin;
        getline(name, namen);
        dates[i].name = "'" + namen + "'";
        getline(pre, pren);
        dates[i].pre = "'" + pren + "'";
        getline(adress, adressn);
        dates[i].adress = "'" + adressn + "'";
        getline(email, emailn);
        dates[i].email = "'" + emailn + "'";
        getline(born_date, born_daten);
        dates[i].born_date = "'" + born_daten + "'";
        getline(cot_date, cot_daten);
        dates[i].cot_date = "'" + cot_daten + "'";
        getline(telefon, telefonn);
        dates[i].telefon = "'" + telefonn + "'";
        getline(companii, companiin);
        dates[i].companii = "'" + companiin + "'";
        getline(id, dates[i].id);
    }
    cout << "Introduceti numarul de tabele: ";
    cin >> nr_tab;
    for(int tab = 1; tab <= nr_tab; tab++)
    {
        cout << "Introduceti numele tabelului: ";
        cin >> table_name;
        cout << "Introduceti numarul coloanelor: ";
        cin >> nr_col;

        cout << "Coloane:\n";
        for(int i = 1; i <= nr_col; i++)
        {
            cout << i << ": ";
            cin >> columns[i];
            cout << endl;
        }
        cout << "Introduceti tipul fiecarei coloane:\n";
        cout << "Tipuri disponibile: \n";
        cout << "1. Nume         2. Prenume         3. Adresa\n";
        cout << "4. Telefon      5. Email           6. Companii\n";
        cout << "7. An 90-07     8. An 07-19        9. NULL\n";
        cout << "10. ID\n\n";

        for(int i = 1; i <= nr_col; i++)
        {
            cout <<"Tipul de date pentru coloana " << columns[i] << ": ";
            cin >> type[i];
        }

        //INSERT INTO( COLUMNS)
        result += "\n\tINSERT INTO " + table_name + "(";
        for(int i  = 1 ; i <= nr_col ; i++)
        {
            result += columns[i];
            if( i != nr_col)
                result += ", ";
            else
                result += "),\n";
        }
        //VALUES (VALUES),
        result += "\t\tVALUES(";
        for(int i = 1 ; i <= nr_col ; i++)
        {
            switch (type[i])
            {
            case 1:
                result += dates[1].name;
                break;
            case 2:
                result += dates[1].pre;
                break;
            case 3:
                result += dates[1].adress;
                break;
            case 4:
                result += dates[1].telefon;
                break;
            case 5:
                result += dates[1].email;
                break;
            case 6:
                result += dates[1].companii;
                break;
            case 7:
                result += dates[1].born_date;
                break;
            case 8:
                result += dates[1].cot_date;
                break;
            case 9:
                result += "''";
                break;
            case 10:
                result += dates[1].id;
                break;
            }
            if( i < nr_col)
                result += ", ";
            else
                result += "),\n";
        }
        //(VALUES),
        //........,
        for(int g = 2; g <= 100; g++)
        {
            result += "\t\t\t(";
            for(int i = 1; i <= nr_col; i++)
            {
                switch (type[i])
                {
                case 1:
                    result += dates[g].name;
                    break;
                case 2:
                    result += dates[g].pre;
                    break;
                case 3:
                    result += dates[g].adress;
                    break;
                case 4:
                    result += dates[g].telefon;
                    break;
                case 5:
                    result += dates[g].email;
                    break;
                case 6:
                    result += dates[g].companii;
                    break;
                case 7:
                    result += dates[g].born_date;
                    break;
                case 8:
                    result += dates[g].cot_date;
                    break;
                case 9:
                    result += "''";
                    break;
                case 10:
                    result += dates[g].id;
                    break;
                }
                if( i < nr_col)
                    result += ", ";
                else if(g >= 100)
                    result += ")";
                else
                    result += "),\n";
            }

        }
        system("cls");
        result += "\nGO\n";
    }

    c << result;
    cout << "\n\n" << result;
    cout << "\n\nDatele au fost adaugate cu succes in fisier\n";





    //LOGS:
    {fstream data_log("Dates/log_id.txt", ios_base::out | ios_base::in);
    string dat;
    data_log >> dat;

    clear_file();

    int idd = atoi(dat.c_str());
    idd++;
    file_write(idd);

    logs("Inserted dates with id " + dat);
    }
}
#warning @todo (Vlad#1#): Modific filestream system, to eliminate data redundancy
#warning @todo (Vlad#1#): Add referenced key
#warning @todo (Vlad#1#): If column name == type name, then dont ask for type
#warning #Feature (Vlad#1#): Verify if column name (introduced by user) exist in /data/....txt
