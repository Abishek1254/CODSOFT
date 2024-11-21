#include <iostream>
using namespace std;

class node {
public:
    string data;
    bool isCompleted;
    node* next;

    // Constructor
    node(string s) {
        this->data = s;
        this->next = NULL;
        this->isCompleted = false;
    }
};

// Insert a new task at the end of the list
void insertAtTail(node*& head, node*& tail, string d) {
    node* temp = new node(d);
    if (tail == NULL) {
        head = tail = temp;
    } 
    else {
        tail->next = temp;
        tail = temp;
    }
}

// Function to add a new task
void addTask (node*& head, node*& tail) {
    cout << "Enter your task: ";
    string s;
    cin.ignore();  // Clear the input buffer for multi-word input
    getline(cin, s);
    insertAtTail(head, tail, s);
}

// Function to delete a task at a given position
void deleteTask (node*& head, node*& tail) {
    int position;
    cout << "Enter the task number to delete: ";
    cin >> position;

    if (head == NULL) {
        cout << "Task list is empty, nothing to delete." << endl;
        return;
    }

    if (position == 1) {  // Deleting the head node
        node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;  // If list becomes empty
        delete temp;
        cout << "Task deleted." << endl;
        return;
    }

    node* current = head;
    node* prev = NULL;
    int count = 1;

    // Traverse to find the position
    while (count < position && current != NULL) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Task not found at that position." << endl;
    } 
    else {
        prev->next = current->next;
        if (current == tail) tail = prev;  // Update tail if deleting last node
        delete current;
        cout << "Task deleted." << endl;
    }
}

// Function to mark a task as completed
void markComplete(node* head) {
    int pos;
    cout << "Enter the task number to mark as complete: ";
    cin >> pos;

    node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        temp->isCompleted = true;
        cout << "Task marked as completed." << endl;
    } 
    else {
        cout << "Task not found at that position." << endl;
    }
}

// Function to display all tasks with their completion status-completed/ not completed
void displayTasks (node* head) {
    node* temp = head;
    int count = 1;

    if (head == NULL) {
        cout << "No tasks available." << endl;
        return;
    }
    cout<<"<------------------------------------------------------------------------------------------------>"<<endl;
    cout << "Tasks List:" << endl;
    while (temp != NULL) {
        cout << "Task " << count << ": " << temp->data << " --> ";
        cout << (temp->isCompleted ? "Completed" : "Not completed") << endl;
        temp = temp->next;
        count++;
    }
}

int main() {

    node* head = NULL;
    node* tail = NULL;
    char choice = 'y';
    cout<<"<------------------------------------------------------------------------------------------------------->"<<endl;

    while (choice == 'y' ) {
        cout << "Welcome to the TO-DO-LIST App." << endl;
        cout << "You can perform the following operations:" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. Delete a task" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Display all tasks" << endl;
        cout << "5. Terminate the current list and exit\n" << endl;

        cout << "Enter the operation number: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                addTask(head, tail);
                break;
            case 2:
                deleteTask(head, tail);
                break;
            case 3:
                markComplete(head);
                break;
            case 4:
                displayTasks(head);
                break;
            case 5:
                cout << "Terminating the list..." << endl;
                while (head != NULL) {  // Free all nodes to avoid memory leaks
                    node* temp = head;
                    head = head->next;
                    delete temp;
                }
                head = tail = NULL;
                cout << "List terminated." << endl;
                choice = 'n';  // Exit the program
                break;

               default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }

        if (choice != 'n' && choice != 'N') {
            cout << "Do you want to continue ? Enter y for yes and n for no: ";
            cin >> choice;
        }
    }

    cout << "Thanks for using the TO-DO-LIST App. GOODBYE!" << endl;
    return 0;
}
