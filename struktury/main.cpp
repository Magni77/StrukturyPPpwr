#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <windows.h>


using namespace std;


struct employer {
    char name[10];
    char last_name[20];
    char pesel[20];
    int salary;
    int amount_family_memembers;
};

void save_to_file(employer base[], int i) {

    fstream file_base;
    file_base.open("base.txt", ios::out | ios::app);
    file_base<<base[i].name<<endl;
    file_base<<base[i].last_name<<endl;
    file_base<<base[i].pesel<<endl;
    file_base<<base[i].salary<<endl;
    file_base<<base[i].amount_family_memembers<<endl;

    file_base.close();

}

void save_all_to_file(employer base[], int a_amount_employers) {


    fstream file_base;
    file_base.open("base.txt", ios::out);
    for(int i = 0; i < a_amount_employers; i++) {
        file_base<<base[i].name<<endl;
        file_base<<base[i].last_name<<endl;
        file_base<<base[i].pesel<<endl;
        file_base<<base[i].salary<<endl;
        file_base<<base[i].amount_family_memembers<<endl;
    }
    file_base.close();

}

void read_file(employer base[], int x) {

    fstream file_base;
    file_base.open("base.txt", ios::in);

    if(file_base.good()==false) cout<<"Nie mozna otworzyc pliku!";

    for(int i=0; i<2000; i++) {
        file_base>>base[i].name;
        file_base>>base[i].last_name;
        file_base>>base[i].pesel;
        file_base>>base[i].salary;
        file_base>>base[i].amount_family_memembers;
    }
    file_base.close();
}

void input(employer base[], int a_amount_employers) {
    cout<<"Podaj imie: "<<endl;
    cin>>base[a_amount_employers].name;
    cout<<"Podaj nazwisko: "<<endl;
    cin>>base[a_amount_employers].last_name;
    cout<<"Podaj pesel: "<<endl;
    cin>>base[a_amount_employers].pesel;
    cout<<"Podaj wynagrodzenie: "<<endl;
    cin>>base[a_amount_employers].salary;
    cout<<"Podaj ilosc czlonkow rodziny: "<<endl;
    cin>>base[a_amount_employers].amount_family_memembers;
}

void print(employer base[], int a_amount_employers) {
    for(int i=0; i<a_amount_employers; i++) {
        cout<<"Imie: "<<base[i].name<<endl;
        cout<<"Nazwisko: "<<base[i].last_name<<endl;
        cout<<"Pesel: "<<base[i].pesel<<endl;
        cout<<"Wynagrodzenie: "<<base[i].salary<<endl;
        cout<<"Ilosc czlonkow rodzin: "<<base[i].amount_family_memembers<<endl<<endl;

    }

}

void amount_women(employer base[], int a_amount_employers) {
    int womens=0;
    for (int i=0; i < a_amount_employers; i++) {

        for (int k=0; k<10; k++) {
            if(base[i].name[k] == NULL && base[i].name[k-1] == 'a' )
                womens++;
        }

    }
    cout << "Ilosc kobiet: " << womens << endl;
}

int get_amount_employers(employer base[]) {
    int amount_empl=0;
    string line;
    fstream file_base;
    file_base.open("base.txt", ios::in);

    if(file_base.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while(!file_base.eof()) {
        getline(file_base, line);
        amount_empl++;
    }

    file_base.close();
    return amount_empl/5;
}

void search_employer(employer base[], int a_amount_employers) {
    char letter;
    cout<<"Podaj litere"<<endl;
    cin>>letter;
    for (int i=0; i < a_amount_employers; i++) {
        for (int k=0; k<10; k++) {
            if(base[i].name[k] == letter  ) {
                cout<<base[i].name<<endl;
                break;
            }
        }
    }
}

void bonus(employer base[], int a_amount_employers) {
    for (int i=0; i < a_amount_employers; i++) {
        if(base[i].salary / base[i].amount_family_memembers < 800 ) {
            cout<<base[i].name<< " "<< base[i].last_name<<" dochod na osobe: ";
            cout<<base[i].salary / base[i].amount_family_memembers<<endl;
        }

    }

}

void average_age(employer base[], int a_amount_employers) {
    int salary_women = 0, salary_men = 0, amount_women = 0, amount_men = 0;
    for (int i=0; i < a_amount_employers; i++) {

        for (int k=0; k<10; k++) {
            if(base[i].name[k] == NULL && base[i].name[k-1] == 'a' ) {
                amount_women++;
                salary_women += base[i].salary;
                break;

            } else if(base[i].name[k] == NULL && base[i].name[k-1] != 'a' ) {
                salary_men += base[i].salary;
                amount_men++;
                break;
            }
        }

    }
    cout<<"Srednia pensja kobiet wynosi: "<<salary_women/amount_women<<endl;
    cout<<"Srednia pensja men wynosi: "<<salary_men/amount_men<<endl;
}

void biggest_family(employer base[], int a_amount_employers) {
    int size_family = 0;
    for (int i=0; i < a_amount_employers; i++) {
        if(base[i].amount_family_memembers >= size_family)
            size_family = base[i].amount_family_memembers;
    }
    for (int i=0; i < a_amount_employers; i++) {
        if(base[i].amount_family_memembers >= size_family)
            cout<<base[i].name<<" "<<base[i].last_name<<" - "<<
                base[i].amount_family_memembers<<endl;
    }
}

void print_employers_names(employer base[], int a_amount_employers) {
    for(int i=0; i < a_amount_employers; i++)
        cout<<i+1<<". "<<base[i].name<<" "<<base[i].last_name<<endl;

    cout<<endl;
}

int choose_edit_employer() {
    int choice;
    cout<<"Wybierz rekord do edycji"<<endl;
    cin>>choice;
    return choice-1;
}

int print_edit() {
    int choice;
    cout<<"Co chcesz edytowac? "<<endl;
    cout<<"1. Imie\n2. Nazwisko\n3. Pesel\n4. Pensje\n5.Ilosc czlonkow rodziny\n";
    cin>>choice;
    return choice;

}

void edit(employer base[], int a_choice_edit, int a_choice_empl) {

    switch(a_choice_edit) {
    case 1:
        cout<<"Podaje nowe imie "<<endl;
        cin>>base[a_choice_empl].name;
        break;
    case 2:
        cout<<"Podaje nowe nazwisko "<<endl;
        cin>>base[a_choice_empl].last_name;
        break;
    case 3:
        cout<<"Podaje nowy pesel "<<endl;
        cin>>base[a_choice_empl].pesel;
        break;
    case 4:
        cout<<"Podaje nowa pensje "<<endl;
        cin>>base[a_choice_empl].salary;
        break;
    case 5:
        cout<<"Podaje nowa ilosc czlonkow rodziny "<<endl;
        cin>>base[a_choice_empl].amount_family_memembers;
        break;
    }

}

void menu() {

    cout<<"Baza danych pracownikow"<<endl;
    cout<<"1. Dodaj pracownika."<<endl;
    cout<<"2. odczyt"<<endl;
    cout<<"3. Ilosc kobiet"<<endl;
    cout<<"4. Wyszukaj."<<endl;
    cout<<"5. Dodatkowa premia."<<endl;
    cout<<"6. Segreguj wiekiem."<<endl;
    cout<<"7. Srednia pensja."<<endl;
    cout<<"8. Najwieksza ilosc czlonkow rodziny."<<endl;
    cout<<"9. Edytuj rekord."<<endl;

}



int main() {
    employer base[2000];


    //  int *w = base;
    read_file(base,0);

    for(;;) {

        int amount_employers=get_amount_employers(base);

        menu();
        read_file(base,0);
        int choice=getch();

        switch(choice) {
        case '1':
            system("CLS");
            input(base, amount_employers);
            save_to_file(base, amount_employers);
            break;
        case '2':
            system("CLS");
            print(base, amount_employers);
            break;
        case '3':
            system("CLS");
            amount_women(base, amount_employers);
            break;
        case '4':
            system("CLS");
            search_employer(base, amount_employers);
            break;
        case '5':
            system("CLS");
            bonus(base, amount_employers);
            break;
        case '6':
            system("CLS");
            cout<<"Tu bedzie segregacja wiekiem"<<endl;
            break;
        case '7':
            system("CLS");
            average_age(base, amount_employers);
            break;
        case '8':
            system("CLS");
            biggest_family(base, amount_employers);
            break;
        case '9':
            system("CLS");
            print_employers_names(base, amount_employers);
            int empl = choose_edit_employer();
            int edi = print_edit();
            edit(base, edi, empl);
            save_all_to_file(base, amount_employers);
            break;
        }
    }


    return 0;
}
