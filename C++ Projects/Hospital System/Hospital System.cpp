#include <iostream>
using namespace std;

// Menu function to display options
void menu() {
    cout << "Enter your choice:\n";
    cout << "1) Add new patient\n";
    cout << "2) Print all patients\n";
    cout << "3) Get next patient\n";
    cout << "4) Exit\n";
}

int getSizeOfMatrix (int specialization ,string patientName[16][6] ){
    int c =0;
    for(int i =0 ; i< 5 ;i++){
        if(!patientName[specialization][i].empty()){
            c++;
        }

    }
    return c;
}
bool full_specialization_or_not(int specialization ,string patientName[16][6] ){

        for (int i = 0; i < 5; ++i) {
        if (patientName[specialization][i].empty()) {
            return false;
        }
    }
    return true;
};
bool empty_specialization(int specialization ,string patientName[16][6]){
          for (int i = 0; i < 5; ++i) {
        if (!patientName[specialization][i].empty()) {
            return false;
        }
    }
    return true;
}
void push_in_the_front(int specialization,string name,int status, string patientsName [16][6], int patientStatus  [16][6]){

   if(full_specialization_or_not( specialization , patientsName )){
        cout << "Sorry we can't add more patients for this specialization\n";
        cout << endl;
      }else{

            for(int i =4 - 1 ; i>= 0 ; i-- ){
                patientsName[specialization][i+1] = patientsName[specialization][i];
                patientStatus[specialization][i+1] = patientStatus[specialization][i];

            }

            patientsName[specialization][0] = name;
            patientStatus[specialization][0] =status;


      }

};
void  push_in_the_end(int specialization,string name,int status, string patientsName [16][6], int patientStatus [16][6]){

   if(full_specialization_or_not( specialization , patientsName )){
        cout << "Sorry we can't add more patients for this specialization\n";
      }else{

            for(int i =0 ; i< 5 ; i++ ){
                if(patientsName[specialization][i].empty()){
                  patientsName[specialization][i] = name;
                  patientStatus[specialization][i] =status;
                  break;
                }

            }




      }
};
string pop (int specialization,string patientsName [16][6]){
    int sizeOfMatrix = getSizeOfMatrix(specialization,patientsName);
    string patient = "";

    if(empty_specialization(specialization,patientsName)){
        cout << "NO patients at the moment. Have rest, Dr\n";
    }else{

        patient = patientsName[specialization][0];

       for(int i =1 ; i< sizeOfMatrix ;i++){
          patientsName[specialization][i-1] = patientsName[specialization][i];

       }
      patientsName[specialization][sizeOfMatrix-1] = "";
    }


    return patient;
}
void AddNewPatient(string patientsName [16][6] ,int patientStatus [16][6] ){
  cout << "Enter specialization (1-15), name, status (1 for urgent, 0 for regular): ";
   int specialization ,status;

   string name;
   cin >> specialization >> name >> status ;
   if (specialization < 1 || specialization >15) {
        cout << "Invalid specialization number.\n";
        return;
    }
     if (status != 0 && status != 1) {
        cout << "Invalid status. Please enter 0 for regular or 1 for urgent.\n";
        return;
    }

   if(status == 1){
    push_in_the_front(specialization,name,status, patientsName , patientStatus );
   }else if(status == 0){
     push_in_the_end(specialization,name,status, patientsName , patientStatus );
   }
};
void PrintAllPatientsInSpe(string patientsName [16][6] , int patientStatus [16][6] ){
    int specialize;
    cout << "Enter the specialization number to print patients in it (1-15): ";
    cin >> specialize;

     if (specialize < 1 || specialize >15) {
        cout << "Invalid specialization number.\n";
        return;
    }
     for (int i = 0; i < 5; i++) {
        if(!patientsName[specialize][i].empty()){
             string status = "";
        if (patientStatus[specialize][i] == 1) {
            status = "urgent";
        } else if (patientStatus[specialize][i] == 0) {
            status = "regular";
        }

        cout << "Patient : " << patientsName[specialize][i]
             << " Status : " << status << endl;
    }

        }

cout << endl;

};
void GetNextPatient(string patientsName [16][6] ){

int specialize;
cout << "Enter specialization : ";
cin >> specialize;

string patient = pop(specialize,patientsName);
if( patient != ""){
    cout << patient << " please go with the Dr\n" ;
}

}
void Exit(){
      cout << "Thank you for using the hospital management system." << endl;
      cout << "We appreciate your hard work in managing patient records." << endl;
       cout << "Goodbye, and have a great day!" << endl;

}

int main()
{
 string patientsName [16][6]={} ;
 int patientStatus [16][6]={};
 while(true){
    menu();
    int choice ; cin >> choice;

    if(choice == 1)
    AddNewPatient(patientsName, patientStatus );
   else if(choice ==2)
     PrintAllPatientsInSpe(patientsName ,patientStatus);
   else if(choice ==3)
     GetNextPatient(patientsName);
    else if (choice==4){
        Exit();
        break;
    }

}



return 0;


}
