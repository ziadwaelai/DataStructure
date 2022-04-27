#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
string a;
class phonedirect {

private:
    string F_name, L_name, phone;
public:


    void set_F_name(string a) {

        F_name = a;
    }
    void set_L_name(string b) {

        L_name = b;
    }
    void set_Phone(string c) {

        phone = c;
    }
    string get_F_name() {
        return F_name;
    }
    string get_L_name() {
        return L_name;
    }
    string get_Phone() {
        return phone;
    }
    friend ofstream& operator<<(ofstream& out, phonedirect& ob) {
        out << ob << " ";
        return out;
    }
    friend ifstream& operator>>(ifstream& in, phonedirect& ob) {
        in >> ob;
        return in;
    }



    void add_entry(phonedirect array) {

        fstream out("file_p6.txt", ios::app);
        cin >> F_name >> L_name >> phone;
        array.set_F_name(F_name);
        array.set_L_name(L_name);
        array.set_Phone(phone);

        out << array.get_F_name() << " ";
        out << array.get_L_name() << " ";
        out << array.get_Phone() << endl;

    }


};


void search_by_phone(string phone_num);
void search_by_F_name(string firstname);
void delete_by_F_name(string firstname, vector <string> v);
void sort_1(vector <string>& v);
void sort_2(vector <string>& v);
void sort_3(vector <string>& v, int left, int right);

int main()
{
    vector <string> vec;
    int num;
    int index_vector = 0;
    cout << "\nif you want addan entry to the directory put : 1" << endl;
    cout << "if you want Look up a phone number put : 2" << endl;
    cout << "if you want Look up by first name put : 3" << endl;
    cout << "if you want Delete By First name put : 4" << endl;
    cout << "if you want List All entries in phone directory put: 5" << endl;
    cout << "if you want  Exit form this program put: 6" << endl;
    while (true) {
        cout << "# of operation : ";
        cin >> num;

        if (num == 1) {
            int n = 0;
            cout << "\n enter # of persons : ";
            cin >> n;
            phonedirect* array;
            array = new phonedirect[n];

            for (int i = 0; i < n; i++) {
                cout << "\n enter F_name L_name Phone: " << endl;
                array[i].add_entry(array[i]);



            }
            cout << "-------------------------------------------------------\n";
              }
        if (num == 2) {
            cout << "\n enter number_phone for searsh: " << endl;
            string phone_number;
            cin >> phone_number;
            search_by_phone(phone_number);

            cout << "-------------------------------------------------------\n";

        }

        if (num == 3) {

            cout << "\n enter F_name for searsh : " << endl;
            string F_name;
            cin >> F_name;


            search_by_F_name(F_name);


            cout << "-------------------------------------------------------\n";
        }

        if (num == 4) {
            cout << "\n enter F_name for delete: " << endl;
            string F_name;
            cin >> F_name;
            delete_by_F_name(F_name, vec);
            cout << "-------------------------------------------------------\n";
        }
        if (num == 5) {
            ifstream in("file_p6.txt");
            while (!in.eof()) {
                in >> a;
                vec.push_back(a);
            }  in.close();
         
            sort_1(vec);
            cout << "-------------------------------------------------------\n";
        }
          
        if (num == 6)
            exit(1);
           
    }
    
}
void search_by_phone(string phone_num) {
    int count = 0, num = 0;
    ifstream in("file_p6.txt");
    while (!in.eof()) {
        in >> a;
        count++;
        if (a == phone_num and count % 3 == 0) {

            cout << "Existing :" << a << endl;
            num++;
            continue;

        }

    }
    if (num == 0)
        cout << "Not Found" << endl;

}
void search_by_F_name(string firstname) {

    ifstream in("file_p6.txt");
    string array[3];
    int count = -1; int count2 = 0;
    while (!in.eof()) {
        for (int i = 0; i < 3; i++) {
            in >> array[i];
            count++;
            if (array[i] == firstname and count % 3 == 0) {

                in >> array[i + 1] >> array[i + 2];
                count += 2;
                cout << array[i] << "\t" << array[i + 1] << "\t" << array[i + 2] << endl;
                i += 3;
                count2++;
            }


        }

    }
    if (count2 == 0)
        cout << "Not Found" << endl;

}
void delete_by_F_name(string firstname, vector <string> v) {

    ifstream in("file_p6.txt");
    int count = -1;
    while (!in.eof()) {
        in >> a;
        v.push_back(a);
        count++;
        if (a == firstname) {
            in >> a;
            v.push_back(a);
            count++;
            in >> a;
            v.push_back(a);
            count++;
            cout << v.at(count - 2) << "\t" << v.at(count - 1) << "\t" << v.at(count) << endl;
        }
    }
    in.close();
    ofstream out("file_p6.txt");
    for (int i = 0; i < v.size() - 3; i += 3) {
        if (v.at(i) == firstname) {
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
        }
        else if (i <= v.size() - 3)
            out << v.at(i) << " " << v.at(i + 1) << "  " << v.at(i + 2) << endl;
    } out.close();





}
void sort_1(vector <string>& v) {
    int index = 0;
    cout << "\n*data Befor sorting \n" << endl;
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }

    for (int i = 0; i < v.size() - 3; i += 3) {
        index = i;
        for (int j = i + 3; j < v.size() - 3; j += 3) {
            if (v[index] > v[j]) {

                swap(v[j], v[index]);
                swap(v[j + 1], v[index + 1]);
                swap(v[j + 2], v[index + 2]);

            }
        }

    }

    ofstream out("file_p6.txt");
    cout << "\n*data Aftar sorting\n" << endl;
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        out << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }
    out.close();
    v.clear();

}
void sort_2(vector <string>& v) {

    cout << "\n*data Befor sorting \n" << endl;
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }
    for (int i = 0; i < v.size(); i += 3) {

        for (int j = 0; j < (v.size() - 4); j += 3) {

            if (v[j] >= v[j + 3]) {

                swap(v[j], v[j + 3]);
                swap(v[j + 1], v[j + 4]);
                swap(v[j + 2], v[j + 5]);

            }

        }



    }

    ofstream out("file_p6.txt");
    cout << "\n*data Aftar sorting\n" << endl;
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        out << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }
    out.close();
    v.clear();




}
int partition(vector <string>& v, int left, int right) {

    string povit = v[left];
    int i = left;
    for (int j = left + 3; j < v.size(); j += 3) {

        if (povit >= v[j]) {
            cout << "\n enter F_name for delete: " << endl;
            cout << v[i] << " //" << v[j] << endl;
            i += 3;

            swap(v[i], v[j]);
            swap(v[i + 1], v[j + 1]);
            swap(v[i + 2], v[j + 2]);

        }
    }


    return i;
}
void sort_3(vector <string>& v, int left, int right) {


    ifstream in("file_p6.txt");
    while (!in.eof()) {
        in >> a;
        v.push_back(a);
    }  in.close();
    cout << "data befor sorting\n";
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }

    if (left <= right) {

        int mid = partition(v, left, right);
        sort_3(v, left, mid - 3);
        sort_3(v, mid+3, right);
    }
    ofstream out("file_p6.txt");
    cout << "\n*data Aftar sorting\n" << endl;
    for (int i = 0; i < v.size() - 3; i += 3)
    {
        out << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
        cout << v[i] << "\t" << v[i + 1] << "\t" << v[i + 2] << endl;
    }
    out.close();
    v.clear();



}













































