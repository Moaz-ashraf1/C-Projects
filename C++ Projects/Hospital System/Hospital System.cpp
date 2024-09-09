#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
int queue_length[MAX_SPECIALIZATION+1] = {0};

struct patients {
    string names[MAX_QUEUE];
    int status[MAX_QUEUE];
};

// This struct manages patients for each specialization in the hospital queue.
struct my_queue {
    patients patients_arr[MAX_SPECIALIZATION + 1];

    // Add a patient at the end of the queue
    void add_end(int spec, string name, int status) {
        int added = queue_length[spec];
        patients_arr[spec].names[added] = name;
        patients_arr[spec].status[added] = status;
        queue_length[spec]++;
    }

    // Add a patient at the front of the queue
    void added_front(int spec, string name, int status) {
        int added = queue_length[spec];
        for (int i = added - 1; i >= 0; i--) {
            patients_arr[spec].names[i + 1] = patients_arr[spec].names[i];
            patients_arr[spec].status[i + 1] = patients_arr[spec].status[i];
        }
        patients_arr[spec].names[0] = name;
        patients_arr[spec].status[0] = status;
        queue_length[spec]++;
    }

    // Remove the first patient from the queue
    void remove_front(int spec) {
        int length = queue_length[spec];
        if (length == 0) {
            cout << "NO Patient at the moment. Have rest, Dr" << endl;
            return;
        }
        string patient = patients_arr[spec].names[0];

        for (int i = 0; i < length - 1; i++) {
            patients_arr[spec].names[i] = patients_arr[spec].names[i + 1];
            patients_arr[spec].status[i] = patients_arr[spec].status[i + 1];
        }
        cout << patient << " please go with the Dr\n";
        queue_length[spec]--;
    }

    // Print all patients in the specified specialization
    void print(int spec) {
        int added = queue_length[spec];
        if (added == 0) {
            cout << "There are 0 patients in specialization " << spec << endl;
            return;
        }

        cout << "There are " << added << " patients in specialization " << spec << endl;
        for (int i = 0; i < added; i++) {
            cout << "Patient: " << patients_arr[spec].names[i]
                 << " , Status: " << (patients_arr[spec].status[i] == 1 ? "Urgent" : "Regular") << endl;
        }
    }
};

my_queue hospital_queue;

// Display the menu and get the user's choice
int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;
        if (!(1 <= choice && choice <= 4)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;  // loop keep working
        }
    }
    return choice;
}

// Add a patient to the queue based on input
void add_patient() {
    int spec;
    string name;
    int status;

    cout << "Enter specialization, name, status: ";
    cin >> spec >> name >> status;

    if (spec < 1 || spec > 20) {
        cout << "Specialization must be in range [1-20]." << endl;
        return;
    }

    int length = queue_length[spec];
    if (length == MAX_QUEUE) {
        cout << "Sorry we can't add more patients for this specialization" << endl;
        return;
    }

    if (status == 0) {
        hospital_queue.add_end(spec, name, status);
    } else if (status == 1) {
        hospital_queue.added_front(spec, name, status);
    }
}

// Get the next patient from the queue based on specialization
void get_next_patient() {
    cout << "Enter specialization: ";
    int specialization;
    cin >> specialization;

    if (specialization < 1 || specialization > 20) {
        cout << "Specialization must be in range [1-20]." << endl;
        return;
    }

    hospital_queue.remove_front(specialization);
}

// Print all patients for a specific specialization
void print_patients() {
    int specialization;
    cout << "Enter specialization: ";
    cin >> specialization;
    if (specialization < 1 || specialization > 20) {
        cout << "Specialization must be in range [1-20]." << endl;
        return;
    } else {
        hospital_queue.print(specialization);
    }
}

// Main hospital system function that drives the menu
void hospital_system() {
    while (true) {
        int choice = menu();

        if (choice == 1)
            add_patient();
        else if (choice == 2)
            print_patients();
        else if (choice == 3)
            get_next_patient();
        else
            break;
    }
}

int main() {
    hospital_system();
    return 0;
}
