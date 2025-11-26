#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
using namespace std;

struct Student_lac {
    int roll_lac;
    string name_lac;
    string course_lac;
    double cgpa_lac;
    int year_lac;
    string email_lac;
    int state_lac;

    Student_lac() : roll_lac(0), name_lac(""), course_lac("CSE"), cgpa_lac(0.0), year_lac(0),
                    email_lac(""), state_lac(0) {}
};

bool isPrime_lac(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0) return false;
    return true;
}

int nextPrime_lac(int n){
    while(!isPrime_lac(n)) n++;
    return n;
}

class StudentHash_lac{
public:
    int capacity_lac, used_lac;
    vector<Student_lac> table_lac;

    StudentHash_lac(int cap){
        capacity_lac = nextPrime_lac(cap);
        table_lac.assign(capacity_lac, Student_lac());
        used_lac = 0;
    }

    int h1_lac(int key){ return key % capacity_lac; }
    int h2_lac(int key){ return 1 + (key % (capacity_lac - 2)); }

    void rehash_lac(){
        int newCap = nextPrime_lac(capacity_lac * 2);
        vector<Student_lac> old = table_lac;
        table_lac.assign(newCap, Student_lac());
        int oldCap = capacity_lac;

        capacity_lac = newCap;
        used_lac = 0;

        for(int i=0;i<oldCap;i++)
            if(old[i].state_lac == 1)
                insert_lac(old[i], false);
    }

    bool insert_lac(Student_lac s, bool resize=true){
        if(resize && (double)used_lac/capacity_lac > 0.6) rehash_lac();

        int key = s.roll_lac, i=0;
        int idx = (h1_lac(key)+i*h2_lac(key))%capacity_lac;
        int firstDel = -1;

        while(i<capacity_lac){
            if(table_lac[idx].state_lac==0){
                if(firstDel!=-1) idx=firstDel;
                table_lac[idx]=s;
                table_lac[idx].state_lac=1;
                used_lac++; return true;
            }
            if(table_lac[idx].state_lac==2 && firstDel==-1)
                firstDel = idx;
            else if(table_lac[idx].state_lac==1 && table_lac[idx].roll_lac==key)
                return false;

            i++; idx = (h1_lac(key)+i*h2_lac(key))%capacity_lac;
        }

        if(firstDel!=-1){
            table_lac[firstDel]=s;
            table_lac[firstDel].state_lac=1;
            used_lac++; return true;
        }
        return false;
    }

    int search_lac(int roll){
        int key = roll, i=0;
        int idx=(h1_lac(key)+i*h2_lac(key))%capacity_lac;

        while(i<capacity_lac){
            if(table_lac[idx].state_lac==0) return -1;
            if(table_lac[idx].state_lac==1 && table_lac[idx].roll_lac==key)
                return idx;

            i++; idx=(h1_lac(key)+i*h2_lac(key))%capacity_lac;
        }
        return -1;
    }

    bool remove_lac(int roll){
        int pos = search_lac(roll);
        if(pos==-1) return false;

        table_lac[pos] = Student_lac();
        table_lac[pos].state_lac = 2;
        used_lac--;
        return true;
    }

    void display_lac(){
        cout << "\nIdx State Roll Name CGPA Year Email\n";
        for(int i=0;i<capacity_lac;i++){
            cout<<i<<"\t";
            if(table_lac[i].state_lac==0) cout<<"Empty\n";
            else if(table_lac[i].state_lac==2) cout<<"Deleted\n";
            else cout<<"Full  "<<table_lac[i].roll_lac<<" "<<table_lac[i].name_lac
                <<" "<<table_lac[i].cgpa_lac<<" "<<table_lac[i].year_lac<<" "<<table_lac[i].email_lac<<"\n";
        }
        cout<<"\nCapacity="<<capacity_lac<<" Used="<<used_lac<<"\n";
    }
};

int main(){
    
    string names[4]   = {"likhit","pranil","rohan","sahil"};
    int rolls[4]      = {23,25,26,13};
    double cgpa[4]    = {9.0,9.2,9.6,8.5};
    int year[4]       = {2022,2024,2023,2021};
    string mail[4]    = {"likhit@gmail.com","pranil@gmail.com","rohan@gmail.com","sahil@gmail.com"};

    int cap;
    cout<<"Enter table size: "; cin>>cap;
    StudentHash_lac H(cap);

    while(true){
        cout<<"\n1.Random Insert  2.Search  3.Delete  4.Display  5.Exit\nChoice: ";
        int ch; cin>>ch;

        if(ch==1){
            int r = rand()%4; 
            Student_lac s;
            s.roll_lac = rolls[r];
            s.name_lac = names[r];
            s.cgpa_lac = cgpa[r];
            s.year_lac = year[r];
            s.email_lac = mail[r];

            cout<<"Generated -> "<<s.roll_lac<<" "<<s.name_lac<<" "<<s.cgpa_lac<<"\n";

            if(H.insert_lac(s)) cout<<"Inserted\n";
            else cout<<"FAILED (Duplicate or Full)\n";
        }

        else if(ch==2){
            int r; cout<<"Search roll: "; cin>>r;
            int p=H.search_lac(r);
            if(p==-1) cout<<"Not Found\n";
            else cout<<"Found at index "<<p<<": "<<H.table_lac[p].name_lac<<"\n";
        }

        else if(ch==3){
            int r; cout<<"Enter roll to delete: "; cin>>r;
            cout<<(H.remove_lac(r) ? "Deleted\n":"Not Found\n");
        }

        else if(ch==4) H.display_lac();
        else if(ch==5) break;
        else cout<<"Invalid\n";
    }
    return 0;
}
