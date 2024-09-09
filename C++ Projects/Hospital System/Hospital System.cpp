#include <iostream>
using namespace std;

// DATASTRUCTRE OF THE PROJECT
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int status[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int queue_length[MAX_SPECIALIZATION+1];

// MENU
int menu(){
 int choice = -1;
 while(choice ==-1){
        cout << "\nEnter your choice:\n";
		cout << "1) Add new patient\n";
		cout << "2) Print all patients\n";
		cout << "3) Get next patient\n";
		cout << "4) Exit\n";

       cin >> choice;

       if (!(1 <= choice && choice <= 4)) {
			cout << "Invalid choice. Try again\n";
			choice = -1;	// loop keep working
		}
 }
 return choice;
}
// SHIFT RIGHT
void shift_right(int spec , string names_sp[] , int status_sp[]){
  int length = queue_length[spec];
  for(int i = length-1 ; i>=0 ;i--){
     names_sp[i+1] = names_sp[i];
     status_sp[i+1]=status_sp[i];

  }

  queue_length[spec]++;
}

// SHIFT LEFT
void shift_left(int spec , string names_sp[] , int status_sp[]){
  int length = queue_length[spec];

  for(int i = 1 ; i<length ;i++){
     names_sp[i-1] = names_sp[i];
     status_sp[i-1]=status_sp[i];

  }
  queue_length[spec]--;

}

// ADD PATIENT
bool add_patient(){
 int spec;
 string name;
 int st;

 cout << "Enter specialization, name, status: ";
 cin >> spec >> name >> st;

 int pos = queue_length[spec];
 if(pos>=MAX_QUEUE){
    cout << "Sorry we can't add more patient for this specialization\n";
    return false;
 }

 // 0 --> regular (add to end)
 if(st == 0){
    status[spec][pos] = st;
    names[spec][pos] =name;
    queue_length[spec]++;
 }else{
 // 1 --> urgent (add to end)
   shift_right(spec ,names[spec] , status[spec] );
   status[spec][0] = st;
   names[spec][0] =name;
 }



}

void get_next_patient(){
int spec;
 cout << "Enter specialization: ";
cin >> spec;
int length = queue_length[spec];
if(length==0){
   cout << "NO PATIENTS AT THE MOMENT. HAVE REST, DR\n";
   return;
}

cout << names[spec][0] << " please go with the Dr\n";

shift_left(spec,names[spec],status[spec]);
}
// PRINT PATIENT
void print_patient(int spec , string name_spec[] , int status_spec[]){
int length = queue_length[spec];
if(length ==0){
    return;
}
cout << "There are "<< length << " patients in specialization " << spec << "\n";
for(int i = 0 ; i <length ; i++){
    cout << name_spec[i] << " ";
    if(status_spec[i]){
        cout << "urgent\n";
    }else{
        cout << "regular\n";
    }
}
cout << "\n";
}

// PRINT PATIENTS
void print_patients(){


 cout << "************************\n";
 for(int spec = 0 ; spec <MAX_SPECIALIZATION ;spec++){
    print_patient(spec,names[spec],status[spec]);
 }
}
void hospital_system(){
 while(true){
    int choice = menu();

    if(choice==1)
        add_patient();
    else if(choice ==2)
        print_patients();
    else if(choice ==3)
        get_next_patient();
    else
        break;
 }
}

int main()
{
    hospital_system();
    cout << "Hello world!" << endl;
    return 0;
}

