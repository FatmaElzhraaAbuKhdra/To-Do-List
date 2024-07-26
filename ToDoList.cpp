#include <iostream>
#include <list>
#include <string>
#include <algorithm> 

using namespace std;

int main() {
    int choice, TaskNumber;
    string NewTask;
    list<string> SaveTask;

    while (true) {
        cout << "To-do list management software\n";
        cout << "Choose a number:\n";
        cout << "1. Add a new task\n";
        cout << "2. View tasks\n";
        cout << "3. Remove a task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
            case 1:
                cout << "Enter a new task: ";
                getline(cin, NewTask);
                SaveTask.push_back(NewTask);
                break;
            case 2:
                cout << "Your tasks:" << endl;
                {
                    int taskNumber = 1;
                    for (const auto &task : SaveTask) {
                        cout << taskNumber++ << ". " << task << endl;
                    }
                }
                break;
            case 3:
                cout << "These are your tasks:" << endl;
                {
                    int taskNumber = 1;
                    for (const auto &task : SaveTask) {
                        cout << taskNumber++ << ". " << task << endl;
                    }
                }

                cout << "Select the task number you want to remove: ";
                cin >> TaskNumber;

                if (TaskNumber > 0 && TaskNumber <= SaveTask.size()) {
                    auto it = SaveTask.begin();
                    advance(it, TaskNumber - 1); 
                    SaveTask.erase(it);

                    cout << "To-Do List after removing the task:" << endl;
                    {
                        int taskNumber = 1;
                        for (const auto &task : SaveTask) {
                            cout << taskNumber++ << ". " << task << endl;
                        }
                    }
                } else {
                    cout << "Invalid task number." << endl;
                }

                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                return 0;
                break;
        }
    }
}
